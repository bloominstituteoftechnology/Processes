# FAQ

<p><details><summary><b>What is a syscall/system call?</b></summary><p>

From a C programming perspective, you can think of a syscall as a function that
you call to get the OS to do something for you. It looks just like a regular
function, but the behavior is different.

This is not a syscall:

```c
double x = sqrt(2);
```

You don't need any special access to hardware to compute a square root, so that
just happens in _user space_ without involving the OS.

This _is_ a syscall:

```c
int fd = open("file.txt", O_CREAT|O_WRONLY);
```

Opening a file is something a regular user can't do (since they don't have
direct access to the hard disk). The `open()` syscall asks the OS to open the
file on the user's behalf. And the OS can agree or disagree to do that depending
on the user's authority level.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>What's a privileged vs non-privileged operation?</b></summary><p>

Privileged operations need additional access to hardware or data that the user
is not normally allowed to access.

There are privileged instructions that a CPU won't execute unless in the proper
"supervisor" mode (sometimes called _ring-0_, or _system mode_ or _privileged
mode_).

An example might be accessing a file on a hard disk. A user cannot do this by
talking directly to the hardware. The user must request the OS do it on their
behalf using a syscall.

A non-privileged operation might be something like computing a square root. This
doesn't require any additional access to hardware, and the user program can do
this without asking the OS for anything.

Going between these modes is called a _context switch_. The state of the running
program is saved (so it can be restarted later), and then the OS kernel decides
what to do next. Sometimes it's executing a syscall on a process's behalf. Other
times it's scheduling an entirely different process to run.

```
        User mode           |          Privileged mode
        ---------           |          ---------------
compute square root         |
estimate pi                 |
open a file         <-------+------->    open syscall
compute pi/2                |
write to file       <-------+------->    write syscall
add 3 + 7                   |
```

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>Does compiled code make system calls under the hood?</b></summary><p>

Yes.

Here's an example of a function that runs partly in user space, but then makes a
syscall to complete the work:

```c
printf("%d\n", x);
```

The `printf()` library function does all the hard work of converting `x` into a
string that can be printed, but actually outputting to the screen is a
privileged operation.

So under the hood, `printf()` calls the `write()` syscall to actually perform
the final output.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>How does I/O with the keyboard and other peripherals work?</b></summary><p>

From a programming standpoint, virtually all I/O in a Unix-like system takes
place through the `read()` and `write()` syscalls. These send and receive arrays
of bytes to and from open files.

One of the files that's open by default is called _standard input_. This is
normally attached to the keyboard.

```c
char buf[10];

read(0, buf, 10); // Read 10 bytes from stdin, file descriptor 0
```

Another is _standard output_, normally attached to the screen.

```c
write(1, "Hello, world!\n", 14); // print to stdout, file descriptor 1
```

In Unix, the `/dev` directory contains a number of special _device files_ that
correspond to physical devices on the system. The usual method of accessing them
involves `open()`ing the file, then interacting with it with `read()`,
`write()`, `ioctl()`, and `fcntl()`. Of course, your user needs permission to
open the device file to make this work.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>How does the scheduler work?</b></summary><p>

The _scheduler_ is a component inside the OS that decides which process needs to
run next. Your CPU might only have 4 or 8 cores, so it can actually only do that
many things at once.

But a Unix system might have 200 processes running at the same time, and those
200 processes have to be juggled across the few cores a CPU has.

Imagine a room with 200 reporters and they all want to ask the President a
question. But only one can ask a question at a time. The President calls on one
of the reporters to ask a question, answers, then calls on the next one. How
does the President decide which reporter to call on next? That is the job of the
scheduler.

The scheduler looks at all 200 processes and decides which one to run next.

Now, _how_ it decides is up to whatever scheduler algorithm is implemented.
Imagine you were the President selecting which reporter to call on next. There
are a number of algorithms you could use. (Choose randomly, go in order, choose
the ones you personally like the most, etc.)

But a good scheduling algorithm should give CPU time to processes that the user
expects to see a snappy response from, and less time to "background" processes
that can be delayed a bit.

The [multilevel feedback
queue](https://en.wikipedia.org/wiki/Multilevel_feedback_queue) is a popular
scheduling algorithm.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>Where does the OS keep the process list? How does it relate to the stack and heap?</b></summary><p>

From an individual process's perspective on a modern OS, the process thinks it
has all the memory on the entire system to itself. It's an illusion, though,
brought about by the magic of [virtual
memory](https://en.wikipedia.org/wiki/Virtual_memory). This is where the
individual processes's stacks and heaps are kept.

So if the process thinks it has all the RAM, where are the process list and
other OS internals kept?

The OS kernel has its own bit of dedicated memory allocated to it, and all the
internal data (process list, etc.) are kept there.

Regular user processes have zero access to this data, except via syscalls or
some other mechanism that the OS explicitly allows.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>If processes are isolated from one another, what's the point of using <tt>pipe()</tt>?</b></summary><p>

If you set up the `pipe()` _before_ the `fork()`, then both parent and child
have access to the pipe's file descriptors and they remain connected.

They can then use the pipe to send messages back and forth.

(Pipes are part of a collection of Unix calls known collectively as
_interprocess communication_.)

If you mistakenly call `pipe()` _after_ `fork()`, then the parent and child will
have their on separate, disconnected pipes, and there'd be no point in it.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>When you <tt>fork()</tt>, is the parent's PID always greater than zero?</b></summary><p>

Yes.

But technically, _all_ PIDs are greater than zero.

`fork()` returns `0` to the child process, but the child process's PID is
some other positive number.

The `0` returned by `fork()` is a _sentinel value_ that allows the program to
determine which process is the parent and which is the child.

Any process can call `getpid()` to find out its PID. It can also call
`getppid()` to get the parent process's PID.

(There is no `getchildpid()` call, though, since a parent might have multiple
child processes. The only way for a parent to know the PID of its children is to
remember them from the return value from `fork()`.)

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>Should I use <tt>wait()</tt> or <tt>waitpid()</tt>?</b></summary><p>

`waitpid()` is just like wait, except it gives you more options. With
`waitpid()`, you can wait for specific processes to exit, or for processes in a
process group. You can also specify if you want the `waitpid()` call to block or
not if there are no zombie children waiting to be reaped.

Example where the calls to `wait()` are identical to `waitpid()`:

```c
wait(NULL);
waitpid(-1, NULL, 0);
```

```c
int status;

wait(&status); // Get exit status from child zombie
waitpid(-1, &status, 0);
```

And here's an example of using `waitpid()` to wait for all children that might
have died, but then continuing to run if there are no zombies remaining.

```c
printf("Reaping zombies...\n");

// WNOHANG causes waitpid() to return 0 if
// there are no zombies remaining:

while (waitpid(-1, NULL, WNOHANG) > 0);

printf("Done reaping zombies.n");
```

Normally `wait()` and `waitpid()` will _block_ (sleep) until they have something
to do. But if you specify `WNOHANG` to `waitpid()`, it will return `0`
immediately if there are no child zombies to reap.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>Does a return value of <tt>-1</tt> usually indicate an error?</b></summary><p>

It's common in general, and really common with syscalls.

The usual pattern to:

1. Make a syscall.
2. See if the return value is `-1`.
3. Use `perror()` to print an error, or check `errno` to decide what to do.

Example where we try to open a non-existent file for reading:

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("nosuchfile.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }
}
```

Output from the above:

```shell
$ ./foo
Error opening file: No such file or directory
```

You can also check the exact value of the `errno` global variable (from
`<errno.h>`) to see what specific error occurred and act on it.

In this example, we try to write to (and maybe create) the `/etc/passwd` file.
Normal users don't have permission to do this. (**NOTE**: don't run this as
`root`!)

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
    int fd = open("/etc/passwd", O_CREAT|O_WRONLY);

    if (fd == -1) {
        switch errno {
            case EACCES:
                printf("You don't have permission to open this file.\n");
                break;
            case ENOENT:
                printf("No such file.\n");
                break;
            case ENOSPC:
                printf("Disk full.\n");
                break;
            default:
                perror("Error opening file");
                break;
        }
        exit(1);
    }
}
```

When a normal user runs this, they see:

```shell
$ ./foo
You don't have permission to open this file.
```

The values you can check for with `errno` are listed in the man page for the
syscall in question.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>Is the `fork()` syscall where the word "fork" on GitHub came from?</b></summary><p>

Probably not.

GitHub needed a name for when you branched off someone else's repo.
Unfortunately for them, _branch_ already means something else to git. Seems
likely they just used fork as a similar word.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>If old operating systems like MS-DOS didn't offer a privileged mode or memory protection, how did they offer features dependent on those to their users?</b></summary><p>

In a nutshell, they didn't.

You could write a program and run it in MS-DOS that could directly access
hardware, modify or overwrite the OS, or do all manner of bad things.

But those systems tended to be single-user (a family would just share with no
privacy) and it wasn't that big of a deal. Crash the system? You'd just reboot.

Rebooting happened a lot.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>What are some use cases for pipes?</b></summary><p>

When you `fork()` a new process, it gets a copy of all the data. None of it is
shared. But there might be times you want to communicate between a child and
parent process.

If you set up a pipe ahead of the `fork()`, copies of that pipe's descriptors
get made for the child. But here's the magic: those descriptors still refer to
the underlying shared pipe as they do in the parent. They're still connected.

This means you can pass data across the pipe from one to the other.

Another use case is used by the shell when you run a command like this:

```shell
ls -l | wc -l
```

That pipes the output from the `ls` program to the input of `wc` (a word
counting program). The `pipe()` syscall is used to set up that communication
path between the two completely separate processes. (It also makes use of the
syscall `dup2()` to actually hook up the input and output to the pipe.)

```c
/**
 * Pipe example
 *
 * Runs the command: ls -la / | wc
 *
 * Try running the above command on the command line to see if the
 * output matches.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    int fd[2];

    // Make the pipe for communication
    pipe(fd);

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process

        // Hook up standard input to the "read" end of the pipe
        dup2(fd[0], 0);

        // Close the "write" end of the pipe for the child.
        // Parent still has it open; child doesn't need it.
        close(fd[1]);

        // Run "wc"
        execlp("wc", "wc", NULL);

        // We only get here if exec() fails
        perror("exec wc");
        exit(1);
    } else {
        // Parent process

        // Hook up standard output to the "write" end of the pipe
        dup2(fd[1], 1);

        // Close the "read" end of the pipe for the parent.
        // Child still has it open; parent doesn't need it.
        close(fd[0]);

        // Run "ls -la /"
        execlp("ls", "ls", "-la", "/", NULL);

        // We only get here if exec() fails
        perror("exec ls");
        exit(1);
    }

    return 0;
}
```
</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>Isn't it expensive to copy all the data on a <tt>fork()</tt>?</b></summary><p>

Seems like it would cost a lot to give the child a complete copy of all the
process data.

But modern operating systems implement something called [_copy on
write_](https://en.wikipedia.org/wiki/Copy-on-write) so that the data isn't
copied until the child process wants to modify it. _Then_ a copy is made.

If you're 100% certain that you're just going to call `exec()` right after
`fork()`, then there's no reason to copy anything at all. There's a historic
syscall called `vfork()` that you could use if you were _only_ going call
`exec()` after the fork.  On modern systems, `vfork()` might be marginally
faster for that use case, or it might work exactly the same way as `fork()`.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>Where is the process control block stored?</b></summary><p>

That's somewhere deep in kernel memory. It's not something you can directly
access as a user. You have to use syscalls to ask the OS for information about
the process.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>Is there a way to control how the OS schedules processes, to give them higher priority?</b></summary><p>

As a normal user, you can request the OS give your program _lower_ priority in
the scheduler with the `nice()` syscall.

```c
nice(10); // Be pretty nice to other processes on the system (lower priority)
```

```c
nice(20); // Be as nice as possible (lowest priority)
```

The default priority level is `0`.

If you're superuser (running as `root`), you can assign _negative nice_ levels
(AKA _mean_ levels).

```c
nice(-20); // Be as mean as possible to other processes (highest priority)
```

Particular systems might have other methods of manipulating scheduling, but
they're all going to involve making a request to the OS.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>Is the kernel "close to the metal"?</b></summary><p>

Definitely. It's the arbiter of all access to all the hardware on the system.

Not only that, but the boot-up sequence of an OS is almost always written in
assembly language, as close to the metal as programmers typically go. (Although
as much of the OS as possible is written in a higher-level language because it's
so much easier.)

The expression _close to the metal_ is also used to refer to programming
languages. An example list with closer to the metal at the top would be,
roughly:

* Machine code
* Assembly language
* C
* C++, Rust
* Go, Swift
* JavaScript, Python, Perl
* TypeScript

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>How does a process dynamically resize how much memory is has at its disposal?</b></summary><p>

It asks the OS for more.

On Unix-like systems, this is done with the `brk()` or `sbrk()` syscall.

Normally, C developers don't call this. They call `malloc()` to get more memory,
and `malloc()` calls `brk()` if it needs to get more for this process from the
OS.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>How does the OS assign a particular memory space to a particular process?</b></summary><p>

This is out of scope for the class, but is all about the crazy world of [virtual
memory](https://en.wikipedia.org/wiki/Virtual_memory). Read up on that if you
want all the gritty details.

</p></details></p>

<!--
TODO:
9)How do distributed systems work? 
-->

<!-- ===================================================================== -->

<!--
Template:

<p><details><summary><b></b></summary><p>
</p></details></p>

-->

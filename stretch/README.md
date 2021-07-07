# Bankers and Concurrency

This is an assignment to experiment with concurrency and some of the
issues that arise with it.

## Why Do I Care?

In all kinds of development, web included, multiple processes often have
access to the same resources. Obscure and hard-to-find (read
"expensive") bugs can occur when multiple processes attempt to access
the same resources at the same time.

It is always a good idea to think to yourself, what happens when two of
these processes run at once? Anything bad?

## Concurrency

What is
[concurrency](https://en.wikipedia.org/wiki/Concurrency_(computer_science))?
In a nutshell, we want to run a number of processes at the same time
with access to _shared resources_. And we want these processes not to
step on each-other's toes.

Imagine that after the Mount Everest expedition, there was an expedition
journal that needed to be filled out with the experiences of all
expedition members. Each member is given a pen, the journal is opened,
and they all begin writing on the same page at the same time.

Everyone scribbles on top of everyone else. It's not working.

So the expedition gives it a think, and decides to only allow one person
to write in the journal at a time. Problem solved. Publishers are
definitely interested. Someone smells movie contract.

Of course, all the other members of the expedition are sitting around
doing nothing while they wait their turn. Maybe there is room for
improvement... This is the kind of problem computer scientists like to
solve.

## Money, Money, Money

We're going to write code that simulates a number of processes trying to
withdraw money from a bank account at the same time.

The process for withdrawing money is simple:

1. Open the file containing the balance.
2. Read the current balance.
3. Try to withdraw some amount of cash.
   * If the amount to withdraw is less than (or equal to) the current
     balance:
       * Subtract that amount from the current balance.
	   * Write the new balance to the file.
   * If the amount to withdraw is greater than the current balance:
       * Print an error and do not modify the balance.
4. Close the file containing the balance.

This works fine for any one process trying to withdraw money in isolation.


## Assignment

Implement code to safely withdraw money from a bank account. (A
simulated bank account, that is. Don't get your hopes up.)

1. **Short answer**: How can things go wrong if two processes attempt the
   above plan at the same time? Is there more than one way things can go
   wrong?
   * There are definitely more than one way things can go wrong. Changes can be overwritten, one process can try to update the data while another process simultaneously tries to read the data while its being updated, etc. Since the process scheduling will be determined ultimately by the OS, the end result cannot be predicted. You might get different results every time.

2. Study and understand the skeleton code in the `src/` directory.

   **Short answer**: what do each of the arguments to `open()` mean?
   * The code referenced is: `open(filename, O_CREAT|O_RDWR, 0644)`.
   * `filename` is the file which will be opened.
   * `O_CREAT|O_RDWR` are the options.
     * `O_CREAT` means to create the file if it does not exist.
     * `O_RDWR` means to allow the user to read/write to it.
   * `0644` determines the permissions of the file if it is created.

3. Take the skeleton code in the `src/` directory and implement the
   pieces marked. Run it.
   
   **Short answer**: What happens? Do things go as planned and look
   sensible? What do you speculate is happening?
   * For me, every time it withdrew money, the balance was always the starting $10K. It did not take into account the previous withdrawals. I'm guessing the other processes had not had time to write their new balances to the file before others read it.

4. Add calls to [`flock()`](https://linux.die.net/man/2/flock) to
   capture and release an exclusive lock on the file before reading and
   changing the data.

   The results of the run should now make sense.
   
5. **Short answer**: Why is it working? How has adding locks fixed the
   problems you noted in question 1? How is overall performance of the
   application affected?
   * Flock fixed the problem by giving exclusive access to a file to one process at a time, and only allowing other processes access to it once it has been released. The performance would take a hit because instead of the processes running more or less at the same time, now they find themselves on a queue waiting for the other processes to finish their handling of the file.


## Stretch Goals

* Make some processes deposit money while others withdraw money.

* Have some processes simply check the balance without changing it. Do
  you need to lock? If so, do you need to use `LOCK_EX`? If not, what
  are the advantages of your approach?
  * You would need to lock the file in order to read it. Luckily a reader lock exists in the form of `LOCK_SH`. If the file has been locked with LOCK_SH in one process, it will allow another to use LOCK_EX on it at the same time. Furthermore, LOCK_EX will block all other access to the file until all reader locks on the file have been released. One advantage to this would be to allow better performance by letting another process use the file while a previous process has a reader lock on it.

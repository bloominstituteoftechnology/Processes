# Processes 

1. Memory: A process is given or allocated only a certain portion of ram. Other processes will be given its own portion of ram. Processes in general do not access other process allocated ram. Processes are essentially isolated from one another in terms of allocating memory from ram. These describe civilian processes.

2. Operating System Processes: Operating system is what polices, using elevated permissions, civilian processes by making sure they are not accessing other process's allocated ram. However, in order to do this, operating system itself must and does access the ram of other processes.

3. Process States: processes have states which describes the action the process is currently performing. Process state can be different depending on Os but some basic ones include 'ready', 'waiting', 'running' and 'terminated.' 

4. Child processes: Processes will need to have child processes as it is often the child processes that perform the actual action while the parent processes may provide the ui. e.g the terminal as the parent process and the commands like 'ls' as the child process. 

5. System Call: Creating another process from an existing process can only be done by a privileged process. Cilivian processes cannot create new processes on their own. The kernel/operating system intervenes when a civilian process wants to create a new process. A system call is a api of different functions and procedures, that is exposed to civilian processes that allows cilivian processes to ask the operating system to create the new processes for the cilivian processes by allocating the memory needed etc. Civlian process makes the system call and allows civilian processes have access to priveleged operations and operating system managing them. Examples of system calls include fork(), exec(), etc

6. fork(): fork is used by the parent process to created a child process. It fetches the processes identification number (pid) and then fork is actually called. If successful, a new process is spawned. Parents gets pid of the child that has spawned. e.g int rc = fork(); 'rc' is the pid of child if rc <0, this means fork has failed or it will equal 0 to indicated success. Child cannot access Parent pid but parent can access pid of child. Child just copies the program counter of the parent and keeps moving without re running all the code the parent has already ran before the current program counter. If rc is 0, then you know you are ruynning the child processes.

7. wait(): Wait system call have multiple forms. There are multiple wait functions including 'wait' waitpid' and 'waitid'. Wait is used for to wait for state changes in the child. The parent will run only after the child processes finished first. You cannot make the child wait because the child does not know the parent pid. It is aspect of scheduling processes which determines when processes begins and both are priveleged process so the civilian process will not be able to undermine the scheduler.
int wc = wait(pid, NULL, 0)

8. exec(): Another family of functions rather than one paricular funciton. Fork only gives half of what we need because it only runs based on the parent processes. Howver, we often need child process to do something else or executing something else. Exec transforms the processes it was called in into its own program. After exec, the child is no longer a clone of its parent but executes its own program. The name of the new program is passed into the exec function. The ID itself remains the same. You can also pass in arguments which specifies the actions performed by new process. There are many variations of exec and the differences comes from they are called and how the arguments are called such as passing in arrays or strings.

9. pipe(): Processes by default are isolated with own blocks of ram . However, pipe allows for a uni-directional connection betweeen two processes that would otherwise be isolated from each other. Bi- directional communication would require two uni directional pipes. You need variables to hold the data coming in through the pipes such as an array or string. Bi directional will require at least two such as writing data to another process and then reading data coming from that process. The write() function writes to the pipe and read() read off the pipe to get that data. read( p[0], inbuf, MSGSIZE); inbuf btw is what holds the incoming data.  
 
How does system know when to swap to another process and which processes to prioritizes. This is where Scheduling comes in. A single core can only execute a single process in a single period of time even if its a extremely small amount of time. However, if the processor is able to execute fast enough switching one task to another, you can at last achieve the illusion of multi-tasking even on a single core.

#Scheduling

1. Thread: A thread is a bunch of procceses that share the same memory address or spot in memory.

2. Scheduling: Having shortest processes run first sounds like a good idea at first until you realize that the cpu has no way of determining which process is shorter than another. Even if it does, long processes still need to run and so you can risk the problem of only short processes running while neglecting long processes. 

3. Round Robin scheduling: This would give every processes time to run but would not be able to account for processes that need to take priority over other processes. Mouse movement and clicks are examples of processes that needs to happen right then and there so it can give the illusion of being very responsive. In worse case scenario here, the processes that requires immediate execution might be on the end of list which means the much needed instant response will not happen in Round Robin scheduling.

4. multi level feedback queue: Datastructure which formed the foundation of how modern computers handles processes. THere are a bunch of queue tagged with different priority levels. Whenever a new process comes in, long or short, is put on highest priority queue level. As you move down the queue priority, the longer the time on the processor. The highest priority level will give process the shortest amount of time e.g 5 nanoseconds then push down to next level which will be given lets say 10 nanoseconds but will run only after the highest priority queue is empty. Really long running processes will go down even to the lowest priority but given the most amount of time to run. 

Processes that are on hold because its waiting, it doesn't get moved down the queue list. It only gets moved down the queue list if it uses up the alloted time its given and the process has still yet to be completed. Only processes that are running will get spot in memory and any processes that are done will have its space in memory cleared for another processes. Otherwise, memory leaks could occur. 

5. Blocking queue: A queue with even higher priority than queue one which handles the blocking processes with input output in them. When blocking operation occurs, the scheduler, the queue and the processes need to communicate with each other so that the blocking process can be recieved by the scheduler by the interrupt so it can be moved to the blocking queue and then communication for it to be moved back to origin queue when blocking process completes. Scheduler will always recieve the interrupts and handle the function to move blocking process to blocking queue and vice versa. 

6. Running queue: Deals with nonblocking queues with processes that do not require blocking queues. 

7. Processes are the most independent element when stimulating a multilevel feedback queue. 
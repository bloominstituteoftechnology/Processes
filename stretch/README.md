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

   If multiple processes attempt to withdraw money at the same time you could end up withdrawing more money than you have in your account. Even if you don't overdraft, the balance will not accurately reflect all withdraws processed allowing you to withdraw more than you should have access to. If an additional process reads the balance before it is fully updated by a prior process, both withdrawals could be processed but only one will be recorded; the final process will overwrite the balance recorded from the first process.

2. Study and understand the skeleton code in the `src/` directory.

   **Short answer**: what do each of the arguments to `open()` mean?

    ```c
    open(filename, O_CREAT|O_RDWR, 0644);
    ```

    - **filename** is the pathname for the file you want to open
    - **O_CREAT|O_RDWR** are flags dictating open's access mode and behaviour
      - O_CREAT tells open that it should create the file if it does not already exist
      - O_RDWR sets the access mode to read and write
    - **0644** represents the file permission -rw-r--r-- if open has to create a new file. The permission breakdown is read and write privileges for the user and read privileges for the group and other.


3. Take the skeleton code in the `src/` directory and implement the
   pieces marked. Run it.
   
   **Short answer**: What happens? Do things go as planned and look
   sensible? What do you speculate is happening?

   As is the program is not withdrawing money correctly; the balance does not accurately reflect all of the withdraws that have been made. As detailed in the first short answer, processes are reading the balance sheet before some prior processes have had a chance to write the updated balance. Those later processes end up reading in an outdated balance. Example:

   - 1st process: Withdrew $924, new balance $9076
   - 2nd process: Withdrew $731, new balance $8345
   - 3rd process: Withdrew $538, new balance $7807
   - 4th process: Withdrew $345, new balance $8000

   The 4th process reads the balance before the 3rd process has had a chance to finish updating. While the actual balance when process 3 finishes is $7807, process 4 read in $8345 effectively giving up $538 without recording it.

4. Add calls to [`flock()`](https://linux.die.net/man/2/flock) to
   capture and release an exclusive lock on the file before reading and
   changing the data.

   The results of the run should now make sense.
   
5. **Short answer**: Why is it working? How has adding locks fixed the
   problems you noted in question 1? How is overall performance of the
   application affected?

   By locking a file before it is read by a process and only releasing it after the balance has been updated, no other process can read the file before the balance update. While this solves the problem of performing withdraws based on outdated balances, it will make the application run longer as processes can no longer run parallel. Each process must wait until the prior process has released the file before continuing.


## Stretch Goals

* Make some processes deposit money while others withdraw money.

* Have some processes simply check the balance without changing it. Do
  you need to lock? If so, do you need to use `LOCK_EX`? If not, what
  are the advantages of your approach?
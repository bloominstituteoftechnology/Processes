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
  * For one, let's say there's $1000 available, and two processes attempt to withdraw $800. If they both do this at the same time, then $1000 is technically available to *each*, meaning that there will be a total withdrawl of $1600, which should cause both to fail with the message that there's only $1000 available, or both to succeed which would put the balance into the negative.

2. Study and understand the skeleton code in the `src/` directory.

  **Short answer**: what do each of the arguments to `open()` mean?
  ```C
  int open(const char *path, int oflags, mode_t mode);
  ```
  * The first argument is the relative or absolute path to the file being opened.
  * The second argument is a bitwise 'or' separated list of values that determine the method in which the file is to be opened (whether it should be read only, read/write, whether it should be cleared when opened, etc).
    * As an example, in `bankers.c` we're using `O_CREAT|O_RDWR`. `O_CREAT` will create a new file if one does not exist (and also requires the `mode` argument at the end), while `O_RDWR` opens the file for read/write.
  * The third argument can be a bitwise 'or' separated list of values, or octal notation, that determine the permissions of the file if it is created.
    * In `bankers.c` the argument `0644` is provided, an octal which represents `-rw-r--r--` in *nix, which can be translated to:
    ```
    * (owning) User: read & write
    * Group: read
    * Other: read
    ```

3. Take the skeleton code in the `src/` directory and implement the
   pieces marked. Run it.
   
  **Short answer**: What happens? Do things go as planned and look
  sensible? What do you speculate is happening?
  * I implemented this using `flock()` prior to noticing these short answer questions, however even with this function commented out and the binary recompiled, I do not seem to be getting any unusual output. Here is an example of output **without** `flock()`:
  ```
  ./bankers 30
  Withdrew $728, new balance $9272
  Withdrew $549, new balance $8723
  Withdrew $894, new balance $7829
  Withdrew $416, new balance $7413
  Withdrew $832, new balance $6581
  Withdrew $478, new balance $6103
  Withdrew $965, new balance $5138
  Withdrew $405, new balance $4733
  Withdrew $593, new balance $4140
  Withdrew $137, new balance $4003
  Withdrew $705, new balance $3298
  Withdrew $810, new balance $2488
  Withdrew $586, new balance $1902
  Withdrew $432, new balance $1470
  Withdrew $215, new balance $1255
  Withdrew $533, new balance $722
  Withdrew $266, new balance $456
  Only have $456, can't withdraw $557
  Only have $456, can't withdraw $562
  Withdrew $76, new balance $380
  Withdrew $95, new balance $285
  Withdrew $90, new balance $195
  Withdrew $111, new balance $84
  Only have $84, can't withdraw $296
  Only have $84, can't withdraw $356
  Only have $84, can't withdraw $310
  Only have $84, can't withdraw $99
  Only have $84, can't withdraw $525
  Only have $84, can't withdraw $96
  Withdrew $73, new balance $11
  ```

4. Add calls to [`flock()`](https://linux.die.net/man/2/flock) to
   capture and release an exclusive lock on the file before reading and
   changing the data.

   The results of the run should now make sense.
   
5. **Short answer**: Why is it working? How has adding locks fixed the
  problems you noted in question 1? How is overall performance of the
  application affected?
  * I don't have an answer to this, as I ran into no unusual behavior without `flock()`.


## Stretch Goals

* Make some processes deposit money while others withdraw money.

* Have some processes simply check the balance without changing it. Do
  you need to lock? If so, do you need to use `LOCK_EX`? If not, what
  are the advantages of your approach?
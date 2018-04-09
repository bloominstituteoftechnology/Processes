# Processes: Exercise short answers

## Exercise 1

Write a program that calls `fork()`.
Before calling `fork()`, have the main process access a variable (e.g., x)
Set its value to something (e.g., 100).

* What value is the variable in the child process?

* What happens to the variable when both the child and parent change the value of x?

## Exercise 2

Write a program that opens the text.txt file (with the `fopen()` system call) located in this directory. Then calls `fork()` to create a new process.

* Can both the child and parent access the file descriptor returned by `fopen()`?

* What happens when they are written to the file concurrently?

## Exercise 3 - Coding Only

## Exercise 4

Write a program that calls `fork()` and then calls some form of `exec()` to run the program `/bin/ls`. Try a few variants of `exec()`, such as `execl()`, `execle()`, `execv()`, and others.

* Why do you think there are so many variants of the same basic call?


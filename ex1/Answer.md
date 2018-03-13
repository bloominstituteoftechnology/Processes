1.  Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?

Answer: If variable is reset value before fork(), the value in the child process will be equal to the newly assigned value to variable.

2.  What happens to the variable when both the child and parent change the value of x?

Answer: If parent and child change the value of x, x should be equal to different values in respective processes. But the final value of x should be equal to the last value that either one of the processes that runs later reassigns to .

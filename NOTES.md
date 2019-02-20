# Processes

## Requirements to Execute a Program
- CPU
- Memory


high address                  Command-line Args & Environment Variable

    stack
      |
      |
    heap                      malloc data

    uninitialized data (bss)  initialized to zero by exec

    initialized data           \         
                                } read from program file by exec
    text                       /

low address


Process are isolated by default (unaware of each other by default)

# Initializing a Process

- Allocation of working memory.
- Entry is added to the operating system's processing list.
- OS's scheduling algorithm schedules the newly-initialized process.

## Scheduling
Process List
PID   Command   
1       a
2       b
3       c      -->
4       d    Context      CPU
5       e    Switching
6       f     <--
7       g
8       h

PID (Process Identifier Number): 2 byte number

## Privileged vs. Non-Privileged
Privileged operations
- Creating new processes
- destroying existing processes
- Allocating memory
- Accessing hardware functionality
- scheduling algorithm

Non-Privileged operations
- everything I write. :)


# System Calls
- A request to the OS to perform a privileged operation on its behalf.
- Uses requests and response (similar to API calls)

System calls with requests and responses is: 
- Less Performant but Safer

MS-DOS allowed Processes to perform a privileged operations, which is why games are more prevelant on Windows than Mac.

## Commonly-Used System Calls
- fork()  create copy of existing process
- exec()  execute a spedified file
- chdir() change working directory
- pipe() create a prip for interprocess communication.

fork() 
  - creates a child process, which is a copy from the parent process
  - returns twice:
      - one result in the parent
      - another result in the child

```c
# include 
// putchar: writes a character to the standard output (stdout);
// it is equivalent to calling putc iwth stdout as second argument.
void print_str(char *s) {
  int i;
  char *p = s; // saving a copy of s
  // putchar(** take a character argument)
  //iterate over s and use putchar for every character on the array of characters.
  for(i = 0; s[i] != '\0; i++) {
    putchar(s[i]);
  }

  // equivalent method
    for(i = 0; *(s+i) != '\0; i++) {
    putchar(*s(i+i));
  }

    // another method: it manipulates the values themselves
    for(; *s != '\0; s++) {
      putchar(*s);
  }

  // after doing the last method (the s pointer is pointing to '\0' so calling the first method will no longer work since s is already at '\0'). So we need to add:
  s = p;

  while (*s != '\0') {
    putchar(*(s++))
    /* combines 2 lines of into one; it is equivalent to:
      putchar(*s);
      s++;
    */ 
  }


}
int main(void) {
  pid_t pid;
  pid = fork(); // doesn't take paramters
  if (pid == 0) {
    printf("I am the child\n");
  } else {
    printf("Parent is about to wait\n");
    wait(NULL) // if this is commentted result will be different.
    printf("I am the parent\n");
  }


  return 0;
}
```

```c
# include 
// putchar: writes a character to the standard output (stdout);
// it is equivalent to calling putc with stdout as second argument.


/* 
size_t write(int fd, void* buf, size_t cnt);
fd: fild descripter
buf buffer to write data to
cnt: length of buffer

size_t is typedef howevers it's going to return how many bytese were actually written

return Number of bytes written on success
return 0 on reaching end of file
return -1 on error
*/


void putchar_ls(char c) {
  // c is a vlue we need to have a pointer
  //so we use & to point to the address of c
  write(1, &c, 1);
  // sz = write(1, &c, 1);
  // printf("\n%d\n", sz);
}

void print_str(char *s) {
  while(*s != '\0') {
    putchar_ls(*(s++))
  }
}


}
int main(void) {

  printf("HelloWorld\n");
  return 0;
}


### Programs into Processes

1. Operating System __loads__ any code and any static data into its memory (in the address space of the process). 
    - Programs initially run on __disk__ or on __Solid State Hard Drive (SSD__) in some kind of executable format. 
    - on modern machines, this is done __lazily__. It only loads what is needed during program execution. 
2. Memory must be allocated for the program's run-time __stack__. This is used for program vars, function params, and return addresses. The OS allocates this memory and gives it to the process. The OS will also initialize the stack with arguments from the `main()` func if there are any. 

3. Memory may also be allocated for the program's __heap__. In C programs, the heap is used for explicitly requested dynamically-allocated data (read: `malloc()` and `free()`). The heap is needed for data structures such as linked lists, hash tables, trees, etc. 

4. The OS will also do some other initialization tasks, particularly related to input/output (I/O). 

The above four things sets the stage for program execution. 

`main()`

OS transfers control of the CPU to the newly created process and the program begins execution. 
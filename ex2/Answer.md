Can both the child and parent access the file descriptor returned by `fopen()`? What happens when they are written to the file concurrently?

Answer: Both child and parent processes can access the file descriptor. Because parent and child share the same file pointer and offset, so one process writes and increments the offset, another process will use the modified offset and write new content. Both of the written contents will be together.

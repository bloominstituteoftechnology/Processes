Why do you think there are so many variants of the same basic call?

Answer:

The exec subroutine, in all its forms, executes a new program in the calling process. The exec subroutine does not create a new process, but overlays the current program with a new one, which is called the new-process image. The new-process image file can be one of three file types:

* An executable binary file in XCOFF file format.
* An executable text file that contains a shell procedure (only the execlp and execvp subroutines allow this type of new-process image file).
* A file that names an executable binary file or shell procedure to be run.

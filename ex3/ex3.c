// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

// So we're kind of in a pickle aren't we?
// I know the gotcha already tho R: so wat do den?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int f = fork(); // <- You forked here, and saved it to variable `f` Would that mean on line 24 it should be(f, NULL, 0)? R: Yes J: still reading your explanation I was paying attention to lecture for a sec R: no worries. lect is important too
        if (f > 0) // R: Is this parent or child?
        {            
            int holdup = waitpid(f, NULL, 0); // semicolon. also you're passing rc as the first argument there you go and it just calls itself on creation? cause part of me naturally wants to then call this after. lke calling holdup somewhere
            // like call waitpid after printing goodbye? or you mean this should be somewhere further down the code? J: not further down but like the int holdup = <etc> is just creating it in my mind not running it. that line just brings the variable holdup into exsistence but doesn't call it even though it does call it but why. Is that weird to you cause it's weird from my slightly JS brain
            /*
            int holdup = waitpid(f, NULL, 0);
            So when C gets to this line, it's going to evaluate whatever is right of the assignment operator (the `=` sign) to get a value to assign to the variable
            That means it's going to call waitpid(f, NULL, 0);. waitpid() will then actually do it's job and put the process on hold until the other process is done
            When the other process is done, waitpid() will finish and return a value.
            Finally, that value will be saved to variable holdup, and execution continues.
            In other words, there's much more happening than just creating a variable. You tell C save the value of `waitpid()` to variable holdup.
            In order for C to do that, it has to run `waitpid()`, and therefore `waitpid()` is gonna do it's thing. I get it now thanks
            now onto 4 because this one works & this one doesn't have questions at the top. :+1:
            */
            char *pText = "goodbye";  
            printf("%s\n", pText);
            
        }
        else if (f == 0) // R: Is this parent or child? If it's 0 it's the parent and greater it's the child? R: If it's 0 it's the child and greater it's the parent.
        { // roflmao i didn't say this EDIT: shizz (Lambda professionalism) was the parrent hahaha yeah but all these questions lead to doubt loll
            char *cText = "hello"; 
         // it's always NULL in C. True but can you kinda explain this line a bit more. I know it's a delay but I kinda just got shown this during peer code review & I understand that we would need to delay the print
            // I have to google the other arguments, but the most important argument is the first one. The first argument is the PID of the process you want to wait for
            // What will happen is that upon the execution of waitpid(), the process is essentially on pause until the process that has the PID you passed into waitpid() has terminated.
            // In your instance, you should pass in the value of whatever you got from fork(). In the parent process, the value of that is the PID of the child process. For the child, the value of that is 0.
            // Which variable did you save the result of fork to? What argument are you passing into wait PID?
            // Still looking up the second. But for now, it should just be NULL.
            // The third argument is not a delay, but an options argument. You can customize behavior by passing some argument other than 0 (e.g. WNOHANG, WUNTRACED, etc). For this assignment, not something we need to worry about.
            // I just realized we may be in the wrong place here. This conditional is the child or the parent?
            printf("%s\n", cText); // <- Also cText disappeared
            
        }
        else // R: fork messed up
        //I don't think I even needed the delay
        {
            printf("fork failed \n");
            
        }
    return 0;
    }



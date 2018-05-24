// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_NAME_DATA 20

typedef struct Person {
    int age;
    char first_name[MAX_NAME_DATA];
    char last_name[MAX_NAME_DATA];
    char username[MAX_NAME_DATA];
} Person;

int checkName (char *str){
    int i = 0;
    while(str[i]){
        i++;
    }
    if(i > 1){
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{   
    // Your code here
    FILE *fs;

    // // open the file using
    // // ptr = fopen("fileopen","mode")
    // // https://www.programiz.com/c-programming/c-file-input-output
    fs = fopen("ex2/text.txt", "r");

    if (fs == NULL)
    {
        printf("Error!");
        exit(1);
    }

    
    char output[100];

    while (fgets(output,1000, fs)!=NULL){
        printf("%s",output);
    }

    fclose(fs);
    // another way is using fscanf
    // fscanf(fs, "%s\n", output);
    // printf("The file contains %s", output);

    Person person;

    char *input = NULL;
    int age;

    printf("Hello World! (PID: %d)\n", (int)getpid());
    printf("Please enter your information!!. \n");
    printf("====================================================\n");

    // // username
    printf("Enter username: ");
    input = fgets(person.username, MAX_NAME_DATA, stdin);
    if(checkName(input) == 0){
        // success, move on or do other checks
    }else{
        while(checkName(input)){
            printf("Error encountered. Please enter a username: ");
            input = fgets(person.username, MAX_NAME_DATA, stdin);
        }
    }

    // first name
    printf("Enter your first name: ");
    input = fgets(person.first_name, MAX_NAME_DATA, stdin);
    if(checkName(input) == 0){
        // success, move on or do other checks
    }else{
        while(checkName(input)){
            printf("Error encountered. Please enter your first name: ");
            input = fgets(person.first_name, MAX_NAME_DATA, stdin);
        }
    }

    // last name
    printf("Enter your last name: ");
    input = fgets(person.last_name, MAX_NAME_DATA, stdin);
    if(checkName(input) == 0){
        // success, move on or do other checks
    }else{
        while(checkName(input)){
            printf("Error encountered. Please enter your last name: ");
            input = fgets(person.last_name, MAX_NAME_DATA, stdin);
        }
    }

    // age
    printf("Enter your age: ");
    age = fscanf(stdin, "%d", &person.age);


    // write the information to the file
    fs = fopen("ex2/text.txt", "a+");
    fprintf(fs,"%c", '{');

    fprintf(fs,"%s", "username:");
    fprintf(fs,"%c", '"');
    fprintf(fs,"%s", person.username);
    fprintf(fs,"%s", "\",");

    fprintf(fs,"%s", "first_name: ");
    fprintf(fs,"%c", '"');
    fprintf(fs,"%s", person.first_name);
    fprintf(fs,"%s", "\",");

    fprintf(fs,"%s", "last_name: ");
    fprintf(fs,"%c", '"');
    fprintf(fs,"%s", person.last_name);
    fprintf(fs,"%s", "\",");

    fprintf(fs,"%s", "age: ");
    fprintf(fs,"%d", person.age);
    fprintf(fs,"%s", "},");
    fprintf(fs,"\n");

    // call fork()
    int rc = fork();

    // child process starts execution here
    if (rc < 0)
    {
        // fork failed exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        char *child_username = "child";
        char *child_first_name = "first_child";
        char *child_last_name = "last_child";
        int child_age = 23;
        // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int)getpid());

        // write the information to the file
        fprintf(fs,"%c", '{');

        fprintf(fs,"%s", "username:");
        fprintf(fs,"%c", '"');
        fprintf(fs,"%s", child_username);
        fprintf(fs,"%s", "\",");

        fprintf(fs,"%s", "first_name: ");
        fprintf(fs,"%c", '"');
        fprintf(fs,"%s", child_first_name);
        fprintf(fs,"%s", "\",");

        fprintf(fs,"%s", "last_name: ");
        fprintf(fs,"%c", '"');
        fprintf(fs,"%s", child_last_name);
        fprintf(fs,"%s", "\",");

        fprintf(fs,"%s", "age: ");
        fprintf(fs,"%d", child_age);
        fprintf(fs,"%s", "},");
        fprintf(fs,"\n");
    }
    else
    {
        char *parent_username = "parent";
        char *parent_first_name = "first_parent";
        char *parent_last_name = "last_parent";
        int parent_age = 53;

        printf("hello, parent \n (pid: %d) \n", (int)getpid());

        // write the information to the file
        fprintf(fs,"%c", '{');

        fprintf(fs,"%s", "username:");
        fprintf(fs,"%c", '"');
        fprintf(fs,"%s", parent_username);
        fprintf(fs,"%s", "\",");

        fprintf(fs,"%s", "first_name: ");
        fprintf(fs,"%c", '"');
        fprintf(fs,"%s", parent_first_name);
        fprintf(fs,"%s", "\",");

        fprintf(fs,"%s", "last_name: ");
        fprintf(fs,"%c", '"');
        fprintf(fs,"%s", parent_last_name);
        fprintf(fs,"%s", "\",");

        fprintf(fs,"%s", "age: ");
        fprintf(fs,"%d", parent_age);
        fprintf(fs,"%s", "},");
        fprintf(fs,"\n");
    }
    fclose(fs);
    return 0;
}

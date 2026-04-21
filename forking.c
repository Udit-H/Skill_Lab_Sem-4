#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork(); //Fork a child process
    if(pid < 0) //Error Occured
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if(pid == 0) //Child process
    {
        execlp("/bin/ls", "ls", NULL);
    }
    else{ //Parent Process
        wait(NULL);
        printf("Child Complete");
    }
    return 0;
}
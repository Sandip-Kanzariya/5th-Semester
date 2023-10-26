
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h> 

int main () {
    int pipefd[2];
    pipe(pipefd);
    int pid = fork();
    if(pid > 0) //parent
    { 
        wait(NULL);
        close(pipefd[1]);
        // our pipe is outputing to stdout
        // now to read from there we need to take data from stdin
        // so stdout is outputing and stin is receiving
        dup2(pipefd[0], 0);
        // now this function will have listing and now it will sort
        execl("/bin/sort", "sort", NULL);
    }
    else if (pid == 0)  //child
    {
        // we need to have output in our write head
        // and not in stdout
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        execl("/bin/ls", "ls", NULL);
    }
    return 0;
}
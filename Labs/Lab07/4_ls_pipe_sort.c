#include <stdio.h>
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdlib.h>
#include <unistd.h> 
int main(){


    int pipefd[2];
    int c = pipe(pipefd);

    int pid = fork();
    
    
    if(pid > 0){ // Parent 

        // wait(NULL);
        close(pipefd[1]);
        dup2(pipefd[0], 0);

        execl("/bin/sort", "sort", NULL);

        
    }
    else if(pid == 0){ // Child

        int newfd = dup2(pipefd[1], 1);     
        close(pipefd[0]);
        execl("/bin/ls", "ls", NULL);
        
        // execl("/bin/ls", "ls", "-l", "--sort=extension", NULL);
    }

    return 0;
}


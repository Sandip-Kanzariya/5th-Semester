#include <stdio.h>
#include <fcntl.h> 
#include <sys/types.h> 
#include <stdlib.h>
#include <unistd.h> 
int main(){

    int pid = fork();
    if(pid == 0){ // Child 
        // printf("Child : \n");
        execl("/bin/pwd", "pwd",  NULL);
    }
    else if(pid > 0){ // Parent 
        // printf("Parent : \n");
        execl("/bin/ls", "ls", "-l",  NULL);
    }
    return 0;
}
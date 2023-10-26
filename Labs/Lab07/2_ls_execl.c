#include <stdio.h>
#include <fcntl.h> 
#include <sys/types.h> 
#include <stdlib.h>
#include <unistd.h> 
int main(){


    printf("Hello, Good Morning : \n");
    
    // execl("/bin/pwd", "pwd",  NULL);

    execl("/bin/ls", "ls", "-l",  NULL);

    printf("Bye Bye I am not Going any way : \n");
    return 0;
}
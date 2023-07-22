#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    int pid = fork();

    if (pid == 0) // Child
    {
        printf("Hello From Child ! | ");
        printf("PID : %d \n", getpid());
    }
    else if (pid > 0) // Parent
    {
        printf("Hello From Parent ! | ");
        printf("PID : %d\n", getpid());
    }
    else
    {
        printf("Hello From Error :");
    }

    return 0;
}

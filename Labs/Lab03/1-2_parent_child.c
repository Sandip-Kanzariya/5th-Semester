#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    int pid = fork();

    if (pid > 0) // Parent
    {

        printf("Parent Id : ");
        int parent = getpid();
        printf("%d ", parent);

        printf("Child Id : ");
        printf("%d\n", pid);`
        wait(0);
    }
    else if (pid == 0) // Child
    {
        
        printf("Child Id : ");
        int child = getpid();
        printf("%d ", child);

        printf("Parent Id : ");
        int parent = getppid();
        printf("%d", parent);
    }

    return 0;
}

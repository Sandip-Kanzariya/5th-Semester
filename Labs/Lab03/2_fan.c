#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    printf("Enter Number of Child : ");
    int n;
    scanf("%d", &n);

    int pid;
    for (int i = 0; i < n; i++)
    {
        pid = fork();

        if (pid == 0)
        {
            printf("Parent : %d | ", getppid());
            printf("Child : %d\n", getpid());
            break;
        }
    }

    return 0;
}

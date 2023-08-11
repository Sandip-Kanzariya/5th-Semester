#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    int pid, n, i, status;

    n = 4;

    printf("#");

    for (i = 0; i < n; i++)
    {
        pid = fork();

        if (pid == -1)
        {
            printf("Error");
        }

        else if (pid > 0)
        {

            wait(&status);
            printf("**\n");
            exit(0);
        }

        else if (pid == 0)

        {
            printf("*\n");
        }
    }
    return 0;
}

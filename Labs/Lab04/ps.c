#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{

    char *p = "/proc";

    DIR *dp = opendir(p);

    struct dirent *dr = readdir(dp);

    while (dr != NULL)
    {

        // printf("%s\n", dr -> d_name);

        char *name = dr->d_name;

        int isNum = 1;
        while (*name != 0)
        {

            // printf("%c ", *name);

            if (*name < '0' || *name > '9')
            {
                isNum = 0;
                break;
            }

            name++;
        }

        if (isNum)
        {
            // printf("%s\n", dr -> d_name);

            char fullPath[40];

            strcpy(fullPath, p);

            strcat(fullPath, "/");
            strcat(fullPath, dr->d_name);
            strcat(fullPath, "/stat");

            printf("%s\n", fullPath);
            FILE *demo = fopen(fullPath, "r");

            if (demo == NULL)
            {
                perror("Failed to open stat file");
                return 1;
            }

            int pid;
            char comm[300], state;
            // The correct format specifier for the `fscanf` function is %d %s %c, as shown below:
            fscanf(demo, "%d %s %c", &pid, comm, &state);
            
            printf("%7d %c %s\n", pid, state, comm);


            // Display whole content of file : 
            /* 
            int display;
            while (1)
            {
                // reading file
                display = fgetc(demo);
                // end of file indicator
                if (feof(demo))
                    break;
                // displaying every characters
                printf("%c", display);
            }
            */

            // closes the file pointed by demo
            fclose(demo);
        }

        dr = readdir(dp);
    }

    return 0;
}

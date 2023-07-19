#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

// Check it is [. / .. ] or not
int isDdot(char *dir){
    if(strcmp(dir, ".") != 0 && strcmp(dir, "..") != 0) return 1;
    return 0;
}

// 
void fun(char *dirf)
{

    // printf("%s\n", dirf);
    DIR *dp = opendir(dirf);

    struct dirent *dr = readdir(dp);

    while (dr != NULL)
    {

        if (isDdot(dr -> d_name))
        {
            printf("%s\n", dr->d_name);
        }

        if (dr->d_type == 4 && isDdot(dr -> d_name))
        {
            char full[500];

            // Concate :
            strcpy(full, dirf);
            strcat(full, "/");
            strcat(full, dr->d_name);

            // printf("%s\n", full);
            fun(full);
        }

        dr = readdir(dp);
    }
}

int main()
{

    char b[1000];
    char *p = getcwd(b, sizeof(b));

    fun(p);

    return 0;
}

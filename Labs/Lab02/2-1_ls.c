#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{

    char b[1000];

    char *p = getcwd(b, sizeof(b));

    printf("%s\n", p);

    DIR *dp = opendir(p);

    struct dirent *dr = readdir(dp);

    while (dr != NULL)
    {

        printf("%s\n", dr->d_name);

        dr = readdir(dp);
    }
    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main()
{

    char b[1000];

    char *p = getcwd(b, sizeof(b));

    printf("%s\n", p);

    return 0;
}

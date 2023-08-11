#include <stdio.h>
#include <pthread.h>

void *fun()
{
    printf("Hello From Thread\n");

    return NULL;
}
int main()
{

    pthread_t t;

    int p = pthread_create(&t, NULL, fun, NULL);
    int c = pthread_join(t, NULL);
    return 0;
}

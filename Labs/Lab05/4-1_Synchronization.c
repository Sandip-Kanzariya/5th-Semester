#include <stdio.h>
#include <pthread.h>

int count = 0;

void *fun()
{
    count++;
    printf("Count : %d\n", count);
    return NULL;
}

int main()
{

    pthread_t arr[5];

    for (int i = 0; i < 5; i++)
    {
        int p = pthread_create(&arr[i], NULL, fun, NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        int j = pthread_join(arr[i], NULL);
    }

    return 0;
}

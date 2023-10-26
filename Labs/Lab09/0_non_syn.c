#include <stdio.h>
#include <pthread.h>

int count = 0;
void *fun()
{

    count++;
    printf("%d\n", count);
    
    return NULL;
}

int main()
{

    pthread_t arr[5];

    for (int i = 0; i < 5; i++)
    {
        int p = pthread_create(&arr[i], NULL, (void *)fun, NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        int q = pthread_join(arr[i], NULL);
    }

    return 0;
}
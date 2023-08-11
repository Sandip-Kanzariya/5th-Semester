#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *fun()
{
    pthread_mutex_lock(&m);
    count++;
    printf("Count : %d\n", count);

    pthread_mutex_unlock(&m);
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

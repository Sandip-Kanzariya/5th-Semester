#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int readerCount;
sem_t X, wsem;

void reader()
{

    while (1)
    {
        sem_wait(&X);
        readerCount++;
        if (readerCount == 1)
            sem_wait(&wsem); // Priority Condition
        sem_post(&X);

        //
        printf("%d Reader\n", readerCount);
        sleep(1);
        sem_wait(&X);
        readerCount--;
        if (readerCount == 0)
            sem_post(&wsem);
        sem_post(&X);
    }
}

void writer()
{

    while (1)
    {
        sem_wait(&wsem);

        //
        printf("%d Writer\n", readerCount);
        sleep(1);
        sem_post(&wsem);
    }
}

int main()
{

    readerCount = 0;

    // initilize
    int Xi = sem_init(&X, 0, 1);
    int semi = sem_init(&wsem, 0, 1);

    // Cretate Threads
    pthread_t readert[4], writert[2];

    for (int i = 0; i < 4; i++)
    {
        int tr = pthread_create(&readert[i], NULL, (void *)reader, NULL);
    }

    for (int i = 0; i < 2; i++)
    {

        int tw = pthread_create(&writert[i], NULL, (void *)writer, NULL);
    }

    // Join

    for (int i = 0; i < 4; i++)
    {
        int jr = pthread_join(readert[i], NULL);
    }

    for (int i = 0; i < 2; i++)
    {
        int jw = pthread_join(writert[i], NULL);
    }

    return 0;
}

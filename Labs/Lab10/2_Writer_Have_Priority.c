#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int readerCount, writerCount;
sem_t x, y, z, wsem, rsem;

void reader()
{

    while (1)
    {
        sem_wait(&z);
        sem_wait(&rsem);
        sem_wait(&x);
        readerCount++;
        if (readerCount == 1)
            sem_wait(&wsem);
        sem_post(&x);
        sem_post(&rsem);
        sem_post(&z);

        //
        printf("%d Read\n", readerCount);
        sleep(1);
        sem_wait(&x);
        readerCount--;
        if (readerCount == 0)
        {
            sem_post(&wsem);
        }

        sem_post(&x);
    }
}

void writer()
{

    while (1)
    {
        sem_wait(&y);
        writerCount++;
        if (writerCount == 1)
            sem_wait(&rsem);
        sem_post(&y);
        //
        printf("%d Write\n", writerCount);
        sleep(1);
        sem_wait(&y);
        writerCount--;
        if (writerCount == 0)
            sem_post(&rsem);
        sem_post(&y);
    }
}

int main()
{

    readerCount = 0;
    writerCount = 0;

    // initilize
    int xi = sem_init(&x, 0, 1);
    int yi = sem_init(&y, 0, 1);
    int zi = sem_init(&z, 0, 1);
    int semw = sem_init(&wsem, 0, 1);
    int semr = sem_init(&rsem, 0, 1);

    // Cretate Threads
    pthread_t readert[2], writert[5];

    for (int i = 0; i < 2; i++)
    {
        int tr = pthread_create(&readert[i], NULL, (void *)reader, NULL);
    }

    for (int i = 0; i < 5; i++)
    {

        int tw = pthread_create(&writert[i], NULL, (void *)writer, NULL);
    }

    // Join

    for (int i = 0; i < 2; i++)
    {
        int jr = pthread_join(readert[i], NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        int jw = pthread_join(writert[i], NULL);
    }

    return 0;
}

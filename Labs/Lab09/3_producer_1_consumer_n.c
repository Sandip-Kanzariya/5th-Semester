#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int sb = 5; // 
sem_t s, n, e;
int count = 0;
int arr[5] = {0, 0, 0, 0, 0};

int i = 0;
void * producer(){

    while(1){

        int item = 50;
        sem_wait(&e);
        sem_wait(&s);
        arr[i] = item;
        printf("Item : %d is produce at : %d === \n", item, i);
        i++;

        sleep(1);
        sem_post(&s);
        sem_post(&n);
    }

    return NULL;
}

void * consumer(){

    
    while(1){
        sem_wait(&n);
        sem_wait(&s);
        // take
        i--;
        int c = arr[i];
        printf("Item : %d is Consume at : %d by Thread : %ld \n", c, i, pthread_self());
        sleep(1);
        sem_post(&s);
        sem_post(&e);
    }

    return NULL;
}

int main(){

    // sem_name, for_thread, init_value
    int sinit = sem_init(&s, 0, 1);
    int ninit = sem_init(&n, 0, 0); 
    int einit = sem_init(&e, 0, sb);

    // Create Threads
    pthread_t producert, ct[3];
    int pt = pthread_create(&producert, NULL, (void*)producer, NULL);

    for (int i = 0; i < 3; i++)
    {
        int c = pthread_create(&ct[i], NULL, (void*)consumer, NULL);
    }
    
    
    // Join
    int pj = pthread_join(producert, NULL);

    for (int i = 0; i < 3; i++)
    {
        int pc = pthread_join(ct[i], NULL);
    }

    return 0;
}
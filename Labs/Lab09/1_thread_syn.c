#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


sem_t s;
int count = 0;
void * fun(){

    // sem
    int w = sem_wait(&s);
    count++;
    printf("%d\n", count);
    int p = sem_post(&s);
   return NULL;
}

int main(){

    // sem_name, for_thread, init_value
    int p = sem_init(&s, 0, 1);


    pthread_t arr[5];

    for (int i = 0; i < 5; i++)
    {
        int p = pthread_create(&arr[i], NULL, (void*)fun, NULL);
    }
    
    for(int i = 0;i < 5;i++){
        int q = pthread_join(arr[i], NULL);
    }

    return 0;
}
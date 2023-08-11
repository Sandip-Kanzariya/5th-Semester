#include <stdio.h>
#include <pthread.h>

// Function argument & return type both are Void pointer
void *fun(void *ex)
{

    printf("%s\n", (char *)ex);

    return NULL;
}

int main()
{

    pthread_t t;

    char str[25] = "Hello, This is string.";

    // int p = pthread_create(&t, NULL, fun((void *)str), NULL);
    int p = pthread_create(&t, NULL, fun, (void *)str);
    int j = pthread_join(t, NULL);
    
    return 0;
}

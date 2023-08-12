#include <stdio.h>
#include <pthread.h>

struct sc
{
    int a, b;
    char c;
    int ans;
};

void *operation(void *st)
{
    struct sc *op = (struct sc *)st;
    printf("a = %d, b = %d\n", op->a, op->b);

    if(op->c == '+'){
        op->ans = op->a + op->b;
    }
    else if(op->c == '-')
    {
        op->ans = op->a - op->b;
    }
    else if(op->c == '*')
    {
        op->ans = op->a * op->b;
    }
    else if(op->c == '/')
    {
        op->ans = op->a / op->b;
    }
    else{
        printf("Not a valid operation!");
        return NULL;
    }

    printf("a %c b = %d\n\n", op->c, op->ans);
    return NULL;
}

int main()
{
    pthread_t ta, ts, tm, td;
    struct sc st_add, st_sub, st_mul, st_div; // Separate instances for each thread
    st_add.a = st_sub.a = st_mul.a = st_div.a = 4;
    st_add.b = st_sub.b = st_mul.b = st_div.b = 2;

    st_add.c = '+';
    int p1 = pthread_create(&ta, NULL, operation, (void *)&st_add);
    
    st_sub.c = '-';
    int p2 = pthread_create(&ts, NULL, operation, (void *)&st_sub);
    
    st_mul.c = '*';
    int p3 = pthread_create(&tm, NULL, operation, (void *)&st_mul);
    
    st_div.c = '/';
    int p4 = pthread_create(&td, NULL, operation, (void *)&st_div);
    
    int c1 = pthread_join(ta, NULL);
    int c2 = pthread_join(ts, NULL);
    int c3 = pthread_join(tm, NULL);
    int c4 = pthread_join(td, NULL);
    
    return 0;
}

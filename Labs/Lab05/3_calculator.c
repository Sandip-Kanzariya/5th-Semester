#include <stdio.h>
#include <pthread.h>

struct sc
{
    int a, b;
};

void *add(void *st)
{
    struct sc *ans = (struct sc *)st;
    printf("a = %d, b = %d\n", ans->a, ans->b);
    printf("a + b = %d\n", ans->a + ans->b);
    return NULL;
}

void *sub(void *st)
{
    struct sc *ans = (struct sc *)st;
    printf("a = %d, b = %d\n", ans->a, ans->b);
    printf("a - b = %d\n", ans->a - ans->b);
    return NULL;
}

void *mul(void *st)
{
    struct sc *ans = (struct sc *)st;
    printf("a = %d, b = %d\n", ans->a, ans->b);
    printf("a * b = %d\n", ans->a * ans->b);
    return NULL;
}

void *divi(void *st)
{
    struct sc *ans = (struct sc *)st;
    printf("a = %d, b = %d\n", ans->a, ans->b);
    printf("a / b = %d\n", ans->a / ans->b);
    return NULL;
}

int main()
{
    pthread_t ta, ts, tm, td;
    struct sc st;
    st.a = 4;
    st.b = 2;

    int p1 = pthread_create(&ta, NULL, add, (void *)&st);
    int p2 = pthread_create(&ts, NULL, sub, (void *)&st);
    int p3 = pthread_create(&tm, NULL, mul, (void *)&st);
    int p4 = pthread_create(&td, NULL, divi, (void *)&st);

    int c1 = pthread_join(ta, NULL);
    int c2 = pthread_join(ts, NULL);
    int c3 = pthread_join(tm, NULL);
    int c4 = pthread_join(td, NULL);
    
    return 0;
}

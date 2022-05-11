/* bad sharing */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define ITER 1000
void *thread_increment(void *arg);
void *thread_decrement(void *arg);
int x;
int main() {
    pthread_t tid1, tid2;
    x = 0;
    pthread_create(&tid1, NULL, thread_increment, NULL);
    pthread_create(&tid2, NULL, thread_decrement, NULL);
    
    sleep(1);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    if (x != 0)
        printf("BOOM! counter=%d\n", x);
    else
        printf("OK counter=%d\n", x);
}

/* thread routine */
void * thread_increment (void *arg) {
    int i, val;
    for (i=0; i< ITER ; i++) {
        val = x;
        printf("%u: %d\n", (unsigned int)pthread_self(), val);
        x = val + 1;
    }
    return NULL;
}

void * thread_decrement (void *arg) {
    int i, val;
    for (i=0; i< ITER ; i++) {
        val = x;
        printf("%u: %d\n", (unsigned int)pthread_self(), val); x = val - 1;
    }
    return NULL;
}

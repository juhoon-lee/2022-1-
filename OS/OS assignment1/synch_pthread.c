#include <pthread.h>
#include <stdio.h>
#define ITER 1000
void *producer(void *arg);
void *consumer(void *arg);
int x;
pthread_mutex_t m; // mutex
pthread_cond_t c;

int main() {
    pthread_t tid1, tid2;
    
    pthread_mutex_init(&m, NULL); // 상호배제
    pthread_cond_init(&c, NULL); // 조건동기
    
    // 생산자, 소비자
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    if (x != 0)
    {
        printf("BOOM! counter = %d\n", x);
    }
    else
    {
        printf("OK counter = %d\n",  x);
        
    }
    pthread_mutex_destroy(&m);
}

void * producer (void *arg) { // 생산자
    int i, val;
    for (i=0; i< ITER ; i++) {
        pthread_mutex_lock(&m); // 상호배제
        if (x == 0) {
            pthread_cond_wait(&c, &m); // 조건 동기(0이면 생산 x)
        }
        val = x;
        printf("%u: %d\n", (unsigned int) pthread_self(), val);
        x = val + 1;
        pthread_cond_signal(&c); // 조건 동기
        pthread_mutex_unlock(&m); // 상호배제
    }
    return NULL;
}

void * consumer (void *arg) { // 소비자
    int i, val;
    for (i=0; i< ITER ; i++) {
        pthread_mutex_lock(&m); // 상호배제
        if (x == -30) {
            pthread_cond_wait(&c, &m); // 조건 동기(-30 이면 소비 x)
        }
        val = x;
        printf("%u: %d\n", (unsigned int) pthread_self(), val);
        x = val - 1;
        pthread_cond_signal(&c); // 조건 동기
        pthread_mutex_unlock(&m); // 상호배제
    }
    return NULL;
}


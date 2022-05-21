/* bad sharing */
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#define ITER 1000
void *thread_increment(void *arg);
void *thread_decrement(void *arg);
int x;
sem_t m, upperBound, lowerBound;// 세마포어

int main() {
    
  pthread_t tid1, tid2;
  
  sem_init(&m, 0, 1); // 상호배제
  sem_init(&upperBound, 0, 0); // 0 초과을 방지하기 위해
  sem_init(&lowerBound, 0, 30); // -30 미만을 방지하기 위해
    
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
    sem_destroy(&m);
    sem_destroy(&upperBound);
    sem_destroy(&lowerBound);
}


void * producer (void *arg) {
  int i, val;
  for (i=0; i< ITER ; i++) {
    sem_wait(&upperBound); // 0보다 커지려 하면 조건 동기
    sem_wait(&m); // x 값 변경 부분 상호배제
    val = x;
    printf("%u: %d\n", (unsigned int) pthread_self(), val);
    x = val + 1;
    sem_post(&m); // x 값 변경 부분 상호배제
    sem_post(&lowerBound); // 조건 동기
  }
  return NULL;
}

void * consumer (void *arg) {
  int i, val;
  for (i=0; i< ITER ; i++) {
    sem_wait(&lowerBound); // -30보다 작아지려 하면 조건 동기
    sem_wait(&m); // x 값 변경 부분 상호배제
    val = x;
    printf("%u: %d\n", (unsigned int) pthread_self(), val);
    x = val - 1;
    sem_post(&m); // x 값 변경 부분 상호배제
    sem_post(&upperBound); // 조건 동기
  }
  return NULL;
}

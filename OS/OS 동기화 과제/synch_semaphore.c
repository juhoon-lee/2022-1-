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
  
  sem_init(&m, 0, 1);
  sem_init(&upperBound, 0, 0);
  sem_init(&lowerBound, 0, 30);
    
  pthread_create(&tid1, NULL, thread_increment, NULL);
  pthread_create(&tid2, NULL, thread_decrement, NULL);

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

/* thread routine */
void * thread_increment (void *arg) {
  int i, val;
  for (i=0; i< ITER ; i++) {
    sem_wait(&upperBound);
    sem_wait(&m);
    val = x;
    printf("%u: %d\n", (unsigned int) pthread_self(), val);
    x = val + 1;
    sem_post(&m);
    sem_post(&lowerBound);
  }
  return NULL;
}

void * thread_decrement (void *arg) {
  int i, val;
  for (i=0; i< ITER ; i++) {
    sem_wait(&lowerBound);
    sem_wait(&m);
    val = x;
    printf("%u: %d\n", (unsigned int) pthread_self(), val);
    x = val - 1;
    sem_post(&m);
    sem_post(&upperBound);
  }
  return NULL;
}

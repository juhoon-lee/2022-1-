/* bad sharing */
#include <pthread.h>
#include <stdio.h>
#define ITER 1000
void *thread_increment(void *arg);
void *thread_decrement(void *arg);
int x;
pthread_mutex_t m; // mutex
pthread_t c;
int main() {
    
  pthread_t tid1, tid2;
  
  pthread_mutex_init(&m, NULL);
  pthread_cond_init(&c, NULL);
    
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
  pthread_mutex_destroy(&m);
}

/* thread routine */
void * thread_increment (void *arg) {
  int i, val;
  for (i=0; i< ITER ; i++) {
    pthread_mutex_lock(&m);
    if (x == 0) {
        pthread_cond_wait(&c, &m);
    }
    val = x;
    printf("%u: %d\n", (unsigned int) pthread_self(), val);
    x = val + 1;
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
  }
  return NULL;
}

void * thread_decrement (void *arg) {
  int i, val;
  for (i=0; i< ITER ; i++) {
    pthread_mutex_lock(&m);
      if (x == -30) {
          pthread_cond_wait(&c, &m);
      }
    val = x;
    printf("%u: %d\n", (unsigned int) pthread_self(), val);
    x = val - 1;
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
  }
  return NULL;
}

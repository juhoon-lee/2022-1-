#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#define NUM 5
#define EAT 100000

sem_t forks[NUM]; // forks
sem_t once;
int threadCount = 0;

void pickup(int philosopher_num){
    sem_wait(&forks[philosopher_num % NUM]);
}

void putdown(int philosopher_num){
    sem_post(&forks[philosopher_num % NUM]);
}

void thinking(int philosopher_num){
    printf("philosopher %d is thinking\n", philosopher_num); return;
}

void eating(int philosopher_num){
    printf("philosopher %d is eating\n", philosopher_num);
    return; }

void *philosopher(void *arg){
    int philosopher_num;
    philosopher_num = (unsigned long int) arg;
    int count = 0;
    
    while(count < EAT){
        sem_wait(&once);
        pickup(philosopher_num);
        printf("philosopher %d picks up the fork %d.\n", philosopher_num, philosopher_num);
        pickup(philosopher_num + 1);
        printf("philosopher %d picks up the fork %d.\n", philosopher_num, (philosopher_num + 1) % NUM);
        sem_post(&once);
        eating(philosopher_num);
        putdown(philosopher_num + 1);
        printf("philosopher %d puts down the fork %d.\n", philosopher_num, (philosopher_num + 1) % NUM);
        putdown(philosopher_num);
        printf("philosopher %d puts down the fork %d.\n", philosopher_num, philosopher_num);
        thinking(philosopher_num);
        count++;
        threadCount++;
    }
    return NULL;
}

int main(){
    pthread_t threads[NUM];
    clock_t start,end;
    double totalTime;
    
    start = clock();
    
    for(int i=0; i<NUM; i++){
        sem_init(&forks[i], 0, 1);
    }
    
    sem_init(& once, 0, 1);
    
    for(unsigned long int i=0; i<NUM; i++){
        pthread_create(&threads[i], NULL, philosopher, (void*)i);
    }
    
    for(int i=0; i<NUM; i++){
        pthread_join(threads[i], NULL);
    }
    end = clock();
    
    totalTime = (double)(end-start)/CLOCKS_PER_SEC;
    
    printf("\n");
    printf("필요한 자원을 모두 한번에 요청했을 때 \n");
    printf("각 철학자가 식사한 횟수: %d \n", EAT);
    printf("모든 철학하자가 식사한 횟수): %d \n",threadCount);
    printf("수행시간: %lf \n",totalTime);
    printf("NO DEADLOCK\n");
    return 0;
}

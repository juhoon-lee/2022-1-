#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM 5
int totalCount = 0; // 10000번씩 5번 돌아가는지 확인하기 위한 변수
sem_t forks[NUM]; // forks
sem_t room;

void pickup(int philosopher_num){
    sem_wait(&forks[philosopher_num % NUM]);
}

void putdown(int philosopher_num){ sem_post(&forks[philosopher_num % NUM]);
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
    while(count < 10000){
        sem_wait(&room);
        pickup(philosopher_num);
        printf("philosopher %d picks up the fork %d.\n", philosopher_num, philosopher_num); pickup(philosopher_num + 1);
        printf("philosopher %d picks up the fork %d.\n", philosopher_num, (philosopher_num + 1) % NUM); eating(philosopher_num);
        putdown(philosopher_num + 1);
        printf("philosopher %d puts down the fork %d.\n", philosopher_num, (philosopher_num + 1) % NUM); putdown(philosopher_num);
        printf("philosopher %d puts down the fork %d.\n", philosopher_num, philosopher_num); sem_post(&room);
        thinking(philosopher_num);
    count++; // 10000번 식사
    totalCount++; // 전역변수에 더
    }
    return NULL;
}

int main(){
    pthread_t threads[NUM];
    clock_t start, end; // 시간 측정
    double taskTime;
    start = clock();

    for(int i=0; i<NUM; i++){
        sem_init(&forks[i], 0, 1);
    }
    sem_init(&room, 0, 4);
    for(unsigned long int i=0; i<NUM; i++){
        pthread_create(&threads[i], NULL, philosopher, (void*)i);
    }
    for(int i=0; i<NUM; i++){
        pthread_join(threads[i], NULL);
    }
    end = clock();// 종료 시

    taskTime = (double)(end-start)/CLOCKS_PER_SEC;
    printf("수행시간은 %lf \n", taskTime);
    printf("총 식사 수는 50000이면 성공 -> %d \n",totalCount);
    printf("NO DEADLOCK\n"); return 0;
}

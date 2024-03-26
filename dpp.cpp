#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define MAX_EAT_COUNT 1  // Reduced eat count for a shorter output

pthread_t philosophers[N];
sem_t forks[N];
sem_t mutex;
int state[N];
int eat_count[N] = {0};  // Initialize eat count for each philosopher

void test(int phil_id);  // Declare the test function

void grab_forks(int phil_id) {
    sem_wait(&mutex);
    state[phil_id] = HUNGRY;
    printf("Philosopher %d is hungry\n", phil_id);
    test(phil_id);
    sem_post(&mutex);
    sem_wait(&forks[phil_id]);
}

void put_forks(int phil_id) {
    sem_wait(&mutex);
    state[phil_id] = THINKING;
    printf("Philosopher %d is thinking\n", phil_id);
    test((phil_id + N - 1) % N);  // Test left neighbor
    test((phil_id + 1) % N);      // Test right neighbor
    sem_post(&mutex);
}

void test(int phil_id) {
    if (state[phil_id] == HUNGRY &&
        state[(phil_id + N - 1) % N] != EATING &&
        state[(phil_id + 1) % N] != EATING) {
        state[phil_id] = EATING;
        printf("Philosopher %d is eating\n", phil_id);
        eat_count[phil_id]++;
        sem_post(&forks[phil_id]);
    }
}

void *philosopher(void *arg) {
    int phil_id = *((int *)arg);

    while (eat_count[phil_id] < MAX_EAT_COUNT) {
        // Thinking
        sleep(1);

        // Grab forks and eat
        grab_forks(phil_id);
        sleep(2);
        put_forks(phil_id);
    }
}

int main() {
    int i, ids[N];
    
    sem_init(&mutex, 0, 1);
    
    for (i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
        ids[i] = i;
    }
    
    for (i = 0; i < N; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }
    
    for (i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }
    
    return 0;
}


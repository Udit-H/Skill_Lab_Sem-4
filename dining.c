#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define N 5

pthread_mutex_t chopstick[N];

void* philosopher(void* num)
{
    int id = *(int*) num;
    printf("philosopher %d is thinking\n", id);
    sleep(1);

    pthread_mutex_lock(&chopstick[id]);
    pthread_mutex_lock(&chopstick[(id+1)%N]);

    printf("Philosopher %d is eating\n", id);
    sleep(2);

    pthread_mutex_unlock(&chopstick[id]);
    pthread_mutex_unlock(&chopstick[(id+1)%N]);

    printf("Philosopher %d finished eaating\n", id);

    return NULL;
}

int main()
{
    pthread_t ph[N];
    int i, id[N];

    for(i=0;i<N;i++)
    pthread_mutex_init(&chopstick[i], NULL);

    for(i=0;i<N;i++)
    {
        id[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &id[i]);
    }

    for(i=0;i<N;i++)
    pthread_join(ph[i], NULL); 

    for(i=0;i<N;i++)
    pthread_mutex_destroy(&chopstick[i]);

    return 0;
}
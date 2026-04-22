#include<stdio.h>
#include<pthread.h>

void* print_numbers(void* arg)
{
    int i;
    for(i=1;i<=5;i++)
    printf("Thread 1 : %d\n", i);
    pthread_exit(NULL);
}

void* print_letters(void* arg)
{
    char ch;
    for(ch='A';ch<='E';ch++)
    printf("Thread 2 : %c\n", ch);
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, print_numbers, NULL);
    pthread_create(&t2, NULL, print_letters, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
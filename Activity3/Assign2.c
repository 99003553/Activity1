#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#define MaxItms 10 
#define BufferSize 10 

sem_t emty;
sem_t full;
int write = 0;
int read = 0;
int itm=0;
int buffer[BufferSize];
void *prod(void *po)
{   
    if(write==BufferSize-1)
    {
        printf("Stack of producer is full,  using circular buffer operations \n");
        for(int j = 0; j < MaxItms; j++) 
        {
          itm = rand();
          sem_wait(&empty);
          buffer[write] = item;
          printf(" Insert Item %d in Producer %d at %d: ", buffer[write], *((int *)po), write);
          write = (write + 1) % BufferSize;     
          sem_post(&full);
        }
    }
    else
    {
     for(int j = 0; j < MaxItms; j++) 
     {
        itm = rand();
        sem_wait(&empty);
        buffer[write] = item;
        printf(" Insert Item %d in Producer %d at %d: ", buffer[write], *((int *)po), write);
        write = (write + 1) % BufferSize;     
        sem_post(&full);
     }
    }
}
void *cons(void *co)
{   
    if(read==BufferSize-1)
    {
        printf("Stack of consumer contains nothing, can't read from it now\n");
    }
    else
    {
     int itm=0;
     for(int j = 0; j < MaxItems; j++) 
     {
        sem_wait(&full);
        itm = buffer[read];
        printf("Remove Item %d from Consumer %d from %d: ", itm, *((int *)co), read); 
        read = (read + 1) % BufferSize;     
        sem_post(&empty);
     }
    }
}
int main()
{   
    pthread_t producer[10],consumer[10];
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int k = 0; k < 10; k++) 
    {
        pthread_create(&producer[k], NULL, (void *)prod, (void *)&a[k]);
    }
    for(int k = 0; k < 10; k++) 
    {
        pthread_create(&consumer[k], NULL, (void *)cons, (void *)&a[k]);
    }
    for(int k = 0; k < 10; k++) 
    {
        pthread_join(producer[k], NULL);
    }
    for(int k = 0; k < 10; k++) 
    {
        pthread_join(consumer[k], NULL);
    }
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}

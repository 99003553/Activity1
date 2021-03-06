#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#define MaxItems 10
#define BufferSize 10

int write = 0;
int read = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;
void *prod(void *po)
{
    int itm;
    for(int j = 0; j < MaxItems; j++) 
    {
        itm = rand();
        pthread_mutex_lock(&mutex);
        if(write==BufferSize-1)
        {
           buffer[write] = itm;
           printf("Insert Item %d at Producer %d in %d: ", buffer[write], *((int *)po),write);
           write = (write + 1) % BufferSize;
        }
        else
        {
           buffer[(write+1)%BufferSize] = itm;
           printf("Insert Item %d at Producer %d in %d: ", buffer[write], *((int *)po),write);
           write = (write + 1) % BufferSize; 
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *cons(void *co)
{
    int itm=0;
    for(int l = 0; l < MaxItems; l++) 
    {
        pthread_mutex_lock(&mutex);
        //while (read == write)
        //{
        itm = buffer[read];
        printf("Remove Item %d at Consumer %d from %d: ", itm, *((int *)co), read);
        read = (read + 1) % BufferSize;
        //}
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t producer[10],consumer[10];
    pthread_mutex_init(&mutex, NULL);
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
    pthread_mutex_destroy(&mutex);
    return 0;
}

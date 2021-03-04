#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include <stdlib.h>
#define MaxItms 10 
#define BufferSize 10 

const int max=10;
//sem_t s1;
//sem_t s2;
int write = 0;
int read = 0;
int itm=0;
int buffer[BufferSize];

void* cons(void* pv)
{
	int i;
	printf("Consumer--welcome\n");
	//sem_wait(&s2);
	//sem_wait(&s1);
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
	//sem_post(&s1);
}
void *prod(void *po)
{   
	int i;
	printf("Producer--welcome\n");
	//sem_wait(&s1);
        if(write==BufferSize-1)
        {
          printf("Stack of producer is full, can't write to it now \n");
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
	//sem_post(&s1);
	//sem_post(&s2);
}
int main()
{
	//pthread_t pt1,pt2;	//thread handle
	pthread_t producer[10],consumer[10];
        sem_init(&empty,0,BufferSize);
        sem_init(&full,0,0);
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
	//sem_init(&s1,0,1);
	//sem_init(&s2,0,0);
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
	//pthread_create(&pt1,NULL,tentry_fun1,NULL);
	//pthread_create(&pt2,NULL,tentry_fun2,NULL);
	//pthread_join(pt1,NULL);
	//pthread_join(pt2,NULL);
	//sem_destroy(&s1);
	//sem_destroy(&s2);
	//printf("main--thank you\n");
	//return 0;	//exit(0);
	 //pthread_t producer[10],consumer[10];
        sem_destroy(&empty);
        sem_destroy(&full);
        return 0;
}

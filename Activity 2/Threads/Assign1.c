#include <stdio.h> 
#include <pthread.h> 

#define MAX 20 
#define MAX_THREAD 5
int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220, 250, 280, 320, 350 }; 
int sum[5] = { 0 }; 
int pt = 0; 
void* tsum(void* arg) // Each thread computes sum of 1/5th of array 
{ 
    int thread_pt = pt++; 
    for (int j = thread_pt * (MAX / 5); j < (thread_pt + 1) * (MAX / 5); j++) 
        sum[thread_pt] += a[j]; 
} 
int main() 
{ 
    int total = 0;
    pthread_t threads[MAX_THREAD]; 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i], NULL, tsum, (void*)NULL); 
    for (int k = 0; k < MAX_THREAD; k++) 
        pthread_join(threads[k], NULL);   
    for (int l = 0; l < MAX_THREAD; l++) 
        total += sum[l]; 
    printf("sum of array is %d ", total); 
    return 0; 
} 

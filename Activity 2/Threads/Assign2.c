#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#define max 20
#define Tmax 5

int a[max] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 300, 64, 110, 220,250,280,320,350 }; 
int max_num[Tmax] = { 0 }; 
int min_num[Tmax] = { 0 };
int threadno = 0; 
void maximini(void* arg) 
{ 
    int i, num = threadno++; 
    int maxi = 0, mini = 0; 
    for (i = num * (max / 5); i < (num + 1) * (max / 5); i++) 
    { 
        if (a[i] > maxi) 
            maxi = a[i]; 
        if (a[i] < maxi)
            mini = a[i]    
    } 
    max_num[num] = maxi; 
    min_num[num] = mini;
} 

int main() 
{ 
    int maxin = 0, minim = 0; 
    int j; 
    pthread_t threads[Tmax];  
    for (j = 0; j < Tmax; j++) 
        pthread_create(&threads[j], NULL, 
                       maximini, (void*)NULL); 
    for (j = 0; j < Tmax; j++) 
        pthread_join(threads[j], NULL);  
    for (j = 0; j < Th_max; j++) 
    { 
        if (max_num[j] > maxin) 
            maxin = max_num[j];
        if (min_num[j] < minim)
            minim = min_num[j]; 
    } 
    printf("Maximum Element is : %d", maxin); 
    printf("Minimum Element is : %d", minim);
    return 0; 
} 

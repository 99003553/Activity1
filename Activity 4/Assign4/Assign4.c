#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>

void main() 
{
    int k;
    k = mkfifo("pipe1",0666);
    if(k<0)
        printf("\npipe1 was not created");
    else
        printf("\npipe1 created");
    int l;
    l = mkfifo("pipe2",0666);
    if(l<0)
        printf("\npipe2 was not created");
    else
        printf("\npipe2 is created\n");
}

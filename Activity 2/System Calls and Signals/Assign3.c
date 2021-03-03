#include <signal.h>
#include <sys/types.h> 
#include <unistd.h>  
#include <stdio.h> 
#include <stdlib.h> 

void signalsup(); 
void signalsquit(); 
void signalsint(); 

void main() 
{ 
    int p; 
    if ((p = fork()) < 0)
     { 
        perror("fork"); 
        exit(1); 
    } 
    if (p == 0) { /* child */
        signal(SIGHUP, signalsup); 
        signal(SIGINT, signalsint); 
        signal(SIGQUIT, signalsquit); 
        for (;;) 
            ; 
    } 
    else // parent 
    { // pid hold id of child 
        printf("\nPARENT: sending the SIGHUP\n\n"); 
        kill(p, SIGHUP); 
  	sleep(3);
        printf("\nPARENT: sending the SIGINT\n\n"); 
        kill(p, SIGINT); 
  	sleep(3); 
        printf("\nPARENT: sending the SIGQUIT\n\n"); 
        kill(p, SIGQUIT); 
        sleep(3); 
    } 
}  
void signalsup() 
{ 
    signal(SIGHUP, signalsup); 
    printf("CHILD:  received a SIGHUP\n"); 
} 
void signalsint() 
{ 
    signal(SIGINT, signalsint); 
    printf("CHILD:  received a SIGINT\n"); 
} 
void signalsquit() 
{ 
    printf("Child process is killed!!!\n"); 
    exit(0); 
} 

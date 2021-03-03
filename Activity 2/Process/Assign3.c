#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
	int ret,stat,ret1,ret2;
	printf("welcome, current process id: %d\n",getpid());
	ret=fork();
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{
	char str[20];
  char str1[20];
	int l,k;
  scanf("%s",str);
  l=execl("/usr/bin/pwd",str,NULL);
	if(l<0)
	{
		perror("execl");
		exit(1);
	}
  scanf("%s",str1);
  k=execl("/usr/bin/pwd",str1,NULL);
	if(k<0)
	{
		perror("execl");
		exit(1);
	}  
        exit(5);
	}
	else	
	{
		printf("parent--hello,pid=%d,ppid=%d\n",getpid(),getppid());
		waitpid(-1,&status,0); 
		printf("parent--child exit status=%d\n",WEXITSTATUS(status));
    int ret1=fork();
	  printf("another child process for linking,pid=%d,ppid=%d, ret =%d\n", getpid(),getppid(),ret1);
    int ret2=fork();
	  printf("another child process for executing,pid=%d,ppid=%d, ret =%d\n", getpid(),getppid(),ret2);
	}
	return 0;
}

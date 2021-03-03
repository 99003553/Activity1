#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
	int ret,stat;
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
	int l;
        scanf("%s",str);
        l=execl("/usr/bin/pwd",str,NULL);
	if(l<0)
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
	}
	return 0;
}

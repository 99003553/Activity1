#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int ret,nbytes1;
	struct mq_attr attr;
	attr.mq_msgsize=500;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	mqid=mq_open("/mque1",O_RDONLY|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf1[7000];
	int mxlen=500,prio;
	nbytes1=mq_receive(mqid,buf1,mxlen,&prio);
	if(nbytes1<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf1[nbytes1]='\0';
	int k;
    printf("%s",buf1);
	k =execlp("/bin/gcc","gcc",buf1,0);
    if(k<0)
		{
			perror("execlp");
			exit(1);
		}
		exit(5);
		
	printf("receive msg:%s,nbytes=%d,prio=%d\n",buf1,nbytes1,prio);
	mq_close(mqid);
	return 0;
}

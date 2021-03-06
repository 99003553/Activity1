#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int ret;
	mqd_t mqid;
	struct mq_attr attr;
	attr.mq_msgsize=500;
	attr.mq_maxmsg=10;
	mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char str[]="Hello World";
	int ln=strlen(str);
	ret=mq_send(mqid,str,ln+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	struct mq_attr attr1;
	attr1.mq_msgsize=500;
	attr1.mq_maxmsg=10;
	mqd_t mqid1;
	mqid1=mq_open("/mque2",O_RDONLY|O_CREAT,0666,&attr1);
	if(mqid1<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf[7000];
	int mxlen=500,prio;
	int nbytes=mq_receive(mqid1,buf,mxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	printf("receive msg from receiver :%s,nbytes=%d,prio=%d\n",buf,nbytes,prio);
	mq_close(mqid);
	mq_close(mqid);
	return 0;
}


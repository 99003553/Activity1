#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int ret,mbytes;
	struct mq_attr attr;
	attr.mq_msgsize=500;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	mqid=mq_open("/mque",O_RDONLY|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf[7000];
	int maxlen=500,prio;
	mbytes=mq_receive(mqid,buf,maxlen,&prio);
	if(mbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[mbytes]='\0';
	printf("receive msg from sender:%s,nbytes=%d,prio=%d\n",buf,mbytes,prio);
	mqd_t mqid1;
	struct mq_attr attr1;
	attr1.mq_msgsize=256;
	attr1.mq_maxmsg=20;
	mqid1=mq_open("/mque2",O_WRONLY|O_CREAT,0666,&attr1);
	for(int counter=0;buf[counter]!=NULL;counter++)
    {
        if(buf[counter]>='A' && buf[counter]<='Z')
            buf[counter]=buf[counter]+32;
        else if(buf[counter]>='a' && buf[counter]<='z')
            buf[counter]=buf[counter]-32;
    }
	ret=mq_send(mqid1,buf,mbytes+1,2);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqid);
	mq_close(mqid1);
	return 0;
}

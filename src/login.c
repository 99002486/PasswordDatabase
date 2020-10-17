#include "login.h"

int* login(void* pv)
{
    printf("Entered the login function \n");
    int send,recv;
    char user[50], pass[30];
    mqd_t mqid;
    struct mq_attr attr;
	attr.mq_msgsize=1024;
	attr.mq_maxmsg=2;
	mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,&attr);
    if(mqid<0) 
    {
		perror("mq_open");
		exit(1);
	}
    printf("Enter Username: \n");
    scanf("%s",&user);
    printf("Enter Password: \n");
    scanf("%s",&pass);
    send=mq_send(mqid,user,len+1,10);
    send=mq_send(mqid,pass,len+1,5);
    if(send<0)
	{
		perror("mq_send");
		exit(2);
	}
    sem_post(&s1);
    sem_wait(&s2);
    char buff[8192];
    int prio,maxlen=2048;
    recv=mq_receive(mqid,buff,maxlen,&prio);
    if(recv<0)
    {
        perror("mq_recv");
        exit(3)
    }
    buff[recv]='\0';
    printf("Available Login Credentials: %s",buff);
    mq_close(mqid);
    return 0;
}

#include"database.h"

void* database_function(void* ps)
{
    sem_t *s= ps;
    char username1="user@user1.com";
    char password1="123456789";
    int ret,msg_length;
    char account_password[]="gmail = mdhsaudn\n yahoo = bhsjavhdjsa \nreddit = 78byg8egwgqweg\n";
    int send_message_length=strlen(account_password);
    char no_access="Username/password is not valid";
    mqd_t mqid;
    mqid=mq_open("/mque",O_WRONLY,0666,NULL);
    if(mqid<0)
    {
        perror("mq_open");
        exit(1);
    }
    sem_wait(s);
    char user[8192],password[8192];
    int maxlen=1024,prio;
    msg_length=mq_receive(mqid,user,maxlen,&prio);
    if(msg_length<0)
    {
        perror("mq_recv");
        exit(2);
    }
    msg_length=mq_receive(mqid,password,maxlen,&prio);
    if(msg_length<0)
    {
        perror("mq_recv");
        exit(2);
    }
    if(user==username1 && password==password1)
    {
        ret=mq_send(mqid,account_password,maxlen,10);
        if(ret<0)
	    {
		    perror("mq_send");
		    exit(3);
	    }
    }
    else
    {
        ret=mq_send(mqid,no_access,maxlen,10);
        if(ret<0)
	    {
		    perror("mq_send");
		    exit(3);
	    }
    }
    sem_post(s+1);
    mq_close(mqid);


}

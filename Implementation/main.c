#include<stdio.h>
#include"login.h"
#include"database.h"

sem_t s[2];

int main()
{
    pthread_t th1,th2;
    sem_init(s,0,0);
    sem_init(s+1,0,0);
    pthread_create(&th1,NULL,database_function,(void *)s);
    pthread_create(&th2,NULL,login,(void *)s);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    sem_destroy(s);
    sem_destroy(s+1);
    printf("Exiting program...");
    return 0;
}

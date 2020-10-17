#include<stdio.h>
#include"login.h"
#include"database.h"

sem_t s1,s2;

int main()
{
    pthread_t th1,th2;
    sem_init(&s1,0,0);
    sem_init(&s2,0,0);
    pthread_create(&th1,NULL,database_function,NULL);
    pthread_create(&th2,NULL,login),NULL);
    pthread_join(th1,NULL);
    pthread_join(pt2,NULL);
    sem_destroy(&s1);
    sem_destroy(&s2);
    printf("Exiting program...");
    return 0;
}

#ifndef __DATABASE_H_
#define __DATABASE_H_

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<mqueue.h>
#include<fcntl.h>
#include<string.h>

void* database_function(void* ps);

#endif
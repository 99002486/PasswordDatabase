#ifndef __LOGIN_H__
#define __LOGIN_H__

#include<semaphore.h>
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void* login(void* pv);
#endif

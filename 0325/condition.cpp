/*************************************************************************
	> File Name: condition.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Wed 25 Mar 2015 08:35:28 PM CST
 ************************************************************************/

#include<assert.h>
#include "condition.h"
#include "mutex.h"

Condition::Condition(MutexLock &mutex):mutex_(mutex)
{
pthread_cond_init(&cond_, NULL);
}
Condition::~Condition()
{
pthread_cond_destroy(&cond_);
}
void Condition::wait()
{
//assert(mutex_.isLocking());
pthread_cond_wait(&cond_, mutex_.mutexptr());
}

void Condition::notify()
{
pthread_cond_signal(&cond_);
}

void Condition::notifyAll()
{
pthread_cond_broadcast(&cond_);
}




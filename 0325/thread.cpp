/*************************************************************************
	> File Name: thread.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Thu 26 Mar 2015 10:01:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<assert.h>
#include "thread.h"

Thread::~Thread()
{
assert(isRunning_);
pthread_detach(pthid_);
}
void Thread::start()
{
assert(!isRunning_);
pthread_create(&pthid_, NULL, runInThread, this);
isRunning_ = true;

}
void Thread::join()
{
assert(isRunning_);
pthread_join(pthid_, NULL);
isRunning_ = false;
}

void* Thread::runInThread(void* arg)
{
Thread* pt = static_cast<Thread*>(arg);
pt->run();
return NULL;
}

pthread_t Thread::thread_id() const
{
return pthid_;

}






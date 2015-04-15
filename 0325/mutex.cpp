/*************************************************************************
	> File Name: mutex.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Thu 26 Mar 2015 10:26:26 PM CST
 ************************************************************************/

#include "mutex.h"
#include<assert.h>

MutexLock::MutexLock():isLocking_(false)
{
pthread_mutex_init(&mutex_, NULL);
}
void MutexLock::lock()
{
//assert(!isLocking_);
pthread_mutex_lock(&mutex_);
isLocking_ = true;
}
void MutexLock::unlock()
{
//assert(isLocking_);
pthread_mutex_unlock(&mutex_);
isLocking_ = false;
}
MutexLock::~MutexLock()
{
pthread_mutex_destroy(&mutex_);

}
bool MutexLock::isLocking() const
{
return isLocking_;

}
pthread_mutex_t* MutexLock::mutexptr()
{
return &mutex_;
}


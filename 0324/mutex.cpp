/*************************************************************************
	> File Name: mutex.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Tue 24 Mar 2015 10:39:20 PM CST
 ************************************************************************/

#include "mutex.h"

MutexLock::MutexLock(): isLocking_(false)
{
pthread_mutex_init(&mutex_, NULL);

}
void MutexLock::lock()
{
assert(!isLocking);
pthread_mutex_lock(&mutex_);
isLocking_ = true;

}
void MutexLock::unlock()
{
assert(isLocking);
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
pthread_mutex_t* mutexptr()
{
return &mutex_;
}


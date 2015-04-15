/*************************************************************************
	> File Name: Condition.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Sat 28 Mar 2015 09:22:12 PM CST
 ************************************************************************/

#include "Condition.h"
#include "MutexLock.h"
#include<assert.h>

namespace Tiny
{
	Condition::Condition(MutexLock &mutex)
		:mutex_(mutex)
	{
	TINY_CHECK(!pthread_cond_init(&cond_, NULL));
	}
	Condition::~Condition()
	{
	TINY_CHECK(!pthread_cond_destroy(&cond_));
	}

	void Condition::wait()
	{
	assert(mutex_.isLocking());//wait前必须上锁
	TINY_CHECK(!pthread_cond_wait(&cond_, mutex_.getMutexPtr()));
	mutex_.restoreMutexStatus(); //还原状态
	}
	void Condition::notify()
	{
	TINY_CHECK(!pthread_cond_signal(&cond_));
	}
	void Condition::notifyAll()
	{
	TINY_CHECK(!pthread_cond_broadcast(&cond_));
	
	}

}




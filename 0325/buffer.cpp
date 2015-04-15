/*************************************************************************
	> File Name: buffer.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Wed 25 Mar 2015 10:01:21 PM CST
 ************************************************************************/

#include "buffer.h"

Buffer::Buffer(std::size_t sz): mutex_(), notEmpty_(mutex_), notFull_(mutex_), size_(sz) 
{}

void Buffer::push(int ival)
{
mutex_.lock();
while(queue_.size() >= size_)
{
notFull_.wait();
}
queue_.push(ival);
mutex_.unlock();

notEmpty_.notify();
}

int Buffer::pop()
{
mutex_.lock();
while(queue_.size() <= 0)
{
notEmpty_.wait();
}
int temp = queue_.front();
queue_.pop();
notFull_.notify();

mutex_.unlock();
return temp;

}

bool Buffer::empty() const
{
mutex_.lock();
bool temp = queue_.empty();
mutex_.unlock();
return temp;
}

bool Buffer::full() const
{
mutex_.lock();
bool temp = (queue_.size() >= size_);
mutex_.unlock();
return temp;
}

std::size_t Buffer::size() const
{
mutex_.lock();
int temp = queue_.size();
mutex_.unlock();
return temp;
}




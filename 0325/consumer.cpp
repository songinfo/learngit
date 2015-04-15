/*************************************************************************
	> File Name: consumer.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Wed 25 Mar 2015 10:22:36 PM CST
 ************************************************************************/

#include "consumer.h"
#include "buffer.h"
#include<unistd.h>

Consumer::Consumer(Buffer &buffer) : buffer_(buffer)
{}
void Consumer::run()
{
while(1)
{
	std::size_t num = buffer_.pop();
	std::cout << "pop a No. " << num
		      << ", size = " << buffer_.size()
			  << std::endl;
	sleep(5);
}
}



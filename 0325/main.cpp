/*************************************************************************
	> File Name: main.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Wed 25 Mar 2015 11:01:49 PM CST
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include "thread.h"
#include "workshop.h"

class MyThread : public Thread
{
public:
	void run()
	{
	while(1)
	{
		std::cout << "mythread is running "
			<< std::endl;
		sleep(3);
	}
	}
};

int test0(void)
{
MyThread myth;
myth.start();
myth.join();

return 0;
}

int main(void)
{
Workshop shop(5, 100, 150);
shop.startWorking();

return 0;
}

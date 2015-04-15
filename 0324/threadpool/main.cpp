/*************************************************************************
	> File Name: main.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Tue 24 Mar 2015 10:48:20 PM CST
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include "thread.h"

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

int main(void)
{
MyThread myth;
myth.start();
myth.join();

return 0;
}



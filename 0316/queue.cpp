/*************************************************************************
  > File Name: queue.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Mon 16 Mar 2015 04:53:42 PM CST
 ************************************************************************/

#include<iostream>
#include <queue>

int main()
{
	int i = 0;
	std::queue<int> v;
	for (i = 0; i < 10; i++)
	{
		v.push(i);	//把元素一个一个存入到queue中
		std::cout << v.back() << " 已入队列" << std::endl;

	}
	std::cout << "现在queue的容量: " << v.size() << std::endl << std::endl;
	for (i = 0; i < 10; i++)
	{
		std::cout << v.front() << " 准备出队列" << std::endl;
		v.pop();//把元素一个一个出栈
	}
	std::cout << "现在queue的容量: " << v.size() << std::endl << std::endl;

	
	return 0;
}





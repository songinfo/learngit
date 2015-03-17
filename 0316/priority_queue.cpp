/*************************************************************************
  > File Name: priority_queue.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Mon 16 Mar 2015 04:57:45 PM CST
 ************************************************************************/


#include <iostream>
#include <queue>

//priority_queue允许对存储的元素设置优先级。
//优先级队列的一个实例是机场行李检查队列。30分钟后即将离港的航班的乘客通常会设置高的优先级别。
//优先队列的例子如下：
int main()
{
	int i = 0;
	int array[10] = {0, 1, 3, 2, 5, 6, 9, 8, 7, 4};
	std::priority_queue < int > v;
	for (i = 0; i < 10; i++)
	{
		v.push(array[i]);	//把元素一个一个存入到priority_queue中,并且在内部进行排序
		std::cout << v.top() << " 是目前这个队列中优先级别最高的" << std::endl;

	}
	std::cout << "现在priority_queue的容量:" << v.size() << std::endl << std::endl;

	for (i = 0; i < 10; i++)
	{
		std::cout << v.top() << "准备出队列" << std::endl;
		v.pop();//把元素一个一个出栈
	}
	std::cout << "现在priority_queue的容量:" << v.size() << std::endl << std::endl;

	
	return 0;
}


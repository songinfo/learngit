/*************************************************************************
  > File Name: not1.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Mon 16 Mar 2015 04:14:16 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include <iostream>
#include <algorithm> //使用for_each算法要包含的头文件	
#include <functional> //使用less<>类模板要用的头文件
#include <vector>


int main()
{
	int sz[] = {1, 2, 3, 4, 5, 6};
	std::vector<int> ob(sz, sz + 6);
	std::less< int > lt; //创建less<int>类函数对象
	replace_if(ob.begin(), ob.end(), not1(bind2nd(lt, 3)), 7);	//1 2 7 7 7 7

	std::vector<int>::const_iterator it = ob.begin();

	for (it = ob.begin();it != ob.end();it++)
	{
		std::cout << (*it) << "  ";
	}
	std::cout << std::endl;

//	getchar();
	return 0;
}





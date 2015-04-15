/*************************************************************************
	> File Name: bind.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Sat 21 Mar 2015 03:21:49 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>

int func(int x, int y)
{
	std::cout << "x = " << x << ", y = " << y << std::endl;
	return x > y ? x : y;
}

class A 
{
public:
	int func(int x, int y)
	{
	std::cout << "x = " << x << ", y = " << y << std::endl;
	return x < y ? x : y;
	
	}

};

int func2(int n1, int n2, int n3, const int &n4, int n5)
{
std::cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << std::endl;
}

int main(void)
{
using namespace std::placeholders;
auto f1 = std::bind(func, 10, _1);
std::cout << f1(20) << std::endl;

std::cout << std::endl;
A a;
auto f2 = std::bind(&A::func, a, _2, _1);
std::cout << f2(10, 20) << std::endl;
std::cout << std::endl;

#if 1
auto f3 = std::bind(&A::func, a, _1, 100);
std::cout << f3(110) << std::endl;
std::cout << std::endl;

int n = 3;
int &ref4 = n;
auto f4 = std::bind(func2, _2, _1, 42, ref4, n);
f4(1, 2, 1001);
#endif

return 0;
}



/*************************************************************************
	> File Name: rl_value.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Wed 18 Mar 2015 10:02:12 PM CST
 ************************************************************************/
//reviw: RAII
#include<iostream>
class student
{};
int test0(void)
{
student *ps = new student;
//  ....//发生异常，程序退出

delete ps;
return 0;
}

int test1(void)
{
	int ia = 10;//ia 为非常量左值；
	int &refa = ia;//refa为非常量引用

	const int ib = 20;// ib 为常量左值 
	//int &refb = ib; //refb为非常量左值引用 error；
}

int main(void)
{
	//右值引用
	int &&rref = 10;// 字面值 10 的类型为int，不是 const int；
	std::cout << rref <<std::endl;

	const int ia = 20;
//	const int &&rrefa = ia;

}




/*************************************************************************
  > File Name: multiherit1.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Thu 19 Mar 2015 12:33:44 AM CST
 ************************************************************************/

#include<iostream>

class A
{
	public:
		void print() const
		{
			std::cout << "Hello, this is A " << std::endl;
		}
};

class B
{
	public:
		void print() const
		{
			std::cout << "Hello, this is B" << std::endl;
		}
};

class C : public A, public B
{
	public:
		void print()const 
		{
			//A::print();
			std::cout << "Hello, this is C" << std::endl;
		}
};

int main(void)
{
	C c;
	c.A::print();//解除二义性
	c.B::print();
	c.print();//成员函数的覆盖

	return 0;
}




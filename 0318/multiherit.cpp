/*************************************************************************
  > File Name: multiherit.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Thu 19 Mar 2015 12:28:53 AM CST
 ************************************************************************/

#include<iostream>
#include <iostream>

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
		void show() const
		{
			std::cout << "Hello, this is B" << std::endl;
		}
};

class C : public A, public B
{
	public:
		void disp()const 
		{
			std::cout << "Hello, this is C" << std::endl;
			show();
		}
};

int main(void)
{
	C c;
	c.print();
	c.show();
	c.disp();

	return 0;
}



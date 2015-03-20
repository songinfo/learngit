/*************************************************************************
	> File Name: virtual_ambiguous.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 20 Mar 2015 05:03:54 PM CST
 ************************************************************************/

#include<iostream>
class A
{
public:
	virtual void a()
	{
		std::cout << "a() in A " << std::endl;
	}
	virtual void b()
	{
		std::cout << "b() in A " << std::endl;
	}
	virtual void c()
	{
		std::cout << "c() in A " << std::endl;
	}


};

class B
{
public:

	virtual void a()
	{
		std::cout << "a() in B " << std::endl;
	}
	virtual void b()
	{
		std::cout << "b() in B " << std::endl;
	}
	void c()
	{
		std::cout << "c() in B "<< std::endl;
	}
	void d()
	{
		std::cout << "d() in B "<< std::endl;
	}
};

class C :public A, public B
{
public:
	virtual void a()
	{
		std::cout << "a() in C " << std::endl;
	}
	/*
	virtual void b()
	{
		std::cout << "b() in C " << std::endl;
	}
	*/
	void c()
	{
		std::cout << "c() in C "<< std::endl;
	}
	void d()
	{
		std::cout << "d() in C "<< std::endl;
	}
};

int main(void)
{

	std::cout << "sizeof(C) = " << sizeof(C) << std::endl;
C c;
//c.b(); 虚表；二义性；

A* pA = &c;
pA->a();
pA->b();
pA->c();

std::cout <<  std::endl;

B* pB = &c;
pB->a();
pB->b();
pB->c();

std::cout <<  std::endl;
C* pC = &c;
pC->a();
//pC->b();//二义性
pC->c();

return 0;
}

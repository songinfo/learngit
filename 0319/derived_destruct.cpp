/*************************************************************************
	> File Name: derived_destruct.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Thu 19 Mar 2015 09:43:50 PM CST
 ************************************************************************/

#include<iostream>

class A
{
public:
	A(int xp):ix_(xp)
	{
		std::cout << "A的构造函数被执行" << std::endl;
	}
	~A()
	{
		std::cout << "A的析构函数被执行" << std::endl;
	}
private:
	int ix_;
};

class B
{
public:
	B(int i)
	{
		std::cout << "B的构造函数被执行" << std::endl;
	}
	~B()
	{
		std::cout << "B的析构函数被执行" << std::endl;
	}

};
class C : public A
{
public:
	C(int xp, int yp):b(yp),A(xp)
	{
		std::cout << "C的构造函数被执行" << std::endl;
	}
	~C()
	{
		std::cout << "c的析构函数被执行" << std::endl;
	}
private:
	int iy_;
	 B b;
};

int main(void)
{
C c(1, 2);

return 0;
}




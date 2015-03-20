/*************************************************************************
	> File Name: virtual.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 20 Mar 2015 10:55:12 AM CST
 ************************************************************************/

#include<iostream>
class A 
{
public:
A()
{

}
virtual void func1()
{
	std::cout << "A::this is func1()" << std::endl;
}
 void func2()
{
	std::cout << "A::this is func2()" << std::endl;

}

};

int main(void)
{
	A obj1;

	std::cout << "sizeof(A) = " << sizeof(A) << std::endl;
return 0;
}




/*************************************************************************
	> File Name: oversee.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Thu 19 Mar 2015 11:14:20 PM CST
 ************************************************************************/

#include<iostream>
class Base
{
public:
	void func(int i)
	{
		std::cout << "Base func(int i) " << std::endl;
		//return ix_;
	}
protected:
	int ix_;
};
class Derived : public Base
{
public:
	int ix_;
	int func()
	{
		std::cout << "Derived func()" << std::endl;
		ix_ = 9;
		Base::ix_ = 22;
		return ix_;
	}

};
int main(void)
{
Derived obj;
obj.func();
//obj.func(3); // 父类的func函数被子类隐藏了
obj.Base::func(3); //只能通过作用域的方式进行显式调用
}



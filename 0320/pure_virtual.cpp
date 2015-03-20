/*************************************************************************
  > File Name: pure_virtual.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Fri 20 Mar 2015 11:23:47 AM CST
 ************************************************************************/

#include<iostream>

class A						//类A定义
{
public:
		virtual void disp() = 0;//纯虚函数，类A作为抽象类
};

class B : public A			//B由抽象类A派生而来
{
public:
	virtual void disp()		//此处virtual可省略，继承
	{
		std::cout << "This is from B" << std::endl;
	}
};

class C: public B			//类C从类B派生而来
{
public:
	virtual void disp()
	{
		std::cout << "This is from C" << std::endl;
	}
};

void display(A *a)			//display函数，以A类指针对参数
{
	a->disp();
}

int main()
{
	B *pB = new B;			//正确。但如果删除B类中disp()的定义就会编译出错, 因为删除后，B就还包含纯虚函数。
	
	
	C *pC = new C;

   display(pB);
   display(pC);

   return 0;
}

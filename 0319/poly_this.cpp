/*************************************************************************
  > File Name: poil.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Thu 19 Mar 2015 11:45:02 PM CST
 ************************************************************************/

#include<iostream>


class Base
{
	public:
		virtual void disp()
		{
			std::cout << "hello, Base" << std::endl;
		}

		void call_base1()
		{
			this->disp();
		}
		void call_base2()
		{
			disp();
		}
};

class Child : public Base
{
	public:
		void disp()
		{
			std::cout << "Hello, child" << std::endl;
		}

		void call_child1()
		{
			disp();
		}
};

int main(void)
{
	Base obj_base;
	Child obj_child;
	obj_base.call_base1();
	obj_child.call_child1();

	std::cout << std::endl;

	Base *pbase = &obj_child;
	pbase->call_base1();
	pbase->call_base2();

	std::cout << std::endl;

	pbase = &obj_child;
	pbase->call_base1();
	pbase->call_base2();


	return 0;

}


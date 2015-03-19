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

		void disp(int i)
		{
			std::cout << "disp(int) " << std::endl;
		}
		void print()
		{
			std::cout << "base::print()" << std::endl;
		}
};

class Child : public Base
{
	public:
		void disp()
		{
			std::cout << "Hello, child" << std::endl;
		}

		void print()
		{
			std::cout << "child::print()" << std::endl;
		}

};
#if 0
int main(void)
{

	Child obj_child;
	Base* pbase = &obj_child;
	((Child*)pbase)->print();

	Child* pchild = &obj_child;
	pchild->print();

}
#endif

#if 0
int main(void)
{
	Base obj_base;
	Base &refbase = obj_base;
	refbase.disp();

	Child obj_child;
	Child &refchild = obj_child;
	refchild.disp();

	std::cout << std::endl;
	refbase = obj_child;
	refbase.disp();

	std::cout << std::endl;
	//refchild = obj_base; //error；编译失败//基类对象向下转
	//refchild.disp();
	return 0;

}
#endif
#if 0
int main(void)
{
	Base obj_base;
	Base *pbase = &obj_base;
	pbase->disp();

	Child obj_child;
	Child *pchild = &obj_child;
	pchild->disp();

	std::cout << std::endl;

	pbase = pchild;//将子类指针赋值给父类指针
	pbase->disp();//父类指针指向子类对象，并调用虚函数时，
	//所调的函数是子类的虚函数

	std::cout << std::endl;
	pchild = (Child *)&obj_base;
	pchild->disp();


	std::cout << std::endl;

}
#endif
int main(void)
{
	Base  obj_base;
	Child obj_child;
	obj_base.disp();
	obj_child.disp();

	std::cout << std::endl;

	obj_base = obj_child;
	obj_base.disp();

	std::cout << std::endl;
	obj_child.Base::disp();
	obj_child.Child::disp();


	return 0;

}





/*************************************************************************
  > File Name: poly_construct.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Fri 20 Mar 2015 10:08:15 AM CST
 ************************************************************************/

#include<iostream>

class Base0
{
	public:
		Base0(){}
		virtual void func1()
		{
			std::cout <<"this is base0 func1()"<< std::endl;
		}
		virtual void func2()
		{
			std::cout << "this is base0 func2()" << std::endl;
		}
		~Base0()
		{
			std::cout << "desconstruct Base0" << std::endl;
		}
};
class Base1 : public Base0
{
	public:
		Base1()
		{
			func1();
		}
		virtual void func1()    //没有重写覆盖该虚函数，则调用父类Base0中的func1()方法
			{
				std::cout << "this is base1 func1()" << std::endl;
				std::cout <<  std::endl;
			}
			virtual void func2()
			{
				std::cout << "this is base1 func2()" << std::endl;
			}
		~Base1()
		{
			func2();
			std::cout << "desconstruct Base1" << std::endl;
			std::cout <<  std::endl;
		}
};
class Subclass : public Base1
{
	public:
		Subclass()
		{
			func1();
			std::cout << "this is subclass func1()" << std::endl;
		}
		virtual void func1()   //始终不会被调用
		{
			std::cout << "this is subclass func1()" << std::endl;
			std::cout <<  std::endl;
		}
		virtual void func2()   //始终不会被调用
		{
			std::cout << "this is subclass func2()" << std::endl;
		}
		~Subclass()
		{

			std::cout << "desconstruct subclass" << std::endl;
			std::cout <<  std::endl;
		}
};
int  main()
{
	Subclass sc;
}

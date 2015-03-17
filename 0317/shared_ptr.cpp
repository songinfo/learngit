/*************************************************************************
  > File Name: shared_ptr.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Tue 17 Mar 2015 11:25:20 PM CST
 ************************************************************************/

#include<iostream>

#include <memory>

class Child;

class Parent
{
	public:
		Parent() 
		{   std::cout << "Parent..." << std::endl;  }

		~Parent()
		{   std::cout << "~Parent..." << std::endl; }
		std::shared_ptr<Child> child_;
};

class Child
{
	public:
		Child()
		{   std::cout << "Child..." << std::endl;   }

		~Child()
		{   std::cout << "~Child..." << std::endl;  }
		std::shared_ptr<Parent> parent_;
};

int main(void)
{

	std::shared_ptr<Parent> parent(new Parent);
	std::cout << "parent's ref count = " 
		<< parent.use_count() << std::endl;
	std::shared_ptr<Child> child(new Child);
	std::cout << "child's ref count = " 
		<< child.use_count() << std::endl;

	parent->child_ = child;
	child->parent_ = parent;

	std::cout << "parent's ref count = " 
		<< parent.use_count() << std::endl;
	std::cout << "child's ref count = " 
		<< child.use_count() << std::endl;
	return 0;
}




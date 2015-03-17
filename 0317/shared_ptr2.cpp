/*************************************************************************
  > File Name: shared_ptr2.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Tue 17 Mar 2015 11:42:05 PM CST
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
		std::weak_ptr<Parent> parent_;
};

int main(void)
{

	std::shared_ptr<Parent> parent(new Parent);
	std::cout << "parent's ref count = " 
		<< parent.use_count() << std::endl;
	std::shared_ptr<Child> child(new Child);
	std::cout << "child's ref count = " 
		<< child.use_count() << std::endl;

	std::cout << std::endl;
	parent->child_ = child;
	std::cout << "child's ref count = " 
		<< child.use_count() << std::endl;
	child->parent_ = parent;

	std::cout << "parent's ref count = " 
		<< parent.use_count() << std::endl;
	return 0;
}




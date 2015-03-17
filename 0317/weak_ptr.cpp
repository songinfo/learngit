/*************************************************************************
  > File Name: weak_ptr.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Tue 17 Mar 2015 11:50:46 PM CST
 ************************************************************************/

#include<iostream>
#include <memory>

class X
{
	public:
		X()
		{   std::cout << "construct X" << std::endl;    }
		~X()
		{   std::cout << "~destruct X" << std::endl;    }

		void fun()
		{   std::cout << "fun() " << std::endl; }
};

int main(void)
{
	std::weak_ptr<X> p;
	{
		std::shared_ptr<X> p2(new X);
		std::cout << "p2's use_count = "
			<< p2.use_count() << std::endl;
		p = p2;
		std::cout << "after p = p2" << std::endl;
		std::cout << "p2's use_count = "
			<< p2.use_count() << std::endl;

		std::shared_ptr<X> p3 = p.lock();
		if(!p3)
		{
			std::cout << "object is destroyed!" << std::endl;
		}
		else
		{
			p3->fun();
			std::cout << "p3's ref count = " 
				<< p3.use_count() << std::endl;

		}
	}
}




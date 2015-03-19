/*************************************************************************
	> File Name: derive.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Thu 19 Mar 2015 09:26:21 PM CST
 ************************************************************************/

#include<iostream>
class Baseclass
{
public:
#if 1 
	Baseclass()
	{
		std::cout << "Base default constructor" << std::endl;
	}
#endif
	Baseclass(int i)
	{
		std::cout << "Base constructor" << std::endl;
	}

private:
	int ix_;
};
class Derived : public Baseclass
{
public:
#if 0
	Derived()
	{
		std::cout << "Derived default constructor" << std::endl;

	}
	Derived(int ix)
	{
		std::cout << "Derived default constructor" << std::endl;
	}
#endif
};
int main(void)
{
	
Derived d1;
return 0;
	
}


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
	Baseclass()
	{
		std::cout << "Base default constructor" << std::endl;
	}

private:
	int ix_;
};
class Derived : public Baseclass
{
public:
	Derived()
	{
		std::cout << "Derived default constructor" << std::endl;

	}
	Derived(int ix)
	{
		std::cout << "Derived default constructor" << std::endl;
	}

};
int main(void)
{
	
Derived d1(3);
return 0;
	
}


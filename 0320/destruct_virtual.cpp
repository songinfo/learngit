/*************************************************************************
	> File Name: destruct_virtual.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 20 Mar 2015 08:40:51 PM CST
 ************************************************************************/

#include<iostream>

class Base
{
public:
	Base()
	{
	data_ = new char[64];
	std::cout << "Base() has been called " << std::endl;
	}
	virtual ~Base()
	{
	delete [] data_;
	std::cout << "~Base() has been called " << std::endl;
	}
private:
	char* data_;

};

class Child : public Base
{
public:
	Child(): Base()
	{
	cdata_ = new char[64];
	std::cout << "Child() has been called " << std::endl;
	}
	~Child()
	{
	delete [] cdata_;
	std::cout << "~Child() has been called " << std::endl;
	}
private:
	char* cdata_;

};

int main(void)
{
Child *pb = new Child;
delete pb;

return 0;
}


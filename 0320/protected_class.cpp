/*************************************************************************
	> File Name: protected_class.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 20 Mar 2015 08:16:44 PM CST
 ************************************************************************/

#include<iostream>
class X
{
protected:

public:
	X(int idx)
	{
		std::cout << "X()" << std::endl;
	}

};

class Base
{
public:
	void disp()
	{
		std::cout << "ix_ = " << ix_ << std::endl;
	}
protected:
	Base(int ix = 0):ix_(ix)
	{
	
	}
private:
	int ix_;

};

class Child : public Base
{
public:
Child(int xp):Base(xp) {}

public:
//Base b;
//X x;
};

int main(void)
{
//Base b;
Child child(10);
child.disp();

return 0;
}







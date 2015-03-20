/*************************************************************************
	> File Name: construct_private.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 20 Mar 2015 09:12:58 PM CST
 ************************************************************************/

#include<iostream>

class Example
{
public:
	static Example* createInstance(int ix)
	{
	if(NULL == pinstance)
	{
		std::cout << "new Example " << std::endl;
		pinstance = new Example(ix);
	}
	return pinstance;
	}

#if 0
static Example* createInstance(int ix)
{
if(NULL == pinstance)
{
	std::cout << "new Example " << std::endl;
	return new Example(ix);
}
return pinstance;
}
#endif

static void destroyInstance(Example* pe)
{
delete pe;
}
void disp()
{
std::cout << "ix_ is " << ix_ << std::endl;
}
~Example()
{
	std::cout << "~Example()" << std::endl;
}
private:
Example(int ix = 0): ix_(ix){}
private:
static Example* pinstance;
int ix_;
};
Example *Example::pinstance = NULL;

#if 0
int main(void)
{
Example* pExamp0 = Example::createInstance(10);
Example* pExamp1 = Example::createInstance(20);
Example* pExamp2 = Example::createInstance(30);

std::cout <<" pExample0's address = " << pExamp0 <<std::endl;
pExamp0->disp();
std::cout <<" pExample1's address = " << pExamp1 <<std::endl;
pExamp1->disp();
std::cout <<" pExample2's address = " << pExamp2 <<std::endl;
pExamp2->disp();

return 0;
}
#endif

int main(void)
{
//Example e;
//Example* pe = new Example;

	Example* pe = Example::createInstance(10);
    pe->disp();

    delete pe;
//pe->destroyInstance(pe);
//Example::destroyInstance(pe);
}

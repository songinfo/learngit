/*************************************************************************
  > File Name: derive0.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Thu 19 Mar 2015 10:06:56 AM CST
 ************************************************************************/

#include<iostream>

class Baseclass
{
	private :
		int a;
	public:
		Baseclass()		//用于检测基类的缺省的无参构造函数是否被自动调用
		{
			std::cout << "default base" << std::endl;
		}
};
class Derivedclass : public Baseclass
{
	public:
		Derivedclass()
		{
			std::cout << "default" << std::endl;
		}
		Derivedclass(int i)
		{
			std::cout << "constructing" << std::endl;
		}
};
int main(void)
{
	Derivedclass x1(5);
	Derivedclass x2;
	return 0;
}



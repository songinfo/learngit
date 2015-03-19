/*************************************************************************
  > File Name: copycontrol.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Thu 19 Mar 2015 10:06:42 PM CST
 ************************************************************************/

#include<iostream>
#include <string.h>

class Base
{
	public:
		Base(const char *str = NULL)
		{
			std::cout << "Base(const char *str) " << std::endl;
			if(NULL == str)
			{
				pbstr_ = new char[1];
				pbstr_[0] = '\0';
				return;
			}
			pbstr_ = new char[strlen(str) + 1];
			strcpy(pbstr_, str);
		}

		Base(const Base &rhs)
		{
			std::cout << "Base(const Base &rhs) " << std::endl;
			pbstr_ = new char[strlen(rhs.pbstr_) + 1];
			strcpy(pbstr_, rhs.pbstr_);
		}

		Base &operator=(const Base &rhs)
		{
			std::cout << "Base &operator=(const Base &rhs)" 
				<< std::endl;
			if(this != &rhs)
			{
				delete [] pbstr_;
				pbstr_ = new char[strlen(rhs.pbstr_) + 1];
				strcpy(pbstr_, rhs.pbstr_);
			}
			return *this;
		}

		~Base()
		{
			delete [] pbstr_;
		}

	private:
		char *pbstr_;
};


class Derived : public Base
{
	public:
		Derived(const char *str = NULL) : Base(str) {}

};

int main(void)
{
	Derived d1("Hello");
	std::cout << std::endl;
	Derived d2 = d1;
//	Derived d2;
//	d2 = d1;
	return 0;

}



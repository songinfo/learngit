/*************************************************************************
  > File Name: copycontrol1.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Thu 19 Mar 2015 10:17:42 PM CST
 ************************************************************************/

#include <iostream>
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

		void print()
		{
			std::cout << "Base: " << pbstr_ << ",";
		}

	private:
		char *pbstr_;
};


class Derived : public Base
{
	public:
		Derived()
		{
			pdstr_ = new char[1];
			pdstr_[0] = '\0';
			std::cout << "Derived()" << std::endl;
		}
		Derived(const char *str1, const char *str2) : Base(str1) 
	{
		pdstr_ = new char[strlen(str2) + 1];
		strcpy(pdstr_, str2);
		std::cout << "Derived(str1,str2)" << std::endl;
	}

		Derived(const Derived &rhs) : Base(rhs) 
	{
		pdstr_ = new char[strlen(rhs.pdstr_) + 1];
		strcpy(pdstr_, rhs.pdstr_);
		std::cout << "Derived(const Derived &rhs)" << std::endl;
	}

		Derived &operator=(const Derived &rhs)
		{
			if(this != &rhs)
			{
				Base::operator=(rhs);//注意这种写法
				pdstr_ = new char[strlen(rhs.pdstr_) + 1];
				strcpy(pdstr_, rhs.pdstr_);
				std::cout << "Derived &operator=(const Derived &rhs)" 
					<< std::endl;
			}
			return *this;
		}

		~Derived()
		{
			delete [] pdstr_;
		}

		void print()
		{
			Base::print();
			std::cout << "Derived: " << pdstr_ << std::endl;
		}
	private:
		char *pdstr_;
};

int main(void)
{
	Derived d1("Hello", "World");
	d1.print();
	std::cout << std::endl;
//	Derived d2 = d1;
	Derived d2;
	d2 = d1;
	d2.print();
	return 0;
}



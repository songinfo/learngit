/*************************************************************************
	> File Name: raii.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Tue 17 Mar 2015 08:35:46 PM CST
 ************************************************************************/

#include<iostream>

template<typename T>
class RAII //只能生成栈对象
{
public:
	explicit RAII(T *p):p_(p){}
	~RAII()
	{
		delete P_;
	}
	T &operator *() const
	{
      return (*P_);
	}
	T *get() const
	{
		return p_;
	}
	void reset (T *P)
	{
		delete P_;
		p_ = p;
	}

private:
	RAII(const RAII &);
	RAII &operator =(const RAII &);
private:

	T *p_;
	
};

class someresource
{

};

class Example
{
public:
	Example()
		:p1_(new someresource),
		 p2_(new someresource)
	{}
	Example(const Example &rhs)
	:p1_(new someresource(*rhs.p1_)),
	 p2_(new someresource(*rhs.p2_))
	{}
	Example &operator = (const Example &ths)
	{
		if(this == &rhs)
		{
			return *this;
		}
		*p1_ = *rhs.p1_;
		*p2_ = *rhs.p2_;
		return *this;
	}
	~Example()
	{
		std::cout << "~Example()" << std::endl;

	}
private:
	RAII<someresource> p1_;
	RAII<someresource> p2_;
};


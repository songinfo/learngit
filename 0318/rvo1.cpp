/*************************************************************************
  > File Name: rvo1.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Wed 18 Mar 2015 10:35:17 PM CST
 ************************************************************************/

#include<iostream>
class Rational
{
	public:
		Rational(int numerator = 0, int denominator = 1):n_(numerator),d_(denominator)
	{
		std::cout << "Constructor Called..." << std::endl;
	}

		~Rational()
		{
			std::cout << "~Destructor Called..." << std::endl;
		}

		Rational(const Rational &rhs)
		{
			n_ = rhs.n_;
			d_ = rhs.d_;
			std::cout << "Copy Constructor Called..." << std::endl;
		}

		int numerator() const { return n_;	}
		int denominator() const {	return d_;	}

	private:
		int n_;
		int d_;
};

const Rational operator *(const Rational &lhs, const Rational &rhs)
{
//#if 0
	std::cout << "...Enter operator *()..." << std::endl;
	Rational tmp(lhs.numerator() * rhs.numerator(),
			lhs.denominator() * rhs.denominator());
	std::cout << "...Leave operator *()..." << std::endl;

	return tmp;
//#endif
	//return Rational(lhs.numerator() * rhs.numerator(),
	//		lhs.denominator() * rhs.denominator());
}

int main(void)
{
	Rational x(1, 5), y(2, 9);
	std::cout << std::endl;
	Rational z = x * y;
	std::cout << std::endl;
	std::cout << "calc result:" << z.numerator()
		<< "/" << z.denominator() << std::endl;

	return 0;
}




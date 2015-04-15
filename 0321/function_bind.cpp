/*************************************************************************
	> File Name: function_bind.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Sat 21 Mar 2015 03:46:44 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
#include<math.h>

const float PI = 3.1415926;

class Circle
{
public:
	Circle(float r = 0)
	{
	fRadius_ = r;
	}
	float area()
	{
	return PI * fRadius_ * fRadius_;

	}
	void dispname()
	{
		std::cout << "Circle " << std::endl;

	}
private:
	float fRadius_;
};
class Rectangle
{
public:
	Rectangle(float fx = 0.0, float fy = 0.0)
	{
	fx_ = fy;
	fy_ = fy;
	}
	float area()
	{
	return fx_ * fy_;

	}
	void dispname()
	{
		std::cout << "Rectangle "<< std::endl;
	}
private:
	float fx_;
	float fy_;

};

class Triangle
{
public:
	Triangle(float fa = 0, float fb = 0, float fc = 0)
	{
	fa_ = fa;
	fb_ = fb;
	fc_ = fc;

	}
	float area()
	{
	float fp = (fa_ + fb_ + fc_) / 2;
	return sqrt(fp * (fp - fa_) * (fp - fb_) * (fp - fc_));
	}
	void dispname()
	{
		std::cout << "Triangle " << std::endl;
	}
private:
	float fa_;
	float fb_;
	float fc_;
};

int main(void)
{
	std::function<float()> func1;
	std::function<void()> func2;
	Circle c(3);
	Rectangle r(1.2f, 3.6f);
	Triangle t(6, 7, 8);

	func1 = std::bind(&Circle::area, c);
	func2 = std::bind(&Circle::dispname, c);
	std::cout << "area = " << func1() << std::endl;
	func2();
	std::cout << std::endl;

	func1 = std::bind(&Rectangle::area, c);
	func2 = std::bind(&Rectangle::dispname, c);
	std::cout << "area = " << func1() << std::endl;
	func2();
	std::cout << std::endl;

	func1 = std::bind(&Triangle::area, c);
	func2 = std::bind(&Triangle::dispname, c);
	std::cout << "area = " << func1() << std::endl;
	func2();
	std::cout << std::endl;

	return 0;
}



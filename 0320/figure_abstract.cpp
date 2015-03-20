/*************************************************************************
	> File Name: figure_abstract.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 20 Mar 2015 08:51:35 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>

const float PI = 3.1415926;
class Figure
{
public:
	virtual float area() = 0;
	virtual void dispname() = 0;
};
class Circle : public Figure
{
public:
	Circle(float r = 0 )
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
class Rectangle : public Figure
{
public:
	Rectangle(float fx = 0.0, float fy = 0.0)
	{
	fx_ = fx;
	fy_ = fy;
	}
	float area()
	{
	return fx_ * fy_;
	}
	void dispname()
	{
		std::cout << "Rectangle " << std::endl;
	}
private:
	float fx_;
	float fy_;
};
class Triangle :public Figure
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
//Figure f;  // Error;
Figure *pFig = NULL;

Circle c(3);
Rectangle r(1.2f, 3.6f);
Triangle t(6, 7, 8);

pFig = &c;
pFig->dispname();
std::cout << pFig->area() << std::endl;
std::cout << std::endl;

pFig = &r;
pFig->dispname();
std::cout << pFig->area() << std::endl;
std::cout << std::endl;

pFig = &t;
pFig->dispname();
std::cout << pFig->area() << std::endl;
std::cout << std::endl;

return 0;
}

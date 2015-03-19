/*************************************************************************
	> File Name: pointderi.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Thu 19 Mar 2015 10:43:47 PM CST
 ************************************************************************/

#include<iostream>

class Point
{
public:
	Point(int ix = 0, int iy = 0):ix_(ix), iy_(iy){}
	void disp() const
	{
		std::cout << "(" << ix_
			      << "," << iy_
				  << ")" << std::endl;
	}
	int getx()  const
	{
	return ix_;
	}
	int gety() const
	{
	return iy_;	
	}
private:
	int ix_;
	int iy_;
};
class Point3D : public Point
{
public:
Point3D(int ix, int iy, int iz):Point(ix, iy), iz_(iz){}

void disp() const 
{
		std::cout << "(" << getx()
			      << "," << gety()
				  << "," << iz_
				  << ")" << std::endl;
}
int calc_sum()
{

return getx() + gety() + iz_;
}
private:
int iz_;
};

int main(void)
{
Point pt1(1, 1);
pt1.disp();

Point3D pt2(2, 3, 4);
pt2.disp();

std::cout << "对象强制转换" << std::endl;
pt1 = pt2; //向上转换
pt1.disp();

std::cout << "引用" << std::endl;
Point &refpt = pt2;
refpt.disp();

std::cout << "指针" << std::endl;
Point *ppt = &pt2;
ppt->disp();

return 0;
}


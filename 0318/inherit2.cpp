/*************************************************************************
  > File Name: inherit2.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Thu 19 Mar 2015 12:25:19 AM CST
 ************************************************************************/

#include<iostream>


class Point
{
	public:
		Point(int ix = 0, int iy = 0) : ix_(ix), iy_(iy), im_(50){}

		void disp() const
		{
			std::cout << "(" << ix_ 
				<< "," << iy_
				<< ")" << std::endl;
		}

		int getx() const
		{   return ix_; }

		int gety() const
		{   return iy_; }

	protected:
		int im_;


	private:
		int ix_;
		int iy_;
};

class Point3D : private Point
{
	public:
		Point3D(int ix, int iy, int iz) : Point(ix, iy), iz_(iz){}

		void disp() const//成员函数覆盖
		{
			std::cout << "(" << getx()
				<< "," << gety()
				<< "," << iz_
				<< ")" << std::endl
				<< "Point:im_ = " << im_ << std::endl;
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
	Point pt1(7, 9);
	pt1.disp();

	Point3D pt2(3, 4, 5);
	pt2.disp();
//	std::cout << "Point::x = " << pt2.getx() << std::endl;//对于getx()的访问权限变成了private

//	pt2.im_ = 30;//无法访问

	int res = pt2.calc_sum();
	std::cout << res << std::endl;

	return 0;
}



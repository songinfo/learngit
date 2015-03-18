/*************************************************************************
  > File Name: inherit.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Wed 18 Mar 2015 03:32:45 PM CST
 ************************************************************************/

#include<iostream>

class Line;

class Point		//point类定义
{
	public:
		friend Line ;
	private:		//private成员列表，表示点的坐标信息
		int ix_;
		int iy_;

	public:
		Point(int ix = 0, int iy = 0) //构造函数，带缺省参数
		{
			ix_ = ix;
			iy_ = iy;
			im_ = 50;
		}

		void disp()	const //成员disp函数，用来输出点的信息
		{
			std::cout << "( " << ix_ << " , " << iy_ << " )" << std::endl;
		}

		int getx() const	//读取private成员x
		{
			return ix_;
		}

		int gety()	const	//读取private成员y
		{
			return iy_;
		}
	protected:
		int im_;

};

class Point3D:public Point //3维点类point3D，从point类继承而来
{
public:

    int iz_;	//在point类基础上增加了z坐标信息

public:
		Point3D(int ix, int iy, int iz):Point(ix, iy)//派生类构造函数，初始化表中调用基类构造函数
	{
		iz_ = iz;
	}

void disp()	const	//隐藏了基类的中的同名disp函数
	{
			std::cout << "( " << getx() 
				      << " , " << gety() 
			          << " , " << iz_ 
				      << " )" << std::endl
				      << "Point:im_ = " << im_ << std::endl;
	}

		int calc_sum()	//增添了计算3个数据成员和的函数
		{
			return getx() + gety() + iz_;
		}
};
class Line 
{
	public:
		Line(int ix1 = 0, int iy1 = 0, int iz1 = 0, 
			 int ix2 = 0, int iy2 = 0, int iz2 = 0)
			:pt3_(ix1, iy1),
			pt3d1_(ix1, iy1, iz1),
			pt3d2_(ix2, iy2, iz2)
	{}
		void setPoint(int ix, int iy)
		{
			pt3_.ix_ = ix;
			pt3_.iy_ = iy;

		}
#if 1
		void setPoint3D(int ix, int iy, int iz)
		{
			//pt3d1_.ix_ = ix;
			//pt3d1_.iy_ = iy;
			pt3d1_.iz_ = iz;

		}
#endif
		void print() const
		{
			pt3d1_.disp();
			pt3d2_.disp();
			pt3_.disp();
		}


	private:
		Point3D pt3d1_;
		Point3D pt3d2_;
		Point pt3_;
};
int main(void)
{
	std::cout << "Point's size = " << sizeof(Point) << std::endl;
	std::cout << "Point3D's size = " << sizeof(Point3D) << std::endl;


	Point pt1(7, 9);	//建立point类对象pt1
	pt1.disp();		//显示pt1的信息

	Point3D pt2(3, 4, 5);	//建立point3D类对象pt2
	pt2.disp();		//显示pt2的信息

//	pt2.im_ = 30;  //无法访问

	int res = pt2.calc_sum();//计算pt2中3个坐标信息的加和
	std::cout << res << std::endl;		//输出结果

#if 1
	Line line(1, 2, 3, 5, 6, 7);
	line.print();
	std::cout << std::endl;
	line.setPoint(10, 11);
	line.print();
	line.setPoint3D(15, 16, 17);
#endif

	return 0;
}




/*************************************************************************
  > File Name: worm.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Fri 20 Mar 2015 08:11:45 PM CST
 ************************************************************************/

#include<iostream>

class Worm
{
	public:
		virtual void draw()
		{
			std::cout << "Worm::draw()" << std::endl;
		}

		virtual void draw1()
		{
			std::cout << "Worm::draw1()" << std::endl;
		}
};  

class Ant : public Worm
{
	public:
#if 1
		void draw()
		{
			std::cout << "Ant::draw() " << std::endl;
		}
#endif
};

class Spider : public Worm
{
	public:
		void draw()
		{
			std::cout << "Spider::draw() " << std::endl;
		}
};

int main(void)
{
	std::cout << sizeof(Worm) << std::endl;
	std::cout << sizeof(Ant) << std::endl;
	std::cout << sizeof(Spider) << std::endl;
}

int test0(void)
{
	Worm *pWorm;
	Ant ant;
	Spider spider;
	pWorm = &ant;
	pWorm->draw();
	std::cout << std::endl;
	//ant.Worm::draw();

	std::cout << std::endl;

	pWorm = &spider;
	pWorm->draw();

	return 0;
}




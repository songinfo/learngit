/*************************************************************************
  > File Name: worm.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Fri 20 Mar 2015 12:53:11 AM CST
 ************************************************************************/

#include<iostream>

#include <iostream>

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



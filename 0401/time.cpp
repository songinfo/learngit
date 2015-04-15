/*************************************************************************
	> File Name: time.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Wed 01 Apr 2015 04:49:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Time
{
	public:
		Time(){minute = 0; sec = 0;}
		Time(int m, int s): minute(m), sec(s) {}
		Time operator++();
		void display()
		{
		cout << minute << ":" << sec << endl;
	
		}
	private:
		int minute;
		int sec;
};

Time Time::operator++()
{
  if(++sec >= 60)
  {
  sec -= 60;
  ++minute;
  }
  return *this;
}

int main(void)
{
Time time1(0, 0);
   for(long double i = 0; i < 1000000; ++i)
   {
   ++time1;
   time1.display();
   }


return 0;

}









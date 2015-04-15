/*************************************************************************
	> File Name: sstream.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Tue 31 Mar 2015 10:19:29 PM CST
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<strstream>

using namespace std;

struct student
{
int num;
char name[20];
float score;

};

int main(void)
{
student stud[5] = {
	1001, "Li", 85, 
	1002,"Fang", 97.5,
	1004, "Wang", 54,
	1006, "Tan", 76.5,
	1010, "Ling", 96};

cout << "size of student: " << sizeof(student)<< endl;
cout << "size of stud[0]: " << sizeof(stud[0])<< endl;

cout << endl;

char c[140];
ostrstream strout(c, 140);

for(int i = 0; i < 5; i++)
  {
 
  strout << stud[i].num << " " << stud[i].name << " " << stud[i].score << endl;

  }

cout << "array c:" << c << endl;


return 0;
}


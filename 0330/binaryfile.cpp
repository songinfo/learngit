/*************************************************************************
	> File Name: binaryfile.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 30 Mar 2015 04:20:59 PM CST
 ************************************************************************/

#include <stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;

struct student
{
char name[20];
int num;
int age;
char sex;

};


int main(void)
{
student stu[3] = {"Li", 1001, 18, 'f',"Fang", 1002, 19, 'm',"Wang", 1004, 17, 'f'};
ofstream outfile("stu.dat", ios::binary);
if(!outfile)
{
cerr << "open error !" << endl;
abort();
}
for(int i = 0; i < 3; i++)
outfile.write((char*)&stu[i], sizeof(stu[i]));

outfile.close();
return 0;

}

/*************************************************************************
	> File Name: rdbinaryfile.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 30 Mar 2015 04:39:46 PM CST
 ************************************************************************/

#include <stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;

struct student
{
string name;
int num;
int age;
char sex;

};


int main(void)
{
student stu[3];
int i;

ifstream infile("stu.dat", ios::binary);
if(!infile)
{
cerr << "open error !" << endl;
abort();
}
for(i= 0; i < 3; i++)
infile.read((char*)&stu[i], sizeof(stu[i]));

infile.close();
for(i = 0; i < 3; i++)
{
cout << "NO." << i + 1 << endl;
cout << "name:" << stu[i].name << endl;
cout << "num:" << stu[i].num << endl;
cout << "age:" << stu[i].age << endl;

cout << "sex:" << stu[i].sex << endl << endl;


}
return 0;

}

/*************************************************************************
	> File Name: iofile.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 30 Mar 2015 03:50:41 PM CST
 ************************************************************************/

#include<fstream>
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
int a[10];
ofstream outfile("f1.txt", ios::out);
if(!outfile)
{
cerr<< "open error!"<< endl;
exit(1);
}

cout << "Enter 10 integer numbers:" << endl;
for(int i = 0; i < 10; i++ )
 {
 cin >> a[i];
 outfile << a[i] << " ";
 }
outfile.close();
return 0;

}

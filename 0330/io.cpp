/*************************************************************************
	> File Name: io.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 30 Mar 2015 03:02:03 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main(void)
{
char c[20];
int ch;
cout << "Please enter a sentence:" << endl;
cin.getline(c, 18, '/');
cout << "The first part is:" << c << endl;
ch = cin.peek();
cout << "The next character(ASCII code) is :" << ch <<endl;
cin.putback(c[0]);
cin.getline(c, 15, '/');
cout << "The second part is:" << c << endl;

return 0;
}

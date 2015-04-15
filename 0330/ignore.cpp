/*************************************************************************
	> File Name: ignore.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 30 Mar 2015 03:12:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main(void)
{
char ch[20];
cin.get(ch, 20, '/');
cout<< "The first part is:" << ch << endl;

cin.ignore();
cin.get(ch, 20, '/');
cout << "The second part is :" << ch << endl;

cin.ignore();
cin.get(ch, 20, '/');
cout << "The third part is :" << ch << endl;

return 0;

}

/*************************************************************************
	> File Name: try.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Tue 31 Mar 2015 11:26:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(void)
{
void f1();
  try
  {
  f1();
  }
  catch(double)
 { 
 cout << "ERROR0!" <<endl;
 }
  cout << "end0" << endl;
  return 0;
}

void f1()
{
void f2();
  try
  {
  f2();
  }
  catch(char)
  {
  cout << "ERROR1!" << endl;
  }
  
  cout << "end1" << endl;

}


void f2()
{
void f3();
  try
  {
  f3();
  }
  catch(int)
  {
  cout << "ERROR2!" << endl;
  }
  
  cout << "end2" << endl;

}

void f3()
{
double a = 0;
  try
  {
  throw a;
  }
  catch(float)
  {
  cout << "ERROR3!" << endl;
  }
  
  cout << "end3" << endl;

}

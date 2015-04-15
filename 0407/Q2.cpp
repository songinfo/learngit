/*************************************************************************
	> File Name: Q2.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Tue 07 Apr 2015 10:09:08 AM CST
 ************************************************************************/

char *Question2 = "Q2:请编写函数fun，它的功能是：求出1到100之内能被7或者11整除，但不能同时被7或11整除的所有整数，并将他们放在a所指向的数组中，通过n返回这些数的个数。";
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int statistic_Q2(int a[])
{
int k, i;
   for(i = 1, k = 0; i <= 100; ++i)
  {
   if((!(i % 7 == 0 && i % 11 == 0)) && (i % 7 == 0 || i % 11 == 0))
	   a[k++] = i;
  }

return k;
}

void Q2()
{
puts(Question2);
int a[100], i, k;
k = statistic_Q2(a);
printf("%d\n", k);
  for(i = 0; i < k; ++i)
  {
  printf("%d", a[i]);
  putchar(10);
  }
}

int main(void)
{

Q2();

return 0;
}

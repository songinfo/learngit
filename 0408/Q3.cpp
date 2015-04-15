/*************************************************************************
	> File Name: Q3.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Wed 08 Apr 2015 10:21:15 AM CST
 ************************************************************************/

//char *Question3 = "Q3:请编写函数void fun(int x, int pp[], int *n), 它的功能是：求出能整除x且不是偶数的各整数，并按从小到大的顺序放在pp所指向的数组中，这些除数的个数通过形参n返回。";

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

char *Question3 = "Q3:请编写函数void fun(int x, int pp[], int *n), 它的功能是：求出能整除x且不是偶数的各整数，并按从小到大的顺序放在pp所指向的数组中，这些除数的个数通过形参n返回。";
void divided(int x, int pp[], int *n)
{
  int i;
  for(i = 1, *n = 0; i < x; ++i)
  {
    if(x%i == 0 && i % 2 != 0)
    {
	pp = (int*)realloc(pp, (*n + 1) * sizeof(int));
	pp[(*n)++] = i;
	}
  }
}

void Q3()
{
  puts(Question3);
  int i, x, n, *pp;
  printf("Please input a number:");
  scanf("%d", &x);
  pp = (int*)malloc(sizeof(int));
  divided(x, pp, &n);
  printf("%d\n", n);
  putchar(10);
  for(i = 0; i < n; ++i)
	  printf("%d\n", pp[i]);
}

int main(void)
{
Q3();

return 0;
}


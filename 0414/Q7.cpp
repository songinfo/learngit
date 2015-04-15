/*************************************************************************
	> File Name: Q7.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Wed 15 Apr 2015 12:03:37 AM CST
 ************************************************************************/

#include<stdio.h>
#define M 20

char *Question7 = "Q7:请编写一个函数int fun(int *s, int t, int *k),用来求数组中最大元素在数组中的下标并存放在k所指的存储单元中。";

void maxElemInArray(int *a, int n, int *k)
{
   int i, temp;
   for(i = 1, temp = a[0]; i < n; ++i)
   {
	 if(temp < a[i])
	 {
     *k = i;
	 temp = a[i];
	 }
   
   }

}

void Q7()
{
  puts(Question7);
  int num[M], i;
  printf("please input %d numbers:\n", M);
  for(i = 0; i < M; ++i)
  {
  scanf("%d", num + i);
  }
  maxElemInArray(num, M, &i);
  printf("The Max number is %d, and its position is %d.", num[i], i + 1);
  putchar(10);
}
int main(void)
{
Q7();

return 0;
}


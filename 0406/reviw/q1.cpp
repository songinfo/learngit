/*************************************************************************
	> File Name: q1.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 06 Apr 2015 11:47:31 AM CST
 ************************************************************************/

char *Question1 = "Q1:m个人的成绩存在score数组中，请编写函数fun，它的功能是：将低于平均分的人作为函数值返回，将低于平均分的分数放在below所指定的函数中。";
#include<stdio.h>
#include<iostream>
#define M 20

int lowerThanAvg(float score[], int m, float fail[])
{
int i, k;
float sum, avg;
   for(i = 0, sum = 0; i < m; sum += score[i], ++i )
   {
   avg = sum / m;
   }
   for(i = 0, k = 0; i < m; ++i)
   if(score[i] < avg)
	   fail[k++] = score[i];
   return k;
}

void Q1()
{
  puts(Question1);
  float score[M], fail[M];
  int i, k;
  printf("Please input %d student's score: \n", M);
  for(i = 0; i < M; ++i)
  {
  scanf("%f", score + i);
  }
  k = lowerThanAvg(score, M, fail);
  printf("The scores lower than average are :\n");
  for(i = 0; i < k; ++i)
  {
  printf("%5.2f", fail[i]);
  }
  printf("\n");
}

int main(void)
{
Q1();

return 0;
}

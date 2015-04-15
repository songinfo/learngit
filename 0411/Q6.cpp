/*************************************************************************
	> File Name: Q6.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Sat 11 Apr 2015 11:13:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

char *Question6 = "Q6:请编写一个函数void fun(char a[], char b[], int n),其功能是：删除以各字符串中指定下标的字符。其中，a指向源字符串，删除后的字符串存放在b所指的数组中，n中存放指定的下标.";

void str_copy(char a[], char b[], int n)
{
  char *ap = a, *bp = b, i = 0;
  while(*ap != '\0')
  {
     if((i++) != n)
		 *(bp++) = *ap;
	 ++ap;

  }
  *bp = '\0';
}

void Q6()
{
   puts(Question6);
   char a[1000], b[1000];
   int i;
   printf("Please input a string:\n");
   gets(a);
   printf("Please input the position of charactor you want to delete:");
   scanf("%d",&i);
   while(i <= 0 || i > strlen(a))
   {
     printf("The position is wrong,please input again:");
	 scanf("%d", &i);
   }
   str_copy(a, b, i- 1);
   printf("The result is:\n");
   puts(b);
	   return ;

}

int main(void)
{
  Q6();

  return 0;
}


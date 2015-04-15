/*************************************************************************
	> File Name: pstr.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Tue 14 Apr 2015 12:13:07 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *getmemory()
{
 // char p[] = "hello world";
 char p[] = {'h', 'a', 'p', 'p', 'y', '\0'};

  return p;
}

int main(void)
{
   char *str;

  str = getmemory();
  printf(str);
  putchar(10);

   return 0;
}



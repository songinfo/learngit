/*************************************************************************
	> File Name: Q4.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 10 Apr 2015 12:51:13 AM CST
 ************************************************************************/

#include<stdio.h>
//#include<stdlib.h>

char *Question4 = "Q4:请编写一个函数void fun（char *tt，int pp[]）,统计在tt字符中\"a\"到\"z\"26各字母各自出现的次数，并依次放在pp所指向的数组中。";

void frequency(char *tt, int pp[])
{
  char *c = tt;
  while(*c != '\0')
  {
    if(*c <= 'z' && *c >= 'a')
	{
	++pp[*c - 97];
	}
	++c;
	
  }
}
void Q4()
{
  puts(Question4);
  int i, pp[26] = {0};
  char tt [1000];
  printf("Please input a string with lowercase:\n");
  gets(tt);
  frequency(tt, pp);
  for(i = 0;  i < 26; ++i )
	  printf("%c:%d\n", 97 + i, pp[i]);

  return ;
}

int main(void)
{
   Q4();

   return 0;
}

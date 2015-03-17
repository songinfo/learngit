/*************************************************************************
  > File Name: stack.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Mon 16 Mar 2015 03:19:56 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
int main(void)
{
	std::stack<int, std::vector<int> >obi;
	for(int i = 0; i <= 20; i++)
	{
		obi.push(i);
	}
	while(obi.size())
	{
		int x = obi.top();
		std::cout << x << " ";
		obi.pop();
	}
	std::cout << std::endl;
	std::stack<std::string, std::vector<std::string> >obs;

	for (char c = 'A'; c <= 'Z'; c++)
	{
		std::string s(2, c);
		obs.push(s);
	}

	while (obs.size() > 0)
	{
		std::string s = obs.top();
		std::cout << s << "  ";
		obs.pop();
	}

	std::cout << std::endl;



	return 0;
}
/*
int main(void)
{
	int i = 0;
	std;:stack<int> st;
	for (i = 0; i < 10; i++)
	{
		st.push(i);		//把元素一个一个存入到stack中
		std::cout << st.top() << " 已入栈" << std::endl;

	}
	std::cout << "现在stack的容量: " << st.size() << std::endl << std::endl;
	for (i = 0; i < 10; i++)
	{
		std::cout << st.top() << " 准备出栈" << std::endl;
		st.pop();//把元素一个一个出栈
	}
	std::cout << "现在stack的容量: " << st.size() << std::endl << std::endl;


}
*/




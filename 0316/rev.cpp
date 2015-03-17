/*************************************************************************
  > File Name: rev.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Mon 16 Mar 2015 05:10:36 PM CST
 ************************************************************************/

#include<iostream>
#include <iterator> //使用reverse_iterator和ostream_iterator包含的头文件	
#include <vector>
using namespace std;

int main()
{
	int sz[5] = {1, 2, 3, 4, 5};
	vector < int > ob(sz, sz + 5);	//创建vector<int>对象
	ostream_iterator<int, char> osi(cout, "  ");		//创建输出流迭代器

	vector<int> ::reverse_iterator ri = ob.rbegin();	//创建反向迭代器
	copy(ri, ob.rend(), osi);		//输出操作	= copy(ob.rbegin(), ob.rend(), osi);

	cout << endl;
	
	return 0;
}




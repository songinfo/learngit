/*************************************************************************
	> File Name: rvo0.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Wed 18 Mar 2015 10:26:48 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>

std::vector<int> get_all_scores()
{
	std::vector<int> vectemp;
	vectemp.push_back(90);
	vectemp.push_back(85);
	return vectemp;
}
int main(void)
{
	std::vector<int> vec = get_all_scores();
	std::cout << vec[0] << std::endl << vec[1] << std::endl;

	return 0;
}

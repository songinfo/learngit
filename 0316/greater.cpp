/*************************************************************************
	> File Name: greater.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 16 Mar 2015 02:58:50 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;

template<typename T>
struct greater
{
bool operator()(const T &lts, const T &rhs) const
{
return lhs > rhs;

}

}



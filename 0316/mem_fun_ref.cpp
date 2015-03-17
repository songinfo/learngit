/*************************************************************************
  > File Name: mem_fun_ref.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Mon 16 Mar 2015 04:24:54 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>


class NumVal
{
private:
	int val;
public:
		NumVal()
		{
			val = 0;
		}
		NumVal(int j)
		{
			val = j;
		}

		bool display()
		{
			std::cout << val << " ";
			return true;
		}
		bool isEven()
		{
			return (bool) !(val % 2);
		}
		bool isPrime()
		{
			for (int i = 2; i <= (val / 2); i++)
			{
				if (!(val % i)) 
				return false;
			}
			return true;
		}
};

int main()
{
	//1
	std::vector<NumVal> v1(13);
	std::vector<NumVal>::iterator it1;
	for (int i = 0; i < 13; i++)
	{
		v1[i] = NumVal(i + 1);
	}

	std::cout << "v1中的原始值为: " << std::endl;
	for_each(v1.begin(), v1.end(), std::mem_fun_ref(&NumVal::display));
	std::cout << std::endl;

	
	// Use of mem_fun_ref calling member function through a reference
	// remove the primes in the vector using isPrime ( )
	it1 = remove_if(v1.begin(), v1.end(), std::mem_fun_ref(&NumVal::isPrime));
	std::cout << "v1中删除质数后剩下的值为: " << std::endl;
	for_each(v1.begin(), it1, std::mem_fun_ref(&NumVal::display));
	std::cout << std::endl;
	std::cout << std::endl;

	//2.
	std::vector<NumVal> v2(13);
	std::vector<NumVal>::iterator it2;
	for (int k = 0; k < 13; k++)
	{
		v2 [k] = NumVal (k + 1);
	}

	std::cout << "v2中的原始值为: " << std::endl;
	for_each(v2.begin(), v2.end(), std::mem_fun_ref(&NumVal::display));
	std::cout << std::endl;

	// Use of mem_fun_ref calling member function through a reference
	// remove the even numbers in the vector v2 using isEven ( )
	it2 = remove_if(v2.begin(), v2.end(), std::mem_fun_ref(&NumVal::isEven));
	std::cout << "v2中删除偶数后剩下的值为: " << std::endl;
	for_each(v2.begin(), it2, std::mem_fun_ref(&NumVal::display));
	std::cout << std::endl;

//	getchar();
	return 0;
	
}

/*************************************************************************
	> File Name: function.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Sat 21 Mar 2015 03:00:53 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>

struct Foo
{
Foo(int num):num_(num) {}
void print_add(int i) const
{
	std::cout << "Foo::print_add(int i) : " << num_ + 1 << std::endl;
}
int num_;
};

void print_num(int i)
{
	std::cout << "print_num : " << i << std::endl;
}

struct Printnum
{
void operator()(int i) const
{

	std::cout << i << std::endl;
}
};

int main(void)
{
	std::function<void(int)> f = print_num;
	f(2);

	std::function<void(const Foo &, int)> f2 = &Foo::print_add;
	const Foo foo(314159);
	 f2(foo, 1);
	
	//f = std::bind(&Foo::print_add, foo, std::placeholders::-1);
	//f(3);
	//
	return 0;
}





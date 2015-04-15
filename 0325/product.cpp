/*************************************************************************
	> File Name: product.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Thu 26 Mar 2015 10:16:14 PM CST
 ************************************************************************/

#include "product.h"
#include "buffer.h"
#include<iostream>
#include<unistd.h>
#include<stdlib.h>

Product::Product(Buffer &buffer)
:buffer_(buffer)
{
srand(12345);

}
void Product::run()
{
while(1)
{
	std::size_t num = rand()%100;
	buffer_.push(num);
	std::cout << "push a No. " << num
		<< ", size = " << buffer_.size()
		<< std::endl;
	sleep(4);
}
}

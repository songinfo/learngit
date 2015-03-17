/*************************************************************************
	> File Name: auto_ptr.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Tue 17 Mar 2015 09:54:20 PM CST
 ************************************************************************/

#include<iostream>
#include<memory>

int main(void)
{
double *pd = new double(7.77);
std::auto_ptr<double> apd(pd);
//std::cout << apd << std::endl;
 std::cout << "*pd = " << *apd << std::endl;

 std::cout << "pd = " << apd.get() << std::endl;
 std::cout << "native pd = " << pd << std::endl;
 std::cout << std::endl;
 
 int *pi = new int(7);
 std::auto_ptr<int> api_1(pi);
 std::auto_ptr<int> api_2(api_1);

 //std::cout << "*api_1 = " << *api_1 << std::endl;
 std::cout << "*api_2 = " << *api_2 << std::endl;
 std::cout << std::endl;

 float *pf = new float(static_cast<float>(0.777));
 std::auto_ptr<float> apf_1(pf);
 std::cout << "*apf_1 = " << *apf_1 << std::endl;
 std::auto_ptr<float> apf_2;
 //apf_2 = pf;
 //apf_2.reset(pf);//使用reset（）同一对象可以被多次申请管理；但会出错double free；
 std::cout << "*apf_1 = " << *apf_1 << std::endl;
 //std::cout << "*apf_2 = " << *apf_2 << std::endl;


return 0;
}

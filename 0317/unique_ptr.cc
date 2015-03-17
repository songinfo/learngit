#include <iostream>
#include <memory>
#include <vector>

std::unique_ptr<int> get_value()
{
    std::unique_ptr<int> up(new int(99));
    return up;
}

int main(void)
{
    std::unique_ptr<int> ap(new int(88));
    std::cout << "*ap = " << *ap << std::endl;

    //int a = 3;//
    //std::move();
    //std::unique_ptr<int> ap1(ap);//编译失败
    //std::unique_ptr<int> ap1;
    //ap1 = ap;//unique_ptr不能进行复制或赋值

    std::unique_ptr<int> ap2 = get_value();
    std::cout << "*ap2 = " << *ap2 << std::endl;


    std::unique_ptr<int> ap3(new int(66));
    std::vector<std::unique_ptr<int> > vec;
    vec.push_back(std::move(ap3));
    //std::cout << "*ap3 = " << *ap3 << std::endl;

    int *pii = new int(55);//这种形式不推荐使用
    std::unique_ptr<int> *ap4 = new std::unique_ptr<int>(pii);
    std::cout << "ap4 = " << *(ap4->get()) << std::endl;
    return 0;
}

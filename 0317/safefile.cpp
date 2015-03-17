/*************************************************************************
	> File Name: safefile.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Tue 17 Mar 2015 08:05:54 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>

class safefile
{
public:
	safefile(const char* filename):filehandler_(fopen(filename, "w+"))
	{
    if(NULL == filehandler_)
	{
    std::cout << "file open failed !" << std::endl;
	}
	}

	~safefile()
	{
    std::cout << "fclose(filehandler_)" << std::endl;
	fclose(filehandler_);
	}
   void write(const char* str)
   {
   if(EOF == fputs(str, filehandler_))
   {
    std::cout << "write error" << std::endl;
   }else
   {
	   std::cout << "write ...\n" << std::endl;
   }
   }
void write(const char* buff, std::size_t len)
{
if(len != 0 && fwrite(buff, len, 1, filehandler_) == 0)
{
	std::cout << "write error" << std::endl;

}
}
private:
safefile(const safefile &);
safefile &operator =(const safefile &);

private:
FILE *filehandler_;

};

int main(void)
{
safefile testvar("test.txt");
testvar.write("Hello, RAII !");

return 0;
}




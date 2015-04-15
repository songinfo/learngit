/*************************************************************************
	> File Name: main.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Sun 29 Mar 2015 09:56:18 AM CST
 ************************************************************************/

#include<iostream>
#include "ThreadPool.h"
#include "MySocket.h"
#include "MyConf.h"
#include "MyCache.h"
int main(int argc, char* argv[])
{

 MyConf conf(argv[1]);
 conf.show();
 ThreadPool apool(conf);
 MySocket socket(conf);
 apool.on();
 std::string word;
 const int len = 1024;
 char buf[len];
 int iret;
 while(true)
   {
   memset(buf, 0, len);
   iret = socket.recv_message(buf, len);
   std::cout << "main: " << buf << "len: " << iret << std::endl;
   MyTask task(buf, socket.get_addr(), conf);
   apool.allocate_task(task);

   }

 apool.off();
 return 0;

}



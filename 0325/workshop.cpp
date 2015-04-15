/*************************************************************************
	> File Name: workshop.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Thu 26 Mar 2015 09:15:29 PM CST
 ************************************************************************/

#include "workshop.h"
#include "product.h"
#include "consumer.h"

Workshop::Workshop(std::size_t buffersz,
		std::size_t productSize,
		std::size_t consumerSize)
   :bufSize_(buffersz),
	buffer_(bufSize_),
	productSize_(productSize),
	consumerSize_(consumerSize),
	vec_producers(productSize_, NULL),
	vec_consumers(consumerSize_, NULL)
{
	std::vector<Product*>::iterator pit;
	for(pit = vec_producers.begin();
			pit != vec_producers.end();
			++pit)
	{
	*pit = new Product(buffer_);
	}

	std::vector<Consumer*>::iterator cit;
	for(cit = vec_consumers.begin();
			cit != vec_consumers.end();
			++cit)
	{
	*cit = new Consumer(buffer_);
	}

}

Workshop::~Workshop()
{
	std::vector<Product*>::iterator pit;
	for(pit = vec_producers.begin();
			pit != vec_producers.end();
			++pit)
	{
	delete *pit;
	}
	std::vector<Consumer*>::iterator cit;
	for(cit = vec_consumers.begin();
			cit != vec_consumers.end();
			++cit)
	{
	delete *cit;
	}
}

void Workshop::startWorking()
{
	std::vector<Product*>::iterator pit;
	for(pit = vec_producers.begin();
			pit != vec_producers.end();
			++pit)
	{
	(*pit)->start();
	}

	std::vector<Consumer*>::iterator cit;
	for(cit = vec_consumers.begin();
			cit != vec_consumers.end();
			++cit)
	{
	(*cit)->start();
	}
	for(pit = vec_producers.begin();
			pit != vec_producers.end();
			++pit)
	{
	(*pit)->join();
	}
for(cit = vec_consumers.begin();
		cit != vec_consumers.end();
		++cit)
{
(*cit)->join();
}

}



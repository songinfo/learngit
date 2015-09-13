/*************************************************************************
	> File Name: sort.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Sun 13 Sep 2015 10:06:07 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int* arrayInit(int len);

char** strInit(int len);
void forEachStr(char** bg, char** end,	char* (*handle)());
char* strAsign();
void strShow(char** arr, int len);
int strLess(const void* left, const void* right);

void forEach(int* bg, int* end, void(*handle)(int*));
void sort(int* bg, int* end, int (*cmp)(int* left, int* right));
void arrayDestroy(int* arr);
void visit(int* pval);
int myLess(const void*	left, const void* right);
int myGreat(const void* left, const void* right);
void init(int* pval);

int main(int argc, char* argv[])
{
	int arrLen;
	char** str;
    //int* arr;
	srand(time(NULL));
	arrLen = rand()%20 + 1;
	str = strInit(arrLen);
	forEachStr(str, str + arrLen - 1, &strAsign);
	strShow(str, arrLen);
	printf("\n");
	qsort(str, arrLen, sizeof(char*), &strLess);
	strShow(str, arrLen);
	printf("\n");

	/*
	forEach(&arr[0], &arr[arrLen - 1], &visit);

	printf("\n");

	sort(&arr[0], &arr[arrLen - 1], &myLess);

	forEach(&arr[0], &arr[arrLen - 1], &visit);
	printf("\n");
    */
	return 0;

	
}

int* arrayInit(int len)
{
	int* arr = (int*)calloc(len, sizeof(int));
	return arr;
}
void forEach(int* bg, int* end, void(*handle)(int*))
{
	for(; bg <= end; bg++)
	{
		(*handle)(bg);
	}
}
void sort(int* bg, int* end, int (*cmp)(int* left, int* right))
{
	int* pval;
	int key;
	int* start, *insert;
	for(start = bg + 1; start <= end; ++start)
	{
		key = *start;
		for(insert = start - 1; insert >= bg; --insert)
		{
			if((*cmp)(insert, &key))
			{
				break;
			}
			*(insert+1) = *insert;
		}
		*(insert+1) = key;
	}
}

void arrayDestroy(int* arr)
{
	free(arr);
}
void visit(int* pval)
{
	printf("%d ", *pval);
}
int myLess(const void*	left, const void* right)
{
	int* pleft = (int*)left;
	int* pright = (int*)right;
	if(*pleft < *pright)
	{
		return -1;
	}else if(*pleft == *pright)
	{
		return 0;
	}else
	{
	    return 1;
	}
}
int myGreat(int* left, int* right)
{
	int* pleft = (int*)left;
	int* pright = (int*)right;
	if(*pleft > *pright)
	{
		return 1;
	}else if(*pleft == *pright)
	{
		return 0;
	}else
	{
	    return -1;
	}

}
void init(int* pval)
{
	*pval = rand()%1000;
}

char** strInit(int len)
{
	char** arr = (char**)calloc(len, sizeof(char*));
	return arr;
}

void forEachStr(char** bg, char** end, char*(*handle)())
{
	for(; bg <= end; ++bg)
	{
		*bg = (*handle)();
	}
}

char* strAsign()
{
	int strLen = rand()%20 + 1;
	int i;
	char* pstr = (char*)calloc(strLen + 1, sizeof(char));
	for(i = 0; i < strLen; ++i)
	{
		if(rand()%2 == 0)
		{
			pstr[i] = 'a' + rand()%26;
		}else
		{
			pstr[i] = 'A' + rand()%26;
		}
	}
	pstr[i] = '\0';
	return	pstr;
}

int strLess(const void* left, const void* right)
{
	char** pleft = (char**)left;
	char** pright = (char**)right;
	if(strcmp(*pleft, *pright) < 0)
	{
		return -1;
	}else if(strcmp(*pleft, *pright) == 0)
	{
		return 0;
	}else
	{
		return 1;
	}
}

void strShow(char** arr, int len)
{
	int i;
	for(i = 0; i < len; ++i)
	{
		printf("[%d]: %s\n", i, arr[i]);
	}
}

/*************************************************************************
  > File Name: rvo_string.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Wed 18 Mar 2015 10:50:38 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
class String
{
	public:
		String();
    	String(const char* str);
		String(const String &another);
#if 1
		String(String &&rhs);
		String &operator=(String &&rhs);
#endif
		~String();
		String &operator=(const String &ths);

		String &operator+=(const String &rhs);
		String &operator+=(const char* rhs);

		friend String operator+(const String &lhs, 
				const String &rhs);
		friend std::ostream &operator << (std::ostream &os,
				const String &rhs);
			size_t size() const
			{
				return strlen(m_data);
			}
		const char *c_str() const
		{
			return m_data;
		}
	private:
		char* m_data;

};

String &String::operator+=(const String &rhs)
{
	char *tmp = new char[size() + rhs.size() + 1];
	strcpy(tmp, m_data);
	strcat(tmp, rhs.m_data);

	delete[] m_data;
	m_data = NULL;
	m_data = tmp;

	return *this;
}

String &String::operator+=(const char *rhs)
{
	*this += String(rhs);
	return *this;
}

inline String operator+(const String &lhs, const String &rhs)
{
	String ret(lhs);
	ret += rhs;
	return ret;
}

inline String operator+(const String &lhs, const char *rhs)
{
	return lhs + String(rhs);
}

inline String operator+(const char *lhs, const String &rhs)
{
	return String(lhs) + rhs;
}

std::ostream &operator <<(std::ostream &os,
		const String &rhs)
{
	os << rhs.m_data;
}

String::String() 
{
	std::cout << "String::String()" << std::endl;
	m_data=new char[1];
	m_data[0]='\0';
}

String::String(const char* str)
{
	std::cout << "String(const char *str) " << std::endl;
	if(str==NULL)
	{
		m_data=new char[1];
		m_data[0]='\0';
	}
	else
	{
		m_data=new char[strlen(str)+1];
		strcpy(m_data, str);
	}
}

String::String(const String &another)
{
	std::cout << "String(const String &rhs) " << std::endl;
	m_data=new char[strlen(another.m_data)+1];
	strcpy(m_data,another.m_data);
}

String& String::operator=(const String &rhs)
{
	std::cout << "String& operator=(const String &rhs)" << std::endl;
	if(this ==&rhs)
		return *this;
	delete []m_data;
	m_data=new char[strlen(rhs.m_data)+1];
	strcpy(m_data,rhs.m_data);
	return *this;
}

#if 1
String::String(String &&rhs)
{
	std::cout << "String(String &&rhs) " << std::endl;
	m_data = rhs.m_data;
	rhs.m_data = NULL;
}
String& String::operator=(String &&rhs)
{
	std::cout << "String &operator=(const String &&rhs) " 
		<< std::endl;
	if(this != &rhs)
	{
		delete [] m_data;
		m_data = rhs.m_data;
		rhs.m_data = NULL;
	}
	return *this;
}
#endif

String::~String()
{
	std::cout << "~String()" << std::endl;
	delete []m_data;
}


int main(void)
{
	String s1("hello");
	String s2;
	//String s2 = s1 + "a";
	s2 = s1 + "a";
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	std::cout << std::endl;

	return 0;
}







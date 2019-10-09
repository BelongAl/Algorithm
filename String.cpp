#pragma once
#define	_CRT_SECURE_NO_WARNINGS

#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

#define DEFAULTCAPA 16
#define COUNT(size)  ((size / DEFAULTCAPA+1 )* DEFAULTCAPA)

class String
{
	char * m_data;
	size_t m_size;
	size_t m_capacity;
public:
	String(const char *str = "") :
		m_capacity(DEFAULTCAPA),
		m_size(0)
	{
		if (nullptr == str)
		{
			m_size = 0;
		}
		else
		{
			m_size = strlen(str);
		}
		m_capacity = COUNT(m_size);
		m_data = new char[m_capacity];
		strncpy(m_data,str,m_size);
	}

	String(String &s)
	{
		m_capacity = s.m_capacity;
		m_size = s.m_size;
		m_data = new char[m_capacity];
		strcpy(m_data, s.m_data);
	}

	String(size_t n, char ch):
		m_size(n),
		m_capacity(COUNT(n))
	{
		m_data = new char[m_capacity];
		memset(m_data, ch, m_size);
	}

	~String()
	{
		if (m_data)
		{
			delete [] m_data;
			m_data = NULL;
		}
		m_size = m_capacity = 0;
	}

	void reserve(size_t size)
	{
		if (size >= m_capacity)
		{
			m_capacity = COUNT(size);
			m_data = (char*)realloc(m_data, m_capacity);
		}
	}

	size_t length()
	{
		return m_size;
	}

	size_t size()
	{
		return m_size;
	}

	size_t capacity()
	{
		return m_capacity - 1;
	}

	bool empty()
	{
		return m_size == 0;
	}

	void clear()
	{
		m_size = 0;
	}

	void resize(size_t size, char ch = 0)
	{
		reserve(size);
		if (m_size < size)
		{
			memset(m_data + m_size, ch, size - m_size);
		}
		m_size = size;
	}

	char & operator[](int i)
	{
		return m_data[i];
	}

	typedef char * iterator;

	iterator begin()
	{
		return m_data;
	}

	iterator end()
	{
		return m_data + m_size;
	}

	void push_back(char ch)
	{
		reserve(m_size);
		m_data[m_size] = ch;
		m_size++;
	}

	void pop_back()
	{
		if (!empty())
		{
			m_size--;
		}
	}

	String & operator+= (const char *str)
	{
		m_data[m_size] = '\0';
		m_size += strlen(str);
		reserve(m_size);
		strcat(m_data+m_size, str);
		return *this;
	}
	String & operator+= (String &s)
	{
		m_data[m_size] = '\0';
		m_size += s.m_size;
		reserve(m_size);
		strcat(m_data, s.m_data);
		return *this;
	}

	String & operator= (const char *str)
	{
		m_size = strlen(str);
		reserve(m_size);
		strcpy(m_data, str);
		return *this;
	}
	String & operator= (String &s)
	{
		m_size = s.m_size;
		reserve(m_size);
		strcpy(m_data, s.m_data);
		return *this;
	}

	const char* c_str()
	{
		return m_data;
	}

	size_t find(char ch, int pos = 0)
	{
		if (pos < 0 || pos >= m_size)
		{
			return -1;
		}
		char * tmp = strchr(m_data + pos, ch);
		if (tmp)
		{
			return tmp - m_data;
		}
		return -1;
	}
	size_t find(char *str, int pos = 0)
	{
		if (pos < 0 || pos >= m_size)
		{
			return -1;
		}
		char * tmp = strstr(m_data + pos, str);
		if (tmp)
		{
			return tmp - m_data;
		}
		return -1;
	}
	size_t find(const String & s, int pos = 0)
	{
		if (pos < 0 || pos >= m_size)
		{
			return -1;
		}
		char * tmp = strstr(m_data + pos,s.m_data);
		if (tmp)
		{
			return tmp - m_data;
		}
		return -1;
	}

	String operator+ (const char *str)const;
	String operator+ (const String &s)const;
	friend String operator+ (const char *str, const String &s);

	bool operator>  (const char *str)const;
	bool operator<  (const char *str)const;
	bool operator>= (const char *str)const;
	bool operator<= (const char *str)const;
	bool operator== (const char *str)const;
	bool operator!= (const char *str)const;

	bool operator>  (const String &s)const;
	bool operator<  (const String &s)const;
	bool operator>= (const String &s)const;
	bool operator<= (const String &s)const;
	bool operator== (const String &s)const;
	bool operator!= (const String &s)const;

	friend bool operator>  (const char *str, const String &s);
	friend bool operator<  (const char *str, const String &s);
	friend bool operator>= (const char *str, const String &s);
	friend bool operator<= (const char *str, const String &s);
	friend bool operator== (const char *str, const String &s);
	friend bool operator!= (const char *str, const String &s);

	String substr(size_t start, size_t num)
	{
		String tmp;
		tmp.resize(num);
		strncpy(tmp.m_data, m_data + start, num);
	}

	friend ostream & operator<<(ostream & os, String &s);
	friend istream & operator>>(istream & is, String &s);

};

/*rfind 三种*/

ostream & operator<<(ostream & os, String &s)
{
	int i;
	for (i = 0; i < s.m_size; i++)
	{
		os << s.m_data[i];
	}
	return os;
}
istream & operator>>(istream & is, String &s)
{
	char *tmp = new char[1024];
	is.getline(tmp, 1024);
	s.m_size = strlen(tmp);
	s.m_capacity = COUNT(s.m_size);
	strcpy(s.m_data, tmp);
	delete[]tmp;
	//delete[]s.m_data;
	//s.m_data = tmp;
	return is;
}

String String::operator+ (const char *str)const
{
	String res;
	res.m_size = m_size + strlen(str);
	res.reserve(res.m_size);
	strncpy(res.m_data, m_data, m_size);
	strcpy(res.m_data+m_size, str);
	return res;
}
String String::operator+ (const String &s)const
{
	String res;
	res.m_size = m_size + s.m_size;
	res.reserve(res.m_size);
	strncpy(res.m_data, m_data,m_size);
	strncpy(res.m_data, s.m_data,s.m_size);
	return res;
}
String operator+ (const char *str, const String &s)
{
	String res;
	res.m_size = strlen(str) + s.m_size;
	res.reserve(res.m_size);
	strcpy(res.m_data, str);
	strncat(res.m_data, s.m_data, s.m_size);
	return res;//调一次拷贝构造
}

bool String::operator>  (const char *str)const
{
	return  strncmp(m_data, str, m_size) > 0;
}
bool String::operator<  (const char *str)const
{
	int tmp = strncmp(m_data, str, m_size);
	if (!tmp && strlen(str) > m_size)
	{
		return true;
	}
	return tmp < 0;
}
bool String::operator>= (const char *str)const
{
	return !(*this < str);
}
bool String::operator<= (const char *str)const
{
	return !(*this > str);
}
bool String::operator== (const char *str)const
{
	int tmp = strncmp(m_data, str, m_size);
	if (!tmp && strlen(str) == m_size)
	{
		return true;
	}
	return false;
}
bool String::operator!= (const char *str)const
{
	return !(*this == str);
}



bool String::operator>  (const String &s)const
{
	int i;
	int minsize = m_size < s.m_size ? m_size : s.m_size;
	for (i = 0; i < minsize; i++)
	{
		if (m_data[i] > s.m_data[i])
		{
			return true;
		}
		else if(m_data[i] < s.m_data[i])
		{
			return false;
		}
	}
	return m_size > s.m_size;
}
bool String::operator<  (const String &s)const
{
	int i;
	int minsize = m_size < s.m_size ? m_size : s.m_size;
	for (i = 0; i < minsize; i++)
	{
		if (m_data[i] < s.m_data[i])
		{
			return true;
		}
		else if (m_data[i] < s.m_data[i])
		{
			return false;
		}
	}
	return m_size < s.m_size;
}
bool String::operator>= (const String &s)const
{
	return !(*this < s);
}
bool String::operator<= (const String &s)const
{
	return !(*this < s);
}
bool String::operator== (const String &s)const
{
	int i;
	int minsize = m_size < s.m_size ? m_size : s.m_size;
	for (i = 0; i < minsize; i++)
	{
		if (m_data[i] != s.m_data[i])
		{
			return false;
		}
	}
	return m_size == s.m_size;
}
bool String::operator!= (const String &s)const
{
	return !(*this == s);
}


bool operator>  (const char *str, const String &s)
{
	int tmp = strncmp(str,s.m_data,s.m_size);
	if (!tmp && strlen(str) > s.m_size)
	{
		return true;
	}
	return tmp > 0;
}
bool operator<  (const char *str, const String &s)
{
	return strncmp(str, s.m_data, s.m_size) < 0;
}
bool operator>= (const char *str, const String &s)
{
	return !(str < s);
}
bool operator<= (const char *str, const String &s)
{
	return !(str > s);
}
bool operator== (const char *str, const String &s)
{
	int tmp = strncmp(s.m_data, str,s.m_size);
	if (!tmp && strlen(str) == s.m_size)
	{
		return true;
	}
	return false;
}
bool operator!= (const char *str, const String &s)
{
	return !(str == s);
}


int main()
{
	String s1(nullptr);
	String s2(4, 'n');	
	String s3("BelongAl");
	

	system("pause");
	return 0;
}
//panda
//rfind
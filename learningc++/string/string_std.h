#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
public:                                 
   String(const char* cstr=0); // 将一个 c 风格地字符串转换为 一个 String 对象
   String(const String& str); // 一个拷贝构造函数，通过一个已经存在 String 对象来创建一个新的 String 对象，此拷贝深拷贝
   String& operator=(const String& str); // 拷贝赋值运算符号，接受一个 String 对象的引用，并且返回一个对象的引用，通常用于将一个对象赋值给一个已经存在的对象
   ~String(); // 析构函数，在对象生命周期结束之后，自动调用
   char* get_c_str() const { return m_data; } 
private:
   char* m_data;
};

#include <cstring>

inline
String::String(const char* cstr)
{
   if (cstr) {
      m_data = new char[strlen(cstr)+1];
      strcpy(m_data, cstr);
   }
   else {   
      m_data = new char[1];
      *m_data = '\0';
   }
}

inline
String::~String()
{
   delete[] m_data;
}

inline
String& String::operator=(const String& str)
{
   if (this == &str)
      return *this;

   delete[] m_data;
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
   return *this;
}

inline
String::String(const String& str)
{
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
}

#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const String& str)
{
   os << str.get_c_str();
   return os;
}

#endif
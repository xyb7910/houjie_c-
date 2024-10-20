class String {
private:
    // 定义数据
    char* m_data;
public:
    String(const char* cstr=0);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    char* get_c_str() const {return m_data;}
};

#include <cstring>

inline String::String(const char* cstr) {
    // 将一个 c 风格的字符串转换为 一个 String 对象
    // 如果 cstr 不为空
    if (cstr) {
        // 1. 申请空间 申请空间 + 1 是为了存储 c 字符串的结束标志 '\0'
        m_data = new char[strlen(cstr) + 1];
        // 2. 将 cstr 的 字符串 复制到 String 类中的 m_data
        strcpy(m_data, cstr); //  strcpy(destination, source);
    } else {
        // 字符串为空字符串，则存储一个 '\0'
        // 1.申请一个长度的空间
        m_data = new char[1];
        // 2.将 String 类的数据部分设置为 '\0'
        *m_data = '\0';
    }
};

// 实现拷贝构造函数
inline String::String(const String& str) {
    // 1.先申请空间
    m_data = new char [strlen(str.m_data) + 1];
    // 2.进行赋值
    strcpy(m_data, str.m_data);
}

// 返回引用是为了可以进行链式调用。说明返回值不会 local variable
inline String& String::operator=(const String& str) {
    // 考虑自己 赋值给自己 self assignment
    if (this == &str) {
        return *this;
    }
    // 两个不同字符串 之间的 互相赋值
    // 1.删除掉原有的空间
    delete[] m_data;
    // 2.申请大小为 lhs 操作数的空间大小
    m_data = new char[strlen(str.m_data) + 1];
    // 3.复制数据
    strcpy(m_data, str.m_data);
    return *this;
}

#include <iostream>
std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.get_c_str();
    return os;
}

inline String::~String() {
    delete[] m_data;
}


//
//  point.h
//  learningc++
//
//  Created by Ypb on 2024/10/2.
//

#ifndef point_h
#define point_h
class Point {
public:
    // 定义属性
    int x;
    int y;

    
    // 定义构造函数
    Point():x(0), y(0) {}
    Point(int x, int y): x(x), y(y) {}

    // 类内部 重载 -
    Point operator-(const Point& t) {
        return Point(x - t.x, y - t.y);
    }
    
    // 类内部 重载 后置 ++ 先求值后运算
    Point operator++(int) {
        Point tmp = *this;
        x ++;
        y ++;
        return tmp;
    }
};

// 类外部 重载 +
Point operator+(const Point& a, const Point& b) {
    return Point(a.x + b. y, a.y + b.y);
};

// 类外部 重载 前置 ++ 先运算后求值
Point operator++(Point& a) {
    a.x ++;
    a.y ++;
    return a;
}

// 类外部 重载 前置 -- 先运算后求值
Point operator--(Point& a) {
    a.x --;
    a.y --;
    return a;
}

//std::ostream& operator<<(std::ostream& os, const Point& p) {
//    os << "x = " << p.x << ", y = " << p.y << std::endl;
//    return os;
//}


#endif /* point_h */

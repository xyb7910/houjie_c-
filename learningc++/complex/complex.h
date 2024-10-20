//
//  complex.h
//  learningc++
//
//  Created by Ypb on 2024/9/28.
//

#ifndef complex_h
#define complex_h
class complex {
public:
    // 构造函数 推荐使用以下方式
    complex(double r = 0, double i = 0):re(r), im(i){}
    
    complex& operator += (const complex&);
    
    double real() const {return re;}
    double imag() const {return im;}
private:
    double re, im;
    
    friend complex& __doapl (complex*, const complex&);
};

inline double imag(const complex& x) {
    return x.imag();
}
#endif /* complex_h */

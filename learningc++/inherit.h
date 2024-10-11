//
//  inherit.h
//  learningc++
//
//  Created by Ypb on 2024/10/3.
//

#ifndef inherit_h
#define inherit_h
class BaseClass {
public:
    int publicField;
protected:
    int protectedField;
private:
    int privateField;
};

//class SubClass: public BaseClass {
//    void test() {
//        std::cout << publicField << std::endl;
//        std::cout << protectedField << std::endl;
//    }
//};

//class SubClass: protected BaseClass {
//    void test() {
//        std::cout << publicField << std::endl;
//        std::cout << protectedField << std::endl;
//    }
//};

#endif /* inherit_h */

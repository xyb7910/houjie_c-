//
//  animal.h
//  learningc++
//
//  Created by Ypb on 2024/10/3.
//

#ifndef animal_h
#define animal_h
class Animal {
public:
    int age;
//    Animal():age(0) {std::cout << "调用父类的无参构造函数" << std::endl;};
    
    explicit Animal(int age):age(age) {
        std::cout << "调用父类的有参构造函数" << std::endl;
    }
    
    ~Animal() {
        std::cout << "调用父类的析构函数" << std::endl;
    }
    
    void showAge() const {
        std::cout << "父类中的函数showAge被调用，age = " << age << std::endl;
    }
};

class Dog: public Animal {
public:
    explicit Dog(int age):Animal(age) {
        std::cout << "调用子类的有参构造函数" << std::endl;
    }
    ~Dog() {
        std::cout << "调用子类的析构函数" << std::endl;
    }
    
    void showAge() const {
        std::cout << "子类中的函数showAge被调用，age = " << age << std::endl;
    }
    
    void test() {
        std::cout << age << std::endl;
    }
};
#endif /* animal_h */

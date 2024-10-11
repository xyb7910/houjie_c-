//
//  person.h
//  learningc++
//
//  Created by Ypb on 2024/10/3.
//

#ifndef person_h
#define person_h

class Person{
public:
    int age;
    int score;
    int* p;
    
    Person():age(0), score(0), p(nullptr) {}
    
    //  浅拷贝构造函数
    Person(const Person& person) {
        std::cout << "拷贝构造函数执行了" << std::endl;
        age = person.age;
        score = person.score;
        p = new int(*person.p);
    }
    
    // 重载构造函数
    Person& operator=(const Person& person) {
        std::cout << "重载构造函数执行了" << std::endl;
        age = person.age;
        score = person.score;
        p = new int(*person.p);
        return *this;
    }
    
    ~Person() {
        std::cout <<  "析构函数执行了" << std::endl;
        if (p == nullptr) {
            delete p;
            p = nullptr;
        }
    }
};
 
#endif /* person_h */

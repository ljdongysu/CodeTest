#include <iostream>
using namespace std;

//class B;             // 这是前置声明(Forward declaration)
//class A
//{
//private:
//    B* b;
//
//public:
//    A(B* b):b(b)
//    {
//
//    }
//
//    void someMethod()
//    {
//        b->someMethod();                                                  // (1)
//    }
//};
//
//class B
//{
//private:
//
//public:
//    void someMethod();
//};
#include <vector>
struct A_TEST{
    std::vector<int> a;
    float b;
    int c;
};

class distortion{
public:
    static void remap();
    static void param();
    static int c;
    static A_TEST a;
    void dynic();
    static void staticfordynic(int &b)
    {
        std::cout<<b<<std::endl;
        b = 100;
        std::cout<<b<<std::endl;
    }
    int testa = 10;

};

#define RANGE_EXTEND(height) (((height) < 100) ? 0 : min((height), 200) / 10)
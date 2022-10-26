//利用内部类，实现单例模式的自动释放

#include <stdio.h>
#include <iostream>

#include "singleton.h"

class TestAAA{
private:
    TestAAA(){}
    static TestAAA* testaaa;
};

TestAAA *TestAAA::testaaa = new TestAAA();


int main()
{
    while (1)
    {std::cout<<1<<std::endl;}
}

//void threadFunc()
//{
//    Singleton *s1 = Singleton::getInstance();
//    printf("s1 = %p\n", s1);
//}
//
//
//int main()
//{
//    std::cout<<"project start()\n"<<std::endl;
//    Singleton *s1 = Singleton::getInstance();
//    Singleton *s2 = Singleton::getInstance();
//    printf("s1 = %p\n", s1);
//    printf("s2 = %p\n", s2);
//    s1->SingletonPrint();
//    s2->SingletonPrint();
//    s1 = NULL;
//    s2 = nullptr;
//
//    s1->SingletonPrint();
//    s2->SingletonPrint();
//    Singleton *s3 = NULL;
//    printf("s1 = %p\n", s3);
//    int *a = nullptr;
//    printf("a = %p\n", a);
//
//    s3->SingletonPrint();
//
//
//
//    return 0;
//}

//
// Created by indemind on 11/18/21.
//

#ifndef SINGLEDEMO_SINGLETON_H
#define SINGLEDEMO_SINGLETON_H
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Singleton{
    //单例模式的类
public:
    static Singleton *getInstance();//返回单例指针
    void SingletonPrint(){std::cout<<"print in Singleton"<<std::endl;}
private:
//    friend class AutoRelease;
    Singleton();  //构造函数和析构函数都得是private
    ~Singleton();
    static Singleton *_pInstance;

//private:
//    //应该设计为私有类，避免类外的其他成员使用
//    class AutoRelease{
//        //用来实现单例的自动释放的内部类
//        //应该保存在栈上，程序结束时自动回收单例的资源
//    public:
//        AutoRelease(){
//            cout << "AutoRelease()" << endl;
//        }
//        ~AutoRelease(){
//            cout << "~AutoRelease()" << endl;
//            if(Singleton::_pInstance == nullptr){
//                return;
//            }
//            delete Singleton::_pInstance;
//            Singleton::_pInstance = nullptr;
//        }
//    };
//
//private:
//    static AutoRelease _at;  //由于AutoRelease是private，所以对象应该放在静态区
};



#endif //SINGLEDEMO_SINGLETON_H

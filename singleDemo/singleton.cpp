//
// Created by indemind on 11/18/21.
//

#include "singleton.h"

#include <unistd.h>

Singleton *Singleton::_pInstance = new Singleton();  //饱汉模式 */
//饱汉模式多线程时不安全，需要使用饿汉模式，在程序跑起来前就生成单例对象
//Singleton *Singleton::_pInstance = Singleton::getInstance();//饿汉模式
//Singleton::AutoRelease Singleton::_at;

Singleton *Singleton::getInstance(){
    if(_pInstance == nullptr){
        _pInstance = new Singleton();

    }
    return _pInstance;
}

Singleton::Singleton()
{
    cout << "Begin singleton()\n";
//    sleep(2);
    std::cout<<"End Singleton()\n";
}

Singleton::~Singleton(){
    cout << "~Singleton()" << endl;
}

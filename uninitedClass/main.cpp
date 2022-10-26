#include <iostream>
class TestA{
public:
    TestA(){std::cout<<"start TestA"<<std::endl;}
//    TestA(int a):a(a){}
    void print(){
        std::cout<<"TestA::print(): "<<std::endl;
    }
    int a = 10;
};

int main()
{

    bool flag = false & true;
//    flag = 3 & 0;
    std::cout<<flag<<std::endl;
    return 0;
//    TestA *cc = new TestA();   // Test cc;
    TestA *testa ;//= new TestA(); //TestA *testa; also run successfully;
    testa->print();
    delete(testa);
    testa->print();
    testa = nullptr;
    testa->print();
//    TestA cc;

    return 0;
}

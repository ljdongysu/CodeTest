
#include <iostream>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <queue>
#include <thread>
using namespace std;

//#define NUM_THREADS 5
//queue<int > queuqTest;
//// 线程的运行函数
//void* say_hello(void* args)
//{
//    while (true)
//    {
//        if (queuqTest.empty())
//        {
//            sleep(1);
//            continue;
//        }
//        std::cout<<queuqTest.size()<<std::endl;
//        cout << "Hello Runoob！" << endl;
//        int atest = queuqTest.front();
//        std::cout <<"atest: "<< atest << std::endl;
//        queuqTest.pop();
//        sleep(4);
////        return 0;
//    }
//}
//
//int main()
//{
//    for (int i = 0; i < 50; ++i)
//    {
//        queuqTest.push(i);
//    }
//    std::cout<<"queuqTest.size(): "<<queuqTest.size()<<std::endl;
//    std::cout<<"start thread: "<<std::endl;
//    pthread_t tids;
//    pthread_create(&tids, NULL, say_hello, NULL);
//
//    pthread_detach(tids);
//
//    for (int i = 100; i < 1000; ++i)
//    {
//        queuqTest.push(i);
//        std::cout<<"push: "<< i <<std::endl;
//        sleep(1);
//    }
//
//    pthread_exit(NULL);
//}
//

class Student
{
public:
    Student()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~Student()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    Student(const Student& right)
    {
        std::cout << "Student(const Student& right)" << std::endl;
    }
    void Print() const
    {
        std::cout<<"pid = "<<getpid() <<std::endl;
        std::cout<<"tid = "<<std::this_thread::get_id <<std::endl;

        std::cout << m_count << std::endl;
    }
    int m_count = 0;
};

void DoThings(const Student& s)
{
    std::cout<<"a"<<std::endl;
    std::cout<<"pid = "<<getpid() <<std::endl;
    std::cout<<"tid = "<<std::this_thread::get_id <<std::endl;

    s.Print();
    sleep(1);
}
int main()
{
    Student s;

    std::cout<<"pid = "<<getpid() <<std::endl;
    std::cout<<"tid = "<<std::this_thread::get_id <<std::endl;

    std::thread t(DoThings, s);
//    t.detach();
    std::cout<<"pid = "<<getpid() <<std::endl;

    std::cout<<"tid = "<<std::this_thread::get_id <<std::endl;


    s.m_count++;
    sleep(3);
    t.join();


    std::cout << "Hello World!\n";
    return 0;
}
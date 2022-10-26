#include <iostream>
#include <unistd.h>
#include <list>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define MAX 100
void randInt()
{

    for(int i = 0; i < 10; ++i)
    {
        usleep(500000);
        srand((unsigned ) time(NULL));
        std::cout<<rand()%MAX<<std::endl;
    }
}

struct AAA{
    AAA(){}
    AAA(int a):a(a){}
    void Print(){std::cout<<"a: "<<a<<std::endl;}
    int a;
};
std::list<AAA> aList;

void testB(const AAA &a)
{

    AAA b = a;
    b.Print();
}


void testA(const AAA &a)
{
    testB(a);
}

void testfree(const int &a)
{
    while(true)
    {
        std::cout<<a<<std::endl;
        sleep(1);
    }
}

//int main()
//{
//    aList.push_back(AAA(1));
//    aList.push_back(AAA(2));
//    aList.push_back(AAA(3));
//    randInt();
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
//#include <vector>
#include <list>

#include <iostream>
#include <functional>

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Object
{
    enum ClassID
    {
        UNKNOWN = 0, PERSON, ESCALATOR, HANDRAILS, PERSON_DUMMY
    };
    ClassID classID = UNKNOWN;
};

int main()
{
    Object object;
    object.classID = Object::ClassID::PERSON;
    int a = 0;
    switch (a)
    {
        case (Object::ClassID::UNKNOWN -1):
            std::cout << "Object::ClassID::UNKNOWN" << std::endl;
            break;
        case (Object::ClassID::PERSON - 1):
            std::cout << "Object::ClassID::PERSON" << std::endl;
            break;

        case (Object::ClassID::ESCALATOR - 1):
            std::cout << "Object::ClassID::ESCALATOR" << std::endl;
            break;
        case (Object::ClassID::HANDRAILS - 1):
            std::cout << "Object::ClassID::HANDRAILS" << std::endl;
            break;
        default:
            std::cout << "default"<< std::endl;

    }
    if (Object::ClassID::UNKNOWN == 0)
    {
        std::cout << "Object::ClassID::UNKNOWN == 0";
    }
    else
    {
        std::cout << "Object::ClassID::UNKNOWN != 0";
    }


    return 0;
    std::string person = "class_id = 0, name =          person, count = (    476/    608), ap = 61.67%   (TP = 389, FP = 87, FN = 219, precision = 81.7%, recall = 64.0%, F1 = 71.8%, avg_iou = 65.0%)";
    std::string escalator = "class_id = 1, name =       escalator, count = (    749/   1883), ap = 38.36%   (TP = 731, FP = 18, FN = 1152, precision = 97.6%, recall = 38.8%, F1 = 55.5%, avg_iou = 77.3%)";
    std::string escalator_handrails = "class_id = 2, name =escalator_handrails, count = (   2617/   5550), ap = 45.96%   (TP = 2571, FP = 46, FN = 2979, precision = 98.2%, recall = 46.3%, F1 = 63.0%, avg_iou = 75.3%)";



// 写文件
    ofstream outFile;
    if (outFile.is_open())
    {
        std::cout<<"outFile open"<<std::endl;
    }
    else
    {
        std::cout<<"outFile not open"<<std::endl;
    }
    outFile.open("data.csv", ios::out); // 打开模式可省略
    if (outFile.is_open())
    {
        std::cout<<"outFile open"<<std::endl;
    }
    else
    {
        std::cout<<"outFile not open"<<std::endl;
    }
    outFile <<"model" << ',' << "class" << ',' << "TP" <<','<<"FP"<<','<<"FN"<<','<<"F1"<<','<<"Ap"<<','<<"Percision"<<','<<"Recall"<< endl;
    outFile<<","<<","<<"class"<<","<<"TP"<<","<<"FP"<<","<<"FN"<<","<<"F1"<<","<<"Ap"<<","<<"Precision"<<","<<"Recall"<<std::endl;

    outFile<<1<<2<<3<<4<<","<<std::endl;
//    std::string name;
    int TP=0,FP=0,FN=0;
    int class_id = 0;
    float F1=0,Ap=0.567,Percision=0, Recall = 0;
    outFile<<","<<F1<<","<<setw(4)<<Ap*100<<"%"<<std::endl;
    char *name[3];

    sscanf(person.c_str(),"class_id =%2d, name =          person, count = (%7d/%7d), ap = %2.2f%%   "
                          "(TP = %d, FP = %d, FN = %d, precision = %2.1f%%, recall = %2.1f%%, F1 = %2.1f%%, avg_iou = %2.1f%%) "
            , &class_id,&TP,&TP,&Ap,&TP,&FP,&FN,&Percision,&Recall,&F1,&F1);

    outFile.close();

    // 读文件
    ifstream inFile("data.csv", ios::in);
    string lineStr;
    vector<vector<string>> strArray;
    while (getline(inFile, lineStr))
    {
        // 打印整行字符串
        cout << lineStr << endl;
        // 存成二维表结构
        stringstream ss(lineStr);
        string str;
        vector<string> lineArray;
        // 按照逗号分隔
        while (getline(ss, str, ','))
            lineArray.push_back(str);
        strArray.push_back(lineArray);
    }

    getchar();
    return 0;

}
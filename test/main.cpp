#include <iostream>
#include <string>
#include "forward.h"
#include <unistd.h>
#include <sstream>
#include <map>
#include <cstring>
#include <string>

//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    std::string a = "abc";
//    std::string b = "abcd";
//    if (a == b)
//    {
//        std::cout<<"abc == abcd"<<std::endl;
//    }
//    else
//    {
//        std::cout<<"abc != abcd"<<std::endl;
//    }
//    B b1;
//    A a1(&b1);
//    a1.someMethod();
//
//    return 0;
//}
#include <vector>
#include <functional>   // std::minus
#include <numeric>      // std::accumulate
#include <math.h>

#define COUT std::cout<<"cout" \
<<"aaa"                        \
//\\aaa
#define COUT_1 std::cout<<"cout_1" \
<<"bbb"
struct B_TEST{
    int a;
};


B_TEST SumPointLocation(const B_TEST &pX, const B_TEST &pY)
{
    auto sum = pX;
    sum.a = pX.a + pY.a;
    std::cout<<sum.a<<std::endl;
    return sum;
}
#include <string>

int Dir(int a,int b)
{
    if (a>b)
    {
        return 5;
    }
    else if(a < b)
    {
        return -5;
    }
    return 0;
}

bool testboool(bool flag)
{
    if (!flag)
    {
        return flag;
    }
    else
    {
        flag = true;
    }
    return true;
}

void printString(const std::string info)
{
    std::cout<<info<<std::endl;
}

#include <unistd.h>
#include <algorithm>
const int EXTEND_PERSON = 15; // 10 pixel
const int EXTEND_ESCALATOR = 25; // 10 pixel
const int EXTEND_HANDRAILS = 30; // 10 pixel
const int EXTEND_STEP = 20; // 10 pixel

enum ClassID
{
    PERSON = 0,
    ESCALATOR,
    ESCALATOR_HANDRAILS,
    PERSON_DUMMY,
    ESCALATOR_MODEL,
    ESCALATOR_HANDRAILS_MODEL,
    UNKNOWN
};
struct BoxInfo
{
    int x;
    int y;
    // in some case, float type is needed
    int width;
    int height;
    ClassID classID = UNKNOWN;
    bool IsEscalator() const
    {
        return this->classID == ESCALATOR or this->classID == ESCALATOR_MODEL;
    }

    bool IsEscalatorHandrails() const
    {
        return this->classID == ESCALATOR_HANDRAILS or
               this->classID == ESCALATOR_HANDRAILS_MODEL;
    }

    bool IsPerson() const
    {
        return this->classID == PERSON or this->classID == PERSON_DUMMY;
    }
};

const int HEIGHT = 400;
#include <fstream>
void GetExtendY(std::ofstream &outFile, BoxInfo box,  const int baseExtend = 0)
{
    double height = box.height;
    double extentHeight = baseExtend - RANGE_EXTEND(HEIGHT - (box.y + box.height));


    if (box.IsEscalator()) height += EXTEND_ESCALATOR + extentHeight;
    else if (box.IsPerson()) height += EXTEND_PERSON + extentHeight;
    else if (box.IsEscalatorHandrails()) height += EXTEND_HANDRAILS + extentHeight;
    std::cout<< "before y: " << box.y + box.height
                          << " last y: " << box.y + height << " dist:  " << height - box.height << std::endl;
    outFile <<box.y + box.height <<","<<box.y + height<<","<<height - box.height<<std::endl;
}

void OriginalExtend()
{
    std::ofstream outFile;
    outFile.open("result.csv", std::ios::out);
    outFile<< "before,"<<"last,"<<""<<std::endl;
    for (int i = 0; i < 200; ++i)
    {
        BoxInfo box;
        box.y = 200 + i;
        box.height = 2;
        box.classID = ESCALATOR_HANDRAILS;
        GetExtendY(outFile, box);
    }
    outFile.close();

}

void GetHeightDepth(std::string file, map<int, float> &heightDepth)
{
    std::ifstream inFile;

    inFile.open(file, std::ios::in);
    std::string line;
    while (getline(inFile,line))
    {
        string field1,field2,field3,field4;
        istringstream sin (line);

        getline(sin,field1,',');
        std::cout<<field1<<" ";

        getline(sin,field2,',');
        std::cout<<field2<<" ";

        getline(sin,field3,',');
        std::cout<<field3<<" ";

        if (field1.empty() or field3.empty())
        {
            ;
        }
        else
        {
            heightDepth.insert(pair<int, float>(std::atoi(field1.c_str()), std::atof(field3.c_str())));
        }

        std::cout<<endl;

    }
    inFile.close();
}

void GetNearest(map<int, float> heightDepth, float depth, float &nearDepth, float &nearY)
{
    map<int, float>::iterator  iter = heightDepth.begin();
    float nearest = 1000;
    while (iter!= heightDepth.end())
    {
        if (abs(iter->second - depth) < nearest)
        {
            nearest = abs(iter->second - depth);
            nearY = iter->first;
            nearDepth = iter->second;
        }
        iter++;
    }
}

void RemoveEnd(std::string &s)
{
    size_t n = s.find_last_not_of("\r");
    if (n != string::npos)
    {
        s.erase(n+1, s.size() - 1);
    }
}

void GetResult(map<int, float> heightDepth, std::string file)
{
    std::ifstream inFile;
    std::ofstream outFile;

    outFile.open("result1.csv", std::ios::out);
    inFile.open(file, std::ios::in);
    std::string line;

    getline(inFile,line);
    outFile << line;
    while (getline(inFile,line))
    {
        string field1,field2,field3,field4;
        istringstream sin (line);

        getline(sin,field1,',');
        std::cout<<field1<<" ";

        getline(sin,field2,',');
        std::cout<<field2<<" ";

        getline(sin,field3,',');
        std::cout<<field3<<" ";

        if (field1.empty() or field2.empty() or field3.empty())
        {
            continue;
        }
        else if ((field1.size() == 1 and field1[0] == '\r') or
                (field2.size() == 1 and field2[0] == '\r') or
                (field3.size() == 1 and field3[0] == '\r') )
        {
            continue;
        }
        else if (std::atof(field3.c_str()) < 0.8)
        {
            continue;
        }
        else
        {
            RemoveEnd(field3);
            std::cout<<field3.size()<<std::endl;
            RemoveEnd(field2);
            RemoveEnd(field1);

            float nearDepth, nearY;
            GetNearest(heightDepth, std::atof(field3.c_str()), nearDepth, nearY);
            outFile << field1<< "," << field2<< "," << field3 << "," << nearDepth <<", "<< nearY <<std::endl;
        }

        std::cout<<endl;

    }
    outFile.close();

    inFile.close();
}

int main(int argc, char* argv[])
{
    atanf32(2);
    double x = 1;
    for (int i = 0 ; i <= 100000; ++i)
    {
        double y = i/100000.0;
        double angleAtanf = atanf(y/x);
        double angleAtanf32 = atanf32(y/x);
        std::cout<<"angleATanF: "<<angleAtanf<<", angleATanF32: "<<angleAtanf32<<", dis: "<< angleAtanf - angleAtanf32 <<std::endl;
        std::cout<<"angleATanF: "<<angleAtanf*180/M_PI<<", angleATanF32: "<<angleAtanf32*180/M_PI<<std::endl;


    }
    std::cout<<atanf(1)*180/M_PI<<std::endl;
    return 0;
    map<int, float> heightDepth;
    GetHeightDepth("/data/test_group/2022_0402_V1.10.12_dev/2022_04_02/3-4shuju1126/20211126_shunyi_3/3-4shuju1126_20211126_shunyi_3.csv", heightDepth);

    float a,b;
    GetNearest(heightDepth, 10, a, b);
    std::cout<<a<<" "<<b<<std::endl;

    GetResult(heightDepth, "/data/test_group/2022_0402_V1.10.12_dev/2022_04_02/3-4shuju1126/20211126_shunyi_3/class_y_lidar.csv");
//    OriginalExtend();
}

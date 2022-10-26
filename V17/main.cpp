#include <iostream>
#include <any>
#include "memory.h"
#include "map"
#include <Eigen/Core>

struct A
{
//    A(int a, int b):a(a),b(b){}
    int a = 10;
    double b = 20;

    bool operator<(const struct A &a)
    {
        return this->a < a.a;
    }

    friend bool operator<(const struct A &k1, const struct A &k2);
};

inline bool operator<(const struct A &k1, const struct A &k2)
{
    return k1.a < k2.a || (k1.a == k2.a && k1.b < k2.b);
}

struct B
{
    double b = 20;
    int a = 10;

};


namespace psl
{
    enum class Resolution : uint8_t
    {
        RES_640X400, RES_1280X800, LAST
    };
    enum StatusOperate
    {
        INITED_DL = 0, UPDATE_DL, //  [dl]
        INITED_SLAM, UPDATE_SLAM, //  [slam]
    };
}
namespace swr
{
    enum class Resolution : uint8_t
    {
        RES_640X400, RES_1280X800, LAST
    };
    enum StatusOperate
    {
        INITED_DL = 0, UPDATE_DL, //  [dl]
        INITED_SLAM, UPDATE_SLAM, //  [slam]
    };
}


class TestA
{
public:
    TestA()
    { std::cout << "start TestA" << std::endl; }

    void print()
    {
        std::cout << "TestA::print(): " << a << std::endl;//此处输出a成员值
    }

    int a = 10;
};

void COnvert(TestA &a, const TestA &b)
{
    a = b;
}

#include <vector>

class AA
{
public:
    virtual void Print()
    { std::cout << "AA\n"; }
};

class BB : public AA
{
public:
    void Print()
    { std::cout << "BB\n"; }
};

using namespace Eigen;
using namespace std;

#include <numeric>    //iota头文件

template<typename T>
vector<size_t> SortIndexes(const vector<T> &v)
{
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&v](size_t i1, size_t i2)
         { return v[i1] < v[i2]; });//< is ascending; > is descending
    return idx;
}


class ErrorMessage
{
private:
    ErrorMessage(const ErrorMessage &) = delete;

    ErrorMessage()
    {};

    void operator=(const ErrorMessage &) = delete;

    class AutoRelease
    {
    public:
        AutoRelease()
        {}

        ~AutoRelease()
        {
            if (errorMessage != nullptr)
            {
                delete errorMessage;
            }
        }
    };

public:
    static ErrorMessage *GetInstance()
    {
        std::cout << "GetInstacne()\n";
        return errorMessage;
    }


protected:
    static ErrorMessage *errorMessage;
    static AutoRelease autoRelease;
};

ErrorMessage *ErrorMessage::errorMessage = new ErrorMessage();

ErrorMessage::AutoRelease ErrorMessage::autoRelease;

int main1()
{

    return 0;
    const vector<int> aaaaa = {10, 30, 20, 4};
    vector<size_t> indexes = SortIndexes(aaaaa);

    for (auto aa: aaaaa)
    {
        std::cout << aa << " , ";
    }
    std::cout << endl;
    for (auto index: indexes)
    {
        std::cout << index << " , ";
    }
    std::cout << std::endl;
    return 0;
    MatrixXd test = MatrixXd(2, 2);
    MatrixXd test1 = MatrixXd(2, 2);

    Vector2d l1(10, 20);
    Vector2d l2(30, 40);

    test << l1, l2;

    test1 << 0, 1, 2, 3;
    auto temp = test * test1;
    std::cout << temp << std::endl;

    std::cout << test(0, 0) << " , " << test(0, 1) << std::endl;
    std::cout << test << std::endl;
    return 0;
    std::vector<std::vector<bool>> statuses;
    statuses.push_back({true, true, false, false});

    std::vector<int> ids;
    ids.push_back(1);
    ids.push_back(1);
    ids.push_back(2);
    ids.push_back(3);
    ids.push_back(3);
    ids.push_back(4);


    for (auto it = ids.begin(); it != ids.end();)
    {
        if ((*it) > 2)
        {
            ids.erase(it);
            continue;
        }
        it++;
    }
    auto iiii = std::find(ids.begin(), ids.end(), 3);
    if (find(ids.begin(), ids.end(), 3) != ids.end());
    std::vector<std::vector<double>> iouMatrix;
    iouMatrix.resize(0, std::vector<double>(0, 0));
    std::cout << iouMatrix.size() << std::endl;
    iouMatrix.resize(1, std::vector<double>(5, 0));

    std::cout << iouMatrix[0].size() << std::endl;
    return 0;

    std::vector<int> one = {1};
    for (auto it = one.begin(); it != one.end();)
    {
        it = one.erase(it);
    }
    return 0;
    std::vector<int> abcdefg = {1, 2, 3, 4, 5};
    std::vector<int> abcdefg1 = {-1, -1};
    abcdefg1 = abcdefg;
    abcdefg[0] = 100;
    std::cout << abcdefg[-1];
    return 0;
    TestA *aa = nullptr;
    TestA bb;


    psl::StatusOperate R1 = psl::StatusOperate::INITED_DL;
    int R2 = psl::StatusOperate::INITED_DL;
    if (R1 == 0)
    {
        std::cout << "0" << std::endl;
    }



//    float ranges[2048];
//    for (int i = 0; i < 10; ++i)
//    {
//        ranges[i] = i * 100;
//    }
//    std::vector<float> ranges1(10);
//    for (int i = 0; i < 10; ++i)
//    {
//        ranges1.push_back(1);
//    }
//
//    memcpy(&ranges1[0], ranges, 10 * sizeof(float ));
//
//     for (int i = 0 ; i < 10; ++i)
//     {
//         std::cout<< ranges1[i];
//     }
//
//
//
//    std::map<int , int> camera1;
//    camera1[1] = 2;
//    bool flag = camera1.find(1) != camera1.end();
//    std::cout << flag <<std::endl;
    return 0;

    std::any i = 42;
    const auto ptr = std::any_cast<int>(&i);
    if (ptr)
    {
        std::cout << ptr << std::endl;
    }

    A a;
    B b;
    std::cout << b.a << "   " << b.b << std::endl;

    memcpy(&b, &a, sizeof(A));

    std::cout << b.a << "   " << b.b << std::endl;


    std::map<int, A> camera;
    camera[0] = a;
    std::cout << camera.size() << std::endl;
    camera[1] = a;
    std::cout << camera.size() << std::endl;
    for (int i = 2; i < 100; ++i)
    {
        camera[i] = a;
    }
    std::cout << camera.size() << std::endl;
    std::cout << sizeof(camera) << std::endl;
    std::cout << sizeof(std::map<int, A>) << std::endl;

    psl::Resolution r1 = psl::Resolution::LAST;
//    swr::Resolution r2 = psl::Resolution::LAST;


    std::map<psl::Resolution, int> psl1;
    std::map<psl::Resolution, int> psl2;
    psl1[r1] = 10;
    psl1[psl::Resolution::RES_640X400] = 20;

//    psl2[swr::Resolution::RES_640X400] = 100;
//    psl2[swr::Resolution::RES_1280X800] = 200;
    std::cout << "psl1.size: " << psl1.size() << "\tpsl2.size: " << psl2.size() << std::endl;

//    memcpy(&psl2, &psl1, sizeof(std::map<psl::Resolution, int>));
    std::cout << sizeof(psl1) << "   " << sizeof(psl2) << std::endl;
    std::cout << "psl1.size: " << psl1.size() << "\tpsl2.size: " << psl2.size() << std::endl;
    for (auto iter = psl1.begin(); iter != psl1.end(); iter++)
    {
        std::cout << "for\n";
        std::cout << iter->second << std::endl;
        if (iter->first == psl::Resolution::LAST)
        {
            std::cout << "last: " << std::endl;
        }
    }
//
//    for (auto iter = psl2.begin(); iter != psl2.end(); iter++)
//    {
//        std::cout<<"for\n";
//        std::cout<<iter->second<<std::endl;
//    }


//    std::map<A, B> ab;
//    std::map<int,double> cd;
//    cd[0] = 10;
//        memcpy(&cd,&ab,sizeof(ab));
//    for (auto iter = cd.begin(); iter != cd.end(); iter++)
//    {
//        std::cout<<iter->first<<std::endl;
//    }
//    ab[a] = b;
//    A c;
//    ab[c]= b;
//
//    std::map<A, B> ef;



//    auto iter = cd.begin();
//    while (iter != cd.end())





    return 0;
}


///**
// * self defined struct as the key of map in c++
// */
//#include "map"
//#include "iostream"
//using namespace std;
//struct K {
//    int n1, n2;
//    K(int i, int j): n1(i), n2(j) {}
//    // the operator < defines the operation used in map
//    friend bool operator < (const struct K &k1, const struct K &k2);
//};
//
//inline bool operator < (const struct K &k1, const struct K &k2) {
//    return k1.n1 < k2.n1 || (k1.n1==k2.n1 && k1.n2<k2.n2);
//}
//
//int main() {
//    map<K, int> m;
//    map<K, int>::iterator it;
//    K k1(1, 1);
//    m.insert(make_pair(k1, 2));    // insert the value
//    it = m.find(k1);
//    if (it!=m.end()) cout << it->second << endl;    // fetch the value
//}
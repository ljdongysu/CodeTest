//
// Created by indemind on 11/8/21.
//

#ifndef RUNGTEST_RUNTEST_H
#define RUNGTEST_RUNTEST_H
#include "forcePublic.h"


class runtest {
    int a;
    int add(int a, int b);
public:
    void show_a();

    runtest(){}
    runtest(int a):a(a){}
    friend int seta(int a, runtest &runtest1);

};


#endif //RUNGTEST_RUNTEST_H

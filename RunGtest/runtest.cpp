//
// Created by indemind on 11/8/21.
//

#include "runtest.h"
#include <iostream>
int runtest::add(int a, int b) {return a + b;}
void runtest::show_a() {std::cout<<"runtest.a: "<<a<<std::endl;}
int seta(int a, runtest &runtest1)
{
    runtest1.a = a;

    return runtest1.a;
}
//
// Created by indemind on 11/1/21.
//

#include "forward.h"
int distortion::c = 0;
A_TEST distortion::a = {};
//void B::someMethod()
//{
//    cout << "something happened..." << endl;
//}
void  distortion::remap()
{
    std::cout<<"c: "<<c<<std::endl;
}
void distortion::param()
{
    std::cout<<"in param c:"<<c<<std::endl;
    std::cout<<a.a.size()<<std::endl;
}
void distortion::dynic()
{
    std::cout<<testa<<std::endl;

    staticfordynic(testa);
    std::cout<<testa<<std::endl;

}

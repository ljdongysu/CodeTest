#include <iostream>

int test()
{
    try
    {
    int a = 0;
    int b = 1;
    std::cout << "1" << std::endl;
    if (a == 0) {
        throw -1;
    }
    std::cout<<"last in test"<<std::endl;
    }
    catch (...)
    {
        std::cout<<"in catch"<<std::endl;
    }

}

int main() {
    test();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

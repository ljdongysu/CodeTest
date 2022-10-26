//
// Created by indemind on 5/12/22.
//
#include <iostream>
#include <chrono>
#include <sys/time.h>

using namespace std;
static inline uint64_t getCurrentMicroseconds(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

class TimeIncPrinter{
public:
    TimeIncPrinter(){
        _start = getCurrentMicroseconds();
    }
    ~TimeIncPrinter(){
        cout << (getCurrentMicroseconds() - _start) / 1000 << endl;
    }

private:
    uint64_t _start;
};
int main() {

    std::string image = "/data/RBN100/20220724/20220724_00/data_dl_20220724_0/20220724_0205/15_1658599515745013.jpg";
    int id = image.rfind('/');
    std::string image1 = image.substr(0,id) + "/cam0" + image.substr(id);
    std::cout <<image1<<std::endl;
    return 0;

    auto s0 = std::chrono::system_clock::now().time_since_epoch().count();
    auto s1 = std::chrono::steady_clock::now().time_since_epoch().count();
    auto s2 = getCurrentMicroseconds();
    uint64_t ret;
    cout << s0 << " " << s1 << " " << s2 << endl;
    {
        TimeIncPrinter printer;
        for(int i = 0; i < 1000 * 10000; ++i){
            ret = std::chrono::system_clock::now().time_since_epoch().count();
        }
    }

    {
        TimeIncPrinter printer;
        for(int i = 0; i < 1000 * 10000; ++i) {
            ret = std::chrono::steady_clock::now().time_since_epoch().count();
        }
    }

    {
        TimeIncPrinter printer;
        for(int i = 0; i < 1000 * 10000; ++i) {
            ret = getCurrentMicroseconds();
        }
    }

    auto e0 = std::chrono::system_clock::now().time_since_epoch().count();
    auto e1 = std::chrono::steady_clock::now().time_since_epoch().count();
    auto e2 = getCurrentMicroseconds();

    cout << e0 - s0 << " " << e1 - s1 << " " << e2 - s2 << endl;

    auto tp_end = std::chrono::system_clock::now();
    auto tp_end1 = std::chrono::steady_clock::now();
    auto tp_end3 = getCurrentMicroseconds();
    return 0;
}

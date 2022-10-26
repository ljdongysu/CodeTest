//#include <iostream>
//#include <opencv2/opencv.hpp>
//struct Log
//{
//    int end; // for function end (debug)
//    int debug; // for debug program
//    int time; // for timing
//    int test; // for test(time, distance, mAP)
//    int status; // for release log
//};
//
////Log g_log;
//
//int main()
//{
//    std::cout << "Hello, World!" << std::endl;
////    std::cout<<g_log.end<<std::endl;
//    cv::Mat imageShow = cv::imread("/data/test_data/3-4shuju1126/20211126_shunyi_0/20210223_1114/41_1614050081783353.jpg");
//    cv::imshow("1",imageShow);
//    cv::waitKey(0);
//
//
//    return 0;
//}
#include <boost/lexical_cast.hpp>
#include <iostream>
int main()
{
    using boost::lexical_cast;
    int a = lexical_cast<int>("123");
    double b = lexical_cast<double>("123.12");
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    return 0;
}

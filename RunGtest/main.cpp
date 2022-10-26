#include <iostream>
#include "gtest/gtest.h"
#include "runtest.h"

#include <time.h>

#define FREE(x) do{if (nullptr != (x)) {free((x)); (x) = nullptr;}}while(0)


int add(int a, int b)
{
    return a + b;
}


TEST(TestCase,test1 ){
//    ASSERT_EQ(12,add(3,8));

//    srand(11);
std::cout<<"test"<<std::endl;
for (int i = 0; i < 3;++i)
{
    std::cout << rand() << std::endl;
    std::cout << rand() << std::endl;
}


}

TEST(TestCase,test2){
    EXPECT_EQ(5,add(2,3));
    std::cout<<"time(NLUU): "<<time(NULL)<<std::endl;
    for (int i = 0; i < 3;++i)
    {
        std::cout << rand() << std::endl;
        std::cout << rand() << std::endl;
    }
}

TEST(TestCase,test3){
    EXPECT_EQ(3,add(1,2));
}

runtest c(100);


TEST(TestCase,test4){
    EXPECT_EQ(10,seta(10,c));
}

//TEST(TestCase,test5)
//{
//    runtest d(200);
//
//    EXPECT_EQ(10,d.add(2,8));
//
//}

struct BoxSortable{
    int index;
    int classId;
    float **probs;
};

int main(int argc, char **argv)
{
//    runtest a(10);
//    a.show_a();
//
//    seta(20,a);
//    a.show_a();
//
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();


//    float **ptr =(float**) calloc(2,sizeof(float*));
//    ptr[0] = (float*) calloc(4,sizeof(float));
//    ptr[1] = (float*) calloc(3,sizeof(float));
//    BoxSortable *s = (BoxSortable *) calloc(2, sizeof(BoxSortable));
//
//    s[0].probs = ptr;
//    s[1].probs = ptr;
//
//    free(s);
//    free(ptr[0]);
//    free(ptr[1]);
//    FREE(ptr);
//    FREE(ptr);

//    std::cout<<"sizeof(int): "<<sizeof(int)<<std::endl;
//    std::cout<<"sizeof(int *): "<<sizeof(int*)<<std::endl;
//    std::cout<<"sizeof(float): "<<sizeof(float )<<std::endl;
//    std::cout<<"sizeof(float *): "<<sizeof(float*)<<std::endl;
//    std::cout<<"sizeof(char): "<<sizeof(char )<<std::endl;
//    std::cout<<"sizeof(char *): "<<sizeof(char *)<<std::endl;
//    float *ptr = (float *) calloc(2,sizeof (char ));// 故意写为char结果正常，内存地址和float运算也正常
//    ptr[0] = 30.0;
//    ptr[1] = 60.0;
//    printf("ptr[1] - ptr[0] = %f\n",ptr[1] - ptr[0]);
//    std::cout<<"static_cast<const void *>(&ptr[0]): "<<static_cast<const void *>(&ptr[0])<<std::endl;
//    std::cout<<"static_cast<const void *>(&ptr[1]): "<<static_cast<const void *>(&ptr[1])<<std::endl;
//
//    float **pptr = (float **) calloc(2,sizeof (float* ));
//
//    std::cout<<"static_cast<const void *>(&ptr[0]): "<<static_cast<const void *>(&pptr[0])<<std::endl;
//    std::cout<<"static_cast<const void *>(&ptr[1]): "<<static_cast<const void *>(&pptr[1])<<std::endl;
//
//    free(ptr);
//    free(pptr);
    const int MEMERY_500M = 1024 * 1024 * 1000;

    for (int i = 0; i < 100; ++i)
    {
        std::cout<<"start"<<std::endl;

        float *ptr = (float *) calloc(MEMERY_500M,  sizeof(char));// 故意写为char结果正常，内存地址和float运算也正常
        std::cout<<"end"<<std::endl;
        free(ptr);

    }

    return 0;
}
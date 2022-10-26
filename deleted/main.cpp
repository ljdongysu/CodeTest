#include <iostream>
#include <glog/logging.h>
#include <thread>
#include <mutex>
#include<sys/time.h>
#include <gtest/gtest.h>
#include <queue>
#define SHOW_BUG 0

struct Log
{
    int end; // for function end (debug)
    int debug; // for debug program
    int time; // for timing
    int test; // for test(time, distance, mAP)
    int status; // for release log
};

enum TestType{
    STRING_STREAM = 0,
    TEST_GLOG_SINK,
    TEST_GLOG_STRING,
    TEST_GLOG_TO_STRING
};


TestType testType;
Log g_log;
const std::string MODULE_NAME = "DeepLearning";

std::mutex logMutex;

std::stringstream streamGlobal;

std::queue<std::string> stringQ;
std::vector<std::string> stringV;


class TestLogSinkImpl : public google::LogSink
{
public:
    std::vector<std::string> errors;
    virtual void send(google::LogSeverity severity, const char* /* full_filename */,
                      const char* base_filename, int line,
                      const struct tm* tm_time,
                      const char* message, size_t message_len, int usecs)
    {
        errors.push_back(ToString(severity, base_filename
                , line, tm_time, message
                , message_len));
    }
    virtual void send(google::LogSeverity severity, const char* full_filename,
                      const char* base_filename, int line,
                      const struct tm* tm_time,
                      const char* message, size_t message_len)
    {
        send(severity, full_filename, base_filename, line
                ,tm_time, message, message_len, 0);
    }
};

TestLogSinkImpl sink1;

class StringStream
{
public:
    StringStream()
    {}

    ~StringStream()
    {
        std::unique_lock<std::mutex> lock(logMutex);
        stream<<std::endl;
        stringQ.push(this->GetMessage());
    }


    std::string GetMessage() const
    {
        return stream.str();
    }

    std::stringstream &GetStream()
    {
        return stream;
    }

private:
    std::stringstream stream;
};

#define filename(x) strrchr(x,'/')?strrchr(x,'/')+1:x

#define LOG_CHECK_TEST_STRING_STREAM(severity) if (g_log.test) COMPACT_GOOGLE_LOG_ ## severity.stream() << "[" << MODULE_NAME << "] " \
    << "[" << __FUNCTION__ << "] "; else  StringStream().GetStream() <<"[" << (filename(__FILE__))<< ":" << __LINE__ <<"]" <<"[" << MODULE_NAME << "] " \
    << "[" << __FUNCTION__ << "] "

#define LOG_CHECK_TEST_GLOG_SINK(severity) if (g_log.test) COMPACT_GOOGLE_LOG_ ## severity.stream() << "[" << MODULE_NAME << "] " \
    << "[" << __FUNCTION__ << "] "; else  LOG_TO_SINK_BUT_NOT_TO_LOGFILE(&sink1, severity) <<"[" << MODULE_NAME << "] " \
    << "[" << __FUNCTION__ << "] "

#define LOG_CHECK_TEST_GLOG_STRING(severity) if (g_log.test) COMPACT_GOOGLE_LOG_ ## severity.stream() << "[" << MODULE_NAME << "] " \
    << "[" << __FUNCTION__ << "] "; else  LOG_STRING(severity, &stringV) << "[" << MODULE_NAME << "] " \
    << "[" << __FUNCTION__ << "] "

class TestGlog
{
public:
    void Start();
};

void TestGlog::Start()
{
    std::thread testThread;

    testThread = std::thread(
            [this]()
            {
                for (int i = 0; i < 10000; ++i)
                {
                    if (testType == TestType::STRING_STREAM)
                    {
                        LOG_CHECK_TEST_STRING_STREAM(INFO) << "in thread " << i;
//                        usleep(1);
                    }
                    else if (testType == TestType::TEST_GLOG_SINK)
                    {
                        LOG_CHECK_TEST_GLOG_SINK(INFO) << "in thread " << i;
                        //error function
                        usleep(1);
#if SHOW_BUG
                        sink1.errors.pop_back();
#endif
                    }
                    else if (testType == TestType::TEST_GLOG_STRING)
                    {
                        LOG_CHECK_TEST_GLOG_STRING(INFO) << "in thread " << i;
                        usleep(1);
#if SHOW_BUG
                        stringV.pop_back();
#endif
                    }

                }
            });
    testThread.detach();
}

void TestStringStream()
{
    g_log.time = 0;
    g_log.test = 0;

    TestGlog testGlog;
    testGlog.Start();
    sleep(1);
    while (stringQ.size() > 0)
    {
        std::cout<<stringQ.front();
        stringQ.pop();
    }


    struct  timeval   tv_begin,tv_end;
    gettimeofday(&tv_begin,NULL);
    for (int i = 0; i < 10000; i++)
    {
        if (testType == TestType::STRING_STREAM)
        {
            LOG_CHECK_TEST_STRING_STREAM(INFO) << "in main " << i;
            usleep(1);
        }
        else if (testType == TestType::TEST_GLOG_SINK)
        {
            LOG_CHECK_TEST_GLOG_SINK(INFO) << "in main " << i;
            usleep(1);
#if SHOW_BUG
            sink1.errors.pop_back();
#endif
        }
        else if (testType == TestType::TEST_GLOG_STRING)
        {
            LOG_CHECK_TEST_GLOG_STRING(INFO) << "in main " << i;
            usleep(1);
#if SHOW_BUG
            stringV.pop_back();
#endif
        }

    }

    gettimeofday(&tv_end,NULL);

    if (testType == TestType::TEST_GLOG_SINK)
    {
        for (auto & i : sink1.errors)
        {
            std::cout<<i<<std::endl;
        }
    }
    else if (testType == TestType::STRING_STREAM)
    {
        while(!stringQ.empty())
        {
            std::cout<<stringQ.front();
            stringQ.pop();
        }
        stringV.clear();
    }
    else
    {
        for (auto & i : stringV)
        {
            std::cout<<i<<std::endl;
        }
        stringV.clear();
    }

    printf("cost time :%f\n",(tv_end.tv_sec - tv_begin.tv_sec) + (tv_end.tv_usec - tv_begin.tv_usec)/1000000.0);
    sleep(2);
}

TEST(FunctorTest, TEST_GLOG_STREAM)
{
    testType = TestType::STRING_STREAM;
    TestStringStream();
}
//
//TEST(FunctorTest, TEST_GLOG_SINK)
//{
//    testType = TestType::TEST_GLOG_SINK;
//    TestStringStream();
//}
//
//TEST(FunctorTest, TEST_GLOG_STRING)
//{
//    testType = TestType::TEST_GLOG_STRING;
//    TestStringStream();
//}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
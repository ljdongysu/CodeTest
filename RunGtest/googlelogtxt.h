//
// Created by indemind on 10/26/21.
//

#ifndef SINGLEDEMO_GOOGLELOGTXT_H
#define SINGLEDEMO_GOOGLELOGTXT_H

#include "glog/logging.h"

const std::string MODULE_NAME = "DeepLearning";

struct Log
{
    int debug; // for debug program
    int time; // for timing
    int test; // for test(time, distance, mAP)
    int status; // for release log
};
extern Log g_log;
#define LOG_CHECK_STATUS(severity) if (g_log.status) COMPACT_GOOGLE_LOG_ ## severity.stream()<< "[11" << MODULE_NAME << "] "

void test();
#endif //SINGLEDEMO_GOOGLELOGTXT_H

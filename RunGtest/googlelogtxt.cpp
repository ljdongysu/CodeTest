//
// Created by indemind on 10/26/21.
//

#include <iostream>
#include "googlelogtxt.h"
Log g_log;

void test()
{
    g_log.status = 1;
    LOG_CHECK_STATUS(INFO)<<"receive";
    std::cout<<"nothgin"<<std::endl;
}
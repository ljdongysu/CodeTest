//
// Created by indemind on 10/29/21.
//

#ifndef COMPILE_WRONG_INSTANCE_H
#define COMPILE_WRONG_INSTANCE_H

#include "src/manager/manager.h"
class Instance {
public:
    Instance(){}

    virtual void Init() = 0;


private:
    manager manager;
};


#endif //COMPILE_WRONG_INSTANCE_H

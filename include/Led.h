#ifndef _LED_H_
#define _LED_H_

#include <iostream>
#include "Device.h"

using namespace std;

//抽象类
class Led : public Device{
    public:
        Led(const string &name);

};

#endif /* end of include guard: _LED_H_ */

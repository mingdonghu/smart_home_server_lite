#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <iostream>
using namespace std;

//抽象类
class Device {
    public:
        Device(const string &name);
        virtual bool open() = 0;
        virtual bool close() = 0;
        virtual bool adjust(const string &level) = 0;
        static int current_total();

    protected:
        string name;
        bool isOpen;
        string level;
        static int total;
};

#endif /* end of include guard: _DEVICE_H_ */

#ifndef _AIRCONDITIONER_H_
#define _AIRCONDITIONER_H_

#include "Device.h"

class AirConditioner : public Device{
    public:
        AirConditioner(const string &name);

        bool open();
        bool close();
        bool adjust(const string &level);

        bool tempUp();
        bool tempDown();
        int  getTemp();

    private:
        int temp;
        
};

#endif /* end of include guard: _AIRCONDITIONER_H_ */

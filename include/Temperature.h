#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

#include "Device.h"

class Temperature : public Device{
    public:
        Temperature(const string &name);

        bool open();
        bool close();
        bool adjust(const string &level);

        int getCurrentTemp();

    private:
        int temp;
        
};

#endif /* end of include guard: _TEMPERATURE_H_ */

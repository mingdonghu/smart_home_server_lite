#ifndef _COMMANDHANDLE_H_
#define _COMMANDHANDLE_H_

#include "Led_Room.h"
#include "Led_Corridor.h"
#include "AirConditioner.h"
#include "Communication.h"
#include "Temperature.h"

class CommandHandle {
    public:
        CommandHandle();
        void run();

    private:
        Communication *com;
        Led_Room *led_room;
        AirConditioner *air_conditioner;
        Temperature *temperature;
        
};

#endif /* end of include guard: _COMMANDHANDLE_H_ */

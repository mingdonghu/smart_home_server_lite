#ifndef _LED_ROOM_H_
#define _LED_ROOM_H_

#include "Led.h"

class Led_Room : public Led{
    public:
        Led_Room(const string &name);

        //重写父类的方法
        bool open();
        bool close();
        bool adjust(const string &level);

    private:
        
};

#endif /* end of include guard: _LED_ROOM_H_ */

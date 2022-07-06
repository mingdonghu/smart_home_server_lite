#ifndef _LED_CORRIDOR_H_
#define _LED_CORRIDOR_H_

#include "Led.h"

class Led_Corridor : public Led{
    public:
        Led_Corridor(const string &name);

        //重写父类的方法
        bool open();
        bool close();
        bool adjust(const string &level);
    private:
        
};

#endif /* end of include guard: _LED_CORRIDOR_H_ */

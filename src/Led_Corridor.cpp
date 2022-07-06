#include "Led_Corridor.h"

Led_Corridor::Led_Corridor(const string &name)
    :Led(name)
{

}

//重写父类的方法
bool Led_Corridor::open()
{
    cout << "温馨且浪漫的魔幻灯效" << endl;
    cout << "++++++++" << this->name << " open++++++++" << endl;
}
bool Led_Corridor::close()
{
    cout << "啊， 为匆匆离我而去" << endl; 
    cout << "--------" << this->name << " close-------" << endl;
}

bool Led_Corridor::adjust(const string &level)
{
    cout << "看，我又变亮了" << endl;
    this->level = level;

    cout << this->name << " brightness : " << this->level << endl;

}


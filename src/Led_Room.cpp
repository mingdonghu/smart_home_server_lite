#include "Led_Room.h"

Led_Room::Led_Room(const string &name)
    :Led(name)
{

}

//重写父类的方法
bool Led_Room::open()
{
    cout << "灯光洒在温暖的床上，它不香吗？"  << endl;
    cout << "++++++++" << this->name << " open++++++++" << endl;
}

bool Led_Room::close()
{
    cout << "黑夜现在降临！" << endl;
    cout << "--------" << this->name << " close-------" << endl;
}

bool Led_Room::adjust(const string &level)
{
    cout << "光明，是需要维系的" << endl;
    this->level = level;

    cout << this->name << " brightness : " << this->level << endl;

}


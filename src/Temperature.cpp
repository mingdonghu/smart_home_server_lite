#include "Temperature.h"
#include <stdlib.h>
#include <time.h>

Temperature::Temperature(const string &name)
    :Device(name)
{
    cout << "=========create " << this->name << "==========" << endl;
    this->isOpen = false;

    //产生随机数种子
    srand(time(NULL));
}

bool Temperature::open()
{
    cout << "我见青山多妩媚，青山见我应如是。" << endl;
    cout << "++++++++" << this->name << " open++++++++" << endl;
    
}

bool Temperature::close()
{
    cout << "一个能打的都没有!" << endl;
    cout << "--------" << this->name << " close-------" << endl;

}

bool Temperature::adjust(const string &level)
{
    cout << "冷暖我自量,不信奴唇皮" << endl;
    this->level = level;

    cout << this->name << " brightness : " << this->level << endl;

}

int Temperature::getCurrentTemp()
{
    this->temp = 15 + rand()%10; //15 ～ 24 间
    return this->temp;
}


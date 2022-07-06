#include "Device.h"

//static 成员变量初始化
int Device::total = 0;

Device::Device(const string &name)
{
    this->name = name;
    this->level = "**";
    cout << "=========create " << this->name << "========" << endl;
    cout << ">>> level : " << this->level << endl;

    //新增一个设备
    total++; 
}
#if 0
bool Device::open()
{
    if(this->isOpen){
        cout << "!!!!!!!!! " << this->name << " is open !!!!!!!!!!!" << endl; 
        return false;
    }
    cout << "+++++++++open " << this->name << "++++++++++" << endl;
    this->isOpen = true;

    return true;
}

bool Device::close()
{
    if(!this->isOpen){
        cout << "!!!!!!!!! " << this->name << " is close !!!!!!!!!!!" << endl; 
        return false;
    }
    
    cout << "--------close " << this->name << "----------" << endl;
    this->isOpen = false;

    return true;
}

bool Device::adjust(const string &level)
{
    this->level = level;
    cout << "^^^^^^^ ajust " << this->name << "^^^^^^^" << endl;
    cout << ">>> level : " << this->level << endl;
}
#endif

int Device::current_total()
{
    return total;
}

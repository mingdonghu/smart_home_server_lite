#include "AirConditioner.h"

AirConditioner::AirConditioner(const string &name)
    :Device(name)
{
    cout << "=======air conditioner conming=======" << endl;
    this->isOpen = false;
    this->temp = 20; //空调默认温度
}

bool AirConditioner::open()
{
    if(this->isOpen){
        cout << "您的空调已经开启，别闹！" << endl;
        return false;
    }
    cout << "忽如一夜春风来,千树万树梨花开" << endl;
    cout << "一日三餐没烦恼今天就开老胡密制小空调" << endl;
    cout << this->name << " open" << "temp :" << this->temp << endl;
    this->isOpen = true;

    return true;
}

bool AirConditioner::close()
{
    if(!this->isOpen){
        cout << "您的空调压根就没活过，咋第，炸尸啊" << endl;
        return false;
    }

    cout << "云鬓花颜金步摇，芙蓉帐嗳度春宵" << endl;
    cout << this->name << " close" << endl;
    this->isOpen = false;

    return true;
}

bool AirConditioner::adjust(const string &level)
{
    if(!this->isOpen){
        cout << "您的空调还开都没开呢，闹啥闹！" << endl;
        return false;
    }
    this->level = level;
    cout << "小荷才露尖尖角，早有蜻蜓立上头" << endl;
    cout << "升温 夜热依然午热同，开门小立月明中" << endl;
    cout << this->name << " adjust" << endl;
    cout << "temp : " << this->level << endl;

    return true;

}

bool AirConditioner::tempUp()
{
    if(!this->isOpen){
        cout << "您的空调还开都没开呢，闹啥闹！" << endl;
        return false;
    }
    
    this->temp++;
    return true;
}

bool AirConditioner::tempDown()
{
    if(!this->isOpen){
        cout << "您的空调还开都没开呢，闹啥闹！" << endl;
        return false;
    }
    this->temp--;
    return true;
}

int  AirConditioner::getTemp()
{
    return this->temp;
}



#include "CommandHandle.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

CommandHandle::CommandHandle()
{
    //设备列表
    //在堆区创建对象，只需要知道它的地址就可以操作,整个程序都可以
    this->led_room = new Led_Room("led_room"); 
    this->air_conditioner = new AirConditioner("air_conditioner");
    this->temperature = new Temperature("temperature");
    //通讯模块
    this->com = new Communication;
    //其他
}

void CommandHandle::run()
{
    //等待客户端连接
    com->waitClientConnect();
    
    string recv_buf;
    while(1)
    {
        com->recvFromClient(recv_buf);
        cout << "client : " << recv_buf << endl;

        //消息解释
        //message
        if(recv_buf.compare(0, 7, "message") == 0){
            size_t pos = recv_buf.find(" ");
            string context = recv_buf.substr(pos+1);
            cout << "context : " << context << endl;

            //服务器退出
            if(context.compare(0, 4, "quit") == 0){
                cout << "````````服务器退出```````" << endl;
                break;
            }
        }

        //led_room
        if(recv_buf.compare(0, 8, "led_room") == 0){
            if(recv_buf.compare(9, 4, "open") == 0){
                this->led_room->open();
                com->sendMessageToClient("led_room is open!");
            }else if(recv_buf.compare(9, 5, "close") == 0){
                this->led_room->close();
                com->sendMessageToClient("led_room is close!");
            }else{
                size_t pos = recv_buf.find("*");
                string level = recv_buf.substr(pos);
                this->led_room->adjust(level);
                com->sendMessageToClient("led_room brightness: "+level);
            }
        }

        //led_corridor


        //空调
        int len = strlen("air_conditioner");
        if(recv_buf.compare(0, len, "air_conditioner") == 0){
            if(recv_buf.compare(len+1, 4, "open") == 0){
                this->air_conditioner->open();
                com->sendMessageToClient("air_conditioner is open!");
            }else if(recv_buf.compare(len+1, 5, "close") == 0){
                this->air_conditioner->close();
                com->sendMessageToClient("air_conditioner is close!");
            }else if(recv_buf.compare(len+1, 2, "up") == 0){
                this->air_conditioner->tempUp();
                char temp[10];
                sprintf(temp, "%d", air_conditioner->getTemp());
                string tempStr = temp;
                com->sendMessageToClient("temp up ---> air_conditioner temp: "+tempStr);
            }else if(recv_buf.compare(len+1, 4, "down") == 0){
                this->air_conditioner->tempDown();
                char temp[10];
                sprintf(temp, "%d", air_conditioner->getTemp());
                string tempStr = temp;
                com->sendMessageToClient("temp down ---> air_conditioner temp: "+tempStr);
            }
        }

        //温控设备
        len = strlen("temperature");
        if(recv_buf.compare(0, len, "temperature") == 0){
            if(recv_buf.compare(len+1, 4, "open") == 0){
                this->temperature->open();
                com->sendMessageToClient("temperature is open!");
            }else if(recv_buf.compare(len+1, 5, "close") == 0){
                this->temperature->close();
                com->sendMessageToClient("temperature is close!");
            }else if(recv_buf.compare(len+1, 4, "temp") == 0){
                com->sendTempToClient(this->temperature->getCurrentTemp());
            }
        }

    }
    
}

void device_control(Device &dev)
{
    dev.open();
    dev.close();
    dev.adjust("*********");
}


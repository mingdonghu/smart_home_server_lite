#include "Communication.h"
#include <iostream>
#include <sys/types.h>	       /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>   //用于进行本地数据和网络数据的转化
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define PORT 7777

using namespace std;


Communication::Communication()
{
    //step 1 : 创建 服务器端的套接字对象 socket() 
    this->sockfd_server = socket(AF_INET, SOCK_STREAM, 0); 
    if(this->sockfd_server == -1)
    {
        cerr << "fail server socket : ";
        return;
    }

    //step 2 : 绑定 ip地址与端口号 bind() 
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY; //设置服务器ip地址  INADDR_ANY : 允许任意本地连接 
    socklen_t addrlen = sizeof(sockaddr_in);

    int res_bind = bind(this->sockfd_server, (struct sockaddr *)&server_addr, addrlen);
    if(res_bind == -1)
    {
        cerr << "bind address fail : ";
        return;
    }
    
    //step 3 : 监听客户端连接请求 listen() 
    int res_listen = listen(this->sockfd_server, 5);
    if(res_listen == -1)
    {
        cerr << "listen fail : ";
        return;
    }

}

bool Communication::waitClientConnect()
{
    cout << "===================server info======================" << endl;
    system("ifconfig");
    cout << "==================wait for connect==================" << endl;
    cout << "服务器端口号 : 7777" << endl;
    cout << ">>>>>>>>等待客户端连接<<<<<<<" << endl;
    
    //step 4 : 接受客户端连接请求 accept()
    struct sockaddr_in client_addr; //用于接受客户端的ip和port（端口号）
    socklen_t addrlen_client = sizeof(struct sockaddr_in);
    this->sockfd_client = accept(this->sockfd_server, (struct sockaddr *)&client_addr, &addrlen_client);
    if(this->sockfd_client == -1)
    {
        cerr << "client accept fail : ";
        return false;
    }

    cout << "客户端连接成功！" << endl;
    //打印客户端的ip
    cout << "client ip : " << inet_ntoa(client_addr.sin_addr) << endl;

    //连接成功向 客户端 反馈信息
    string send_buf = "connect server success!";
    if(!sendMessageToClient(send_buf))
    {
        cout << "反馈连接服务器状态失败！" << endl;
    }
    
    return true;
}


bool Communication::sendBuf(const string &buf)
{
    int buf_size = buf.size();

    //向客户端发送信息
    int send_size = send(this->sockfd_client, buf.c_str(), buf_size, 0);
    if(send_size == -1)
    {
        cerr << "send fail : ";
        return false;
    }

    return true;

}

bool Communication::sendMessageToClient(const string &buf)
{
    //包装信息
    string send_buf = "message "+buf;

    if(sendBuf(send_buf)){
        return true;
    }else{
        return false;
    }

}

bool Communication::sendTempToClient(const int temp)
{
    char temp_num[10];
    sprintf(temp_num, "%d", temp);
    string tempStr = temp_num;

    //包装信息
    string send_buf = "temp "+tempStr;

    if(sendBuf(send_buf)){
        return true;
    }else{
        return false;
    }

}

bool Communication::sendHumToClient(const int hum)
{
    char hum_num[10];
    sprintf(hum_num, "%d", hum);
    string humStr = hum_num;

    //包装信息
    string send_buf = "hum "+humStr;

    if(sendBuf(send_buf)){
        return true;
    }else{
        return false;
    }

}

bool Communication::recvFromClient(string &buf)
{
    
    //接受来自客户端的信息
    char recv_buf[1024];
    int recv_size = recv(this->sockfd_client, recv_buf, 1024, 0);
    if(recv_size == -1)
    {
        cerr << "recv fail : ";
        exit(0);
        return false;
    }
    //cout << recv_size << endl;
    recv_buf[recv_size] = '\0'; //字符串结尾标识符

    buf = recv_buf;

    //cout << "recv : " << recv_buf << endl;
    return true;

}

Communication::~Communication()
{
    //step 6 : 关闭 socket 接口 close()
    close(this->sockfd_server);
    close(this->sockfd_client);
}

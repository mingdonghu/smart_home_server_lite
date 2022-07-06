#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

#include <iostream>
using namespace std;

class Communication {
    public:
        Communication();
        bool waitClientConnect();
        bool sendBuf(const string &buf);
        bool sendMessageToClient(const string &buf);
        bool sendTempToClient(const int temp);
        bool sendHumToClient(const int hum);
        bool recvFromClient(string &buf);
        ~Communication();

    private:
        int sockfd_server;
        int sockfd_client;

        
};

#endif /* end of include guard: _COMMUNICATION_H_ */

//  客户端通信

#ifndef client_hpp
#define client_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include<arpa/inet.h>
#include <unistd.h>

using namespace std;



class client{
private:
    string IPServer;
    unsigned int port;
    int socketID;
    struct sockaddr_in serverAddr;
    
public:
    client() = delete;
    client(string ip, unsigned int port1);
    client(client& temp) = delete;
    client& operator=(client& temp) = delete;
    bool createSocket();
    bool myConnect();
    bool mySend(void* buffer, size_t size);
    bool myRec(void* buffer);
    string getIPServer() const;
    unsigned int getPort() const;
    int getSocketID() const;
    void myclose();
};
#endif /* client_hpp */

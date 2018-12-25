//
// Created by vered on 19/12/18.
//

#ifndef AP3_OPENDATASERVERTHREAD_H
#define AP3_OPENDATASERVERTHREAD_H

#include <pthread.h>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "DataBase.h"


using namespace std;


struct ConnectParams
{
    DataBase *data;
    int port;
    string IP;
};

struct openDataServerParams
{
    DataBase *data;
    int port;
    int NumToSec;
};

void* thread_OpenDataserver(void* arg);
void* thread_Connect(void* arg);

#endif //AP3_OPENDATASERVERTHREAD_H

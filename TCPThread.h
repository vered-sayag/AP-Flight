

#ifndef AP3_OPENDATASERVERTHREAD_H
#define AP3_OPENDATASERVERTHREAD_H

#include <pthread.h>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include "DataBase.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <regex>
#include <chrono>
#include <bits/stdc++.h>

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
vector <string> splitByComma(string str);
void setInputSymbols(const string &line, DataBase *data);


#endif //AP4_OPENDATASERVERTHREAD_H

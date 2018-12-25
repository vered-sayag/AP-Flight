//
// Created by vered on 20/12/18.
//

#include <pthread.h>
#include <regex>
#include <string>
#include "connectCommand.h"
#include "Shunting_Yard.h"


using namespace std;

void ConnectCommand::doCommand(int index, vector<string> lex) {
    if (!regex_match(lex[index + 1],
                     regex("^\\d{1,3}(\\.\\d{1,3}){3}$"))) {
        throw std::invalid_argument("Invalid IP");
    }



    vector<double> port = shuntingYard(data, lex, index + 2);

    struct ConnectParams *params;
    params = new ConnectParams();
    params->port = (int) port[0];
    params->IP = lex[index + 1];
    params->data=data;
    pthread_t trid;
    pthread_create(&trid, nullptr, thread_Connect, params);
}

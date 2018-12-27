
#include "connectCommand.h"

void ConnectCommand::doCommand(int index, vector<string> lex) {
    if (index > lex.size() - 3) {
    throw invalid_argument("Invalid argument to Connect");
    }
    if (!regex_match(lex[index + 1],
                     regex("^\\d{1,3}(\\.\\d{1,3}){3}$"))) {
        throw std::invalid_argument("Invalid IP");
    }

    vector<double> port = shuntingYard(data, lex, index + 2);

    struct ConnectParams *params;
    params = new ConnectParams();
    params->port = (int) port[0];
    params->IP = lex[index + 1];
    params->data = data;
    pthread_t trid;
    pthread_create(&trid, nullptr, thread_Connect, params);
}

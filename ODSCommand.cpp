
#include "ODSCommand.h"

void ODSCommand::doCommand(int index, vector <string> lex) {
    if (index > lex.size() - 3) {
        throw invalid_argument("Invalid argument to open data server");
    }

    vector <double> syPort = shuntingYard(data, lex, index + 1);

    if(!lex[syPort[1] + 1].compare(",")){
        syPort[1]++;
    }

    if (syPort[1] > lex.size() - 2) {
        throw invalid_argument("Invalid argument to open data server");
    }

    vector <double> sySec = shuntingYard(data, lex, syPort[1] + 1);

    struct openDataServerParams *params;
    params = new openDataServerParams();
    params->port = (int)syPort[0];
    params->NumToSec = (int)sySec[0];
    params->data = data;
    pthread_t trid2;
    pthread_create(&trid2, nullptr, thread_OpenDataserver, params);
    while (!params->data->isConect()){}
}



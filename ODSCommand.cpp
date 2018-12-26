
#include "ODSCommand.h"

void ODSCommand::doCommand(int index, vector <string> lex) {

    vector <double> syPort = shuntingYard(data, lex, index + 1);
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



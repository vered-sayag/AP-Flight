//
// Created by vered on 20/12/18.
//

#ifndef AP3_CONNECTCOMMAND_H
#define AP3_CONNECTCOMMAND_H

#include "TCPThread.h"
#include "Command.h"
#include "DataBase.h"

class ConnectCommand : public Command {
    DataBase *data;
public:
    ConnectCommand(DataBase *d) {
        data = d;
    }

    virtual void doCommand(int index, vector <string> lex);
};


#endif //AP3_CONNECTCOMMAND_H

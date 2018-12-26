

#ifndef AP3_CONNECTCOMMAND_H
#define AP3_CONNECTCOMMAND_H

#include "TCPThread.h"
#include "Command.h"
#include "DataBase.h"
#include <pthread.h>
#include <regex>
#include <string>
#include "Shunting_Yard.h"
using namespace std;

class ConnectCommand : public Command {
    DataBase *data;
public:
    ConnectCommand(DataBase *d) {
        data = d;
    }

    virtual void doCommand(int index, vector <string> lex);
};


#endif //AP3_CONNECTCOMMAND_H

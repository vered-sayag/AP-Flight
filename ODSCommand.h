
#ifndef AP3_ODS_H
#define AP3_ODS_H


#include "TCPThread.h"
#include <pthread.h>
#include "Command.h"
#include "DataBase.h"
#include "Shunting_Yard.h"


class ODSCommand : public Command {
    DataBase *data;

public:
    ODSCommand(DataBase *d) {
        data = d;
    }

    virtual void doCommand(int index, vector <string> lex);
};


#endif

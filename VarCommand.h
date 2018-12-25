//
// Created by vered on 21/12/18.
//

#ifndef AP4_VARCOMMAND_H
#define AP4_VARCOMMAND_H


#include <iostream>
#include "Command.h"
#include "DataBase.h"



class VarCommand : public Command {
    DataBase *data;

public:
    VarCommand(DataBase *d) {
        data = d;
    }

    virtual void doCommand(int index, vector <string> lex);
};


#endif //AP4_VARCOMMAND_H

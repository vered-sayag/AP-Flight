//
// Created by vered on 20/12/18.
//

#ifndef AP3_EQUALBINDCOMMAND_H
#define AP3_EQUALBINDCOMMAND_H

#include "DataBase.h"
#include "Command.h"


class equalBindCommand : public Command {
    DataBase *data;
public:
    equalBindCommand(DataBase *d) {
        data = d;
    }

    void doCommand(int index, vector <string> lex);
};

#endif //AP3_EQUALBINDCOMMAND_H

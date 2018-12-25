//
// Created by vered on 20/12/18.
//

#ifndef AP3_WHILECOMMAND_H
#define AP3_WHILECOMMAND_H


#include "Command.h"
#include "DataBase.h"
#include "BlockCommand.h"
class WhileCommand : public BlockCommand{
    DataBase *data;

public:
    WhileCommand(DataBase *d) {
        data = d;
    }

    void doCommand(int index, vector<string> lex);
};



#endif //AP3_WHILECOMMAND_H

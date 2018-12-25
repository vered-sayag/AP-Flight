//
// Created by vered on 20/12/18.
//

#ifndef AP3_EQUALCOMMAND_H
#define AP3_EQUALCOMMAND_H

#include "Command.h"
#include "DataBase.h"
#include "Shunting_Yard.h"


class equalCommand : public Command {
    DataBase* data;

public:
    equalCommand(DataBase* d) {
        data = d;
    }

    void doCommand(int index, vector <string> lex);

};


#endif //AP3_EQUALCOMMAND_H

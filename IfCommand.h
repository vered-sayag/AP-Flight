

#ifndef AP3_IFCOMMAND_H
#define AP3_IFCOMMAND_H


#include "Command.h"
#include "DataBase.h"
#include "BlockCommand.h"
#include "conditionParser.h"
#include "parser.h"
#include "Condition.h"

class IfCommand : public BlockCommand {
    DataBase *data;

public:
    IfCommand(DataBase *d) {
        data = d;
    }

    void doCommand(int index, vector <string> lex);
};


#endif //AP3_IFCOMMAND_H

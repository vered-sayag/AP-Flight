
#ifndef AP4_PRINTCOMMAND_H
#define AP4_PRINTCOMMAND_H

#include <iostream>
#include <regex>
#include "DataBase.h"

class printCommand : public Command {
    DataBase *data;
public:
    printCommand(DataBase *d) {
        data = d;
    }

    void doCommand(int index, vector <string> lex);
};


#endif //AP4_PRINTCOMMAND_H

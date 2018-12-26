

#ifndef AP4_SLEEPCOMMAND_H
#define AP4_SLEEPCOMMAND_H

#include <chrono>
#include "DataBase.h"
#include "Shunting_Yard.h"
class sleepCommand : public Command {
    DataBase *data;

public:
    sleepCommand(DataBase *d) {
        data = d;
    }

    virtual void doCommand(int index, vector <string> lex);
};


#endif //AP4_SLEEPCOMMAND_H

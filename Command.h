

#ifndef AP3_COMMAND_H
#define AP3_COMMAND_H

#include <vector>
#include <string>

using namespace std;

class Command {
public:
    virtual void doCommand(int i, vector <string> lex) = 0;

    virtual ~Command() {}
};

#endif //AP3_COMMAND_H

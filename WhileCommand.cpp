

#include "WhileCommand.h"


void WhileCommand::doCommand(int index, vector <string> lex) {;
    Condition *condition = conditionParser(data, lex, index + 1);
    vector<string> Whilelex=splitBlock(index,lex);

    while (condition->calculate()) {
        parser(data, Whilelex);
    }

    delete (condition);
}

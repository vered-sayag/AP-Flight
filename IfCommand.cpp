

#include "IfCommand.h"


void IfCommand::doCommand(int index, vector<string> lex) {
    Condition *condition = conditionParser(data, lex, index + 1);
    vector<string> IFlex = splitBlock(index, lex);
    if (condition->calculate()) {
        parser(data, IFlex);
    }
    delete (condition);
}

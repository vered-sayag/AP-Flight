//
// Created by vered on 20/12/18.
//

#include "IfCommand.h"
#include "conditionParser.h"
#include "parser.h"
#include "Condition.h"


void IfCommand::doCommand(int index, vector<string> lex) {
    Condition *condition = conditionParser(data, lex, index + 1);
    vector<string> IFlex = splitBlock(index, lex);
    if (condition->calculate()) {
        parser(data, IFlex);
    }
    delete (condition);
}

//
// Created by vered on 20/12/18.
//

#include "WhileCommand.h"

#include "conditionParser.h"
#include "parser.h"

void WhileCommand::doCommand(int index, vector <string> lex) {;
    Condition *condition = conditionParser(data, lex, index + 1);
    vector<string> Whilelex=splitBlock(index,lex);

    while (condition->calculate()) {
        parser(data, Whilelex);
    }
}

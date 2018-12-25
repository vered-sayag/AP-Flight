//
// Created by vered on 23/12/18.
//

#ifndef AP4_CONDITIONPARSER_H
#define AP4_CONDITIONPARSER_H

#include "DataBase.h"
#include <vector>
#include "Condition.h"

Condition* conditionParser(DataBase* d, vector <string> lex, int index);


#endif //AP4_CONDITIONPARSER_H

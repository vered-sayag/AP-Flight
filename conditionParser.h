

#ifndef AP4_CONDITIONPARSER_H
#define AP4_CONDITIONPARSER_H

#include "DataBase.h"
#include <vector>
#include "Condition.h"
#include "Shunting_Yard.h"

Condition* conditionParser(DataBase* d, vector <string> lex, int index);


#endif //AP4_CONDITIONPARSER_H

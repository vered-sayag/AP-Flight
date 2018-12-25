#include "DataBase.h"
#include <iostream>
#include "Expression.h"
#include <string>
#include <regex>
#include <list>
#include "lexer.h"
#include "Shunting_Yard.h"
#include "parser.h"
#include "conditionParser.h"
#include "TCPThread.h"

int main(int numArg, char* argFiles[]) {
    if (numArg == 2) {
        vector<string> a;
        a = lexer(argFiles[1]);
        DataBase *d = new DataBase();
        parser(d, a);
        delete (d);
    } else{
        throw invalid_argument("Invalid main arguments");
    }
}



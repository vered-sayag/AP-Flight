#include "DataBase.h"
#include <string>
#include <regex>
#include "lexer.h"
#include "parser.h"

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



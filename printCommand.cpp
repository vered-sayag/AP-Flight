

#include "printCommand.h"

void printCommand::doCommand(int index, vector<string> lex) {
    if (index >= lex.size() - 1) {
        throw invalid_argument("invalid argument to print");
    }
    index++;
    do {
        if (regex_match(lex[index ], regex("^\"[^\"]*\"$"))) {
            string s = (lex[index ]).substr(1, lex[index ].size() - 2);
            cout << s ;
        } else if (data->isSymbol(lex[index])) {
            cout << data->getSymbolValue(lex[index]) ;
        } else {
            throw invalid_argument("invalid argument to print");
        }
        index++;
    }while (index+1<lex.size() && (lex[index++]).compare("+")==0);
    cout << "" << endl;

}



#include "printCommand.h"

void printCommand::doCommand(int index, vector<string> lex) {
    if (index >= lex.size() - 1) {
        throw invalid_argument("invalid argument to print");
    }
    if (regex_match(lex[index + 1], regex("^\"[^\"]*\"$"))) {
        string s = (lex[index + 1]).substr(1, lex[index + 1].size() - 2);
        cout << s << endl;
    } else if (data->isSymbol(lex[index + 1])) {
        cout << data->getSymbolValue(lex[index + 1]) << endl;
    }else if(regex_match(lex[index + 1], regex("^\"[^\"]*$"))){
        string s = (lex[index + 1]).substr(1, lex[index + 1].size() - 1);
        cout << s + " ";
        index++;
        while (!regex_match(lex[index + 1], regex("^[^\"]*\"$"))){
            if (index+1>= lex.size()){
                throw invalid_argument("invalid argument to print");
            }
            cout << lex[index + 1] + " ";
            index++;
        }
        s = (lex[index + 1]).substr(0, lex[index + 1].size() - 1);
        cout << s << endl;
    }
    else {
        throw invalid_argument("invalid argument to print");
    }

}

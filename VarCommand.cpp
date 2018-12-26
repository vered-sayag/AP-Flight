

#include "VarCommand.h"

void VarCommand:: doCommand(int index, vector <string> lex) {
    if (index >= lex.size()-1){
        throw invalid_argument("invalid var");
    }
    if (!regex_match(lex[index + 1],regex("^[a-zA-Z]+[a-zA-Z_0-9]*$"))) {
        throw invalid_argument("invalid var");
    }
    data->addSymbol(lex[index+1],0);
}


#include "BlockCommand.h"

vector<string> BlockCommand :: splitBlock(int index, vector <string> lex){

    int startBlock = -1;
    int endBlock = -1;
    int block = 0;
    for (int i = index; i < lex.size(); i++) {
        if (block < 0) {
            throw invalid_argument("ERROR: parenthesis are invalid");
        }
        if (!lex[i].compare("{") && block == 0) {
            startBlock = i;
        }
        if (!lex[i].compare("{")) {
            block++;
        }
        if (!lex[i].compare("}")) {
            block--;
        }
        if (!lex[i].compare("}") && block == 0) {
            endBlock = i;
            break;
        }
    }

    if (block != 0 || startBlock == -1 || endBlock == -1) {
        throw invalid_argument("ERROR: parenthesis are invalid");
    }

    vector<string> Blocklex;
    for (int i = startBlock + 1; i < endBlock; i++) {
        Blocklex.push_back(lex[i]);
    }
    return Blocklex;
}

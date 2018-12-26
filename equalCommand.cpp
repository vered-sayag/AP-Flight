

#include "equalCommand.h"

void equalCommand:: doCommand(int index, vector <string> lex){
    if (index<=0 || index>= lex.size()-1){
        throw invalid_argument("invalid =");
    }

    string var = lex[index - 1];

    if (lex[index+1].compare("bind")) {
        double  ans =shuntingYard(data, lex, index + 1)[0];
        data->setSymbol(var,ans);
        if (data->isBind(var)){
            data->pushSend(var,ans);
        } else {
            // the binded variables to check for sending to the simulator
            vector<string> bindsVar = data->getBindVars(var);
            for (int i = 0; i < bindsVar.size(); ++i) {
                if (data->isBind(bindsVar[i])){
                    data->pushSend(bindsVar[i],ans);
                    break;
                }
            }
        }
    }
}


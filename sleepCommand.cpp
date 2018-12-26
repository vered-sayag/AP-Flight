

#include "sleepCommand.h"

void sleepCommand:: doCommand (int index, vector <string> lex) {
    int time = (int)(shuntingYard(data, lex,index+1))[0];
    this_thread::sleep_for(chrono::milliseconds(time));
}

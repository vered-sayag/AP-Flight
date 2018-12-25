//
// Created by vered on 24/12/18.
//

#ifndef AP4_BLOCKCOMMAND_H
#define AP4_BLOCKCOMMAND_H

#include <string>
#include <vector>
#include "Command.h"
using namespace std;

class BlockCommand : public Command{
public:
    vector<string> splitBlock(int index, vector<string> lex);
};


#endif //AP4_BLOCKCOMMAND_H

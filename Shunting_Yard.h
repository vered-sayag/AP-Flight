//
// Created by vered on 20/12/18.
//

#ifndef AP3_SHUNTING_YARD_H
#define AP3_SHUNTING_YARD_H

#include <string>
#include <vector>
#include "DataBase.h"
#include "Expression.h"
#include <bits/stdc++.h>

using namespace std;

vector<double> shuntingYard(DataBase* d, vector <string> lex, int i);

double applyOp(double a, double b, char op);

double precedence(char op);

double evaluate(const string &tokens);


#endif //AP3_SHUNTING_YARD_H

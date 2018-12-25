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

int main() {
    vector<string> a;

    a = lexer("a.txt");
    DataBase *d = new DataBase();
   // d->addSymbol("x",7);
   // cout << shuntingYard(d,9)[0] << endl;
   // cout << shuntingYard(d, 9)[1] << endl;
   // for (int i = 0; i < a.size(); i++) {

   //     cout << a[i] << endl;
   // }
   // delete (d);
   // int x =5;
//    cout << conditionParser(d,0)<< endl;
   parser(d, a);
    int x =5;
}



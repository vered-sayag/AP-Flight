

#ifndef AP4_CONDITION_H
#define AP4_CONDITION_H

#include <vector>
#include <string>
#include "DataBase.h"
#include "Shunting_Yard.h"

using namespace std;

class Condition {
protected:
    DataBase *dataBase;
    vector<string> lexCondition;
    int start_right;
    int start_left;
    double op1;
    double op2;

    bool calculateExpression(){
        op1 = shuntingYard(dataBase, lexCondition, start_left)[0];
        op2 = shuntingYard(dataBase, lexCondition, start_right)[0];
    }

public:
    Condition(DataBase *data, vector<string> lexC, int start_L, int start_R) {
        dataBase = data;
        lexCondition = lexC;
        start_right = start_R;
        start_left = start_L;
    }


    virtual bool calculate() = 0;
};

class BigCondition : public Condition {
public:
    BigCondition(DataBase *data, vector<string> lexC,  int start_L, int start_R) : Condition(data, lexC, start_L,
                                                                                            start_R) {};
    bool calculate() {
        calculateExpression();
        return op1 > op2;

    }
};
class BigEqualCondition : public Condition {
public:
    BigEqualCondition(DataBase *data, vector<string> lexC,  int start_L, int start_R) : Condition(data, lexC, start_L,
                                                                                            start_R) {};

    bool calculate() {
        calculateExpression();
        return op1 >= op2;

    }
};
class SmallCondition : public Condition {
public:
    SmallCondition(DataBase *data, vector<string> lexC, int start_L, int start_R) : Condition(data, lexC, start_L,
                                                                                            start_R) {};

    bool calculate() {
        calculateExpression();
        return op1 < op2;

    }
};
class SmallEqualCondition : public Condition {
public:
    SmallEqualCondition(DataBase *data, vector<string> lexC,  int start_L, int start_R) : Condition(data, lexC, start_L,
                                                                                                 start_R) {};

    bool calculate() {
        calculateExpression();
        return op1 <= op2;

    }
};

class NotEqualCondition : public Condition {
public:
    NotEqualCondition(DataBase *data, vector<string> lexC,  int start_L, int start_R) : Condition(data, lexC, start_L,
                                                                                              start_R) {};

    bool calculate() {
        calculateExpression();
        return op1 != op2;

    }
};
class EqualEqualCondition : public Condition {
public:
    EqualEqualCondition(DataBase *data, vector<string> lexC, int start_L, int start_R) : Condition(data, lexC, start_L,
                                                                                                   start_R) {};

    bool calculate() {
        calculateExpression();
        return op1 == op2;
    }
};


#endif //AP4_CONDITION_H

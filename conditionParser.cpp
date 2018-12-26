

#include "conditionParser.h"



typedef enum {
    NOTHING, BIG, BIG_EQUAL, SMALL, SMALL_EQUAL, EQUAL, EQUAL_EQUAL, NOT, NOT_EQUAL
} oper;

Condition* conditionParser(DataBase *d, vector <string> lex, int index) {
    vector<string> v;
    int paren = 0;
    int op_position = -1;
    oper op = NOTHING;

    // copy the condition to temporary vector
    for (int k = index; k < lex.size(); ++k) {
        if (!lex[k].compare("{")) {
            break;
        }
        v.push_back(lex[k]);
    }

    for (int i = 0; i < v.size(); ++i) {

        if (!v[i].compare("=") && op == NOTHING) {
            op = EQUAL;
            op_position = i;
        } else if (!v[i].compare("=") && op == EQUAL) {
            op = EQUAL_EQUAL;
            op_position = i;
        }

        if (!v[i].compare("<") && op == NOTHING) {
            op = SMALL;
            op_position = i;
        } else if (!v[i].compare("=") && op == SMALL) {
            op = SMALL_EQUAL;
            op_position = i;
        }

        if (!v[i].compare(">") && op == NOTHING) {
            op = BIG;
            op_position = i;
        } else if (!v[i].compare("=") && op == BIG) {
            op = BIG_EQUAL;
            op_position = i;
        }

        if (!v[i].compare("!") && op == NOTHING) {
            op = NOT;
            op_position = i;
        } else if (!v[i].compare("=") && op == NOT) {
            op = NOT_EQUAL;
            op_position = i;
        }
    }

    if (!(op_position > 0 && op_position < v.size()) || op == NOTHING || op == NOT || op == EQUAL) {
        throw invalid_argument("ERROR: Invalid a condition");
    }

    // check validation of parenthesis of first operand
    for (int j = 0; j < op_position; ++j) {
        if (!v[j].compare("(")) {
            paren++;
        }

        if (!v[j].compare(")")) {
            paren--;
        }

        if (paren < 0) {
            throw invalid_argument("ERROR: Invalid a condition");
        }
    }

    for (int j = 0; j < v.size()-1; ++j) {
        if (!v[j].compare("(") && !v[j+1].compare(")")) {
            throw invalid_argument("ERROR: empty parenthesis");
        }
    }

    // erase ')' from the other side of the operand
    for (int l = 0; l < paren; ++l) {
        v.erase(v.end() - l);
    }


    switch (op) {
        case BIG:
            return new BigCondition(d,v,paren,op_position + 1);
        case BIG_EQUAL:
            return new BigEqualCondition(d,v,paren,op_position + 1);
        case SMALL:
            return new SmallCondition(d,v,paren,op_position + 1);
        case SMALL_EQUAL:
            return new SmallEqualCondition(d,v,paren,op_position + 1);
        case EQUAL_EQUAL:
            return new EqualEqualCondition(d,v,paren,op_position + 1);
        case NOT_EQUAL:
            return new NotEqualCondition(d,v,paren,op_position + 1);
    }

}

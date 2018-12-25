//
// Created by vered on 17/12/18.
//

#ifndef AP3_EXPRESSION_H
#define AP3_EXPRESSION_H

class Expression {
public:
    virtual double calculate() = 0;

    virtual ~Expression() {}
};

class Number : public Expression {
    double val;
public:
    Number(double x) {
        val = x;
    }

    double calculate() {
        return val;
    }
};

class Plus : public Expression {
    Expression *right;
    Expression *left;

public:
    Plus(Expression *left2, Expression *right2) {
        right = right2;
        left = left2;
    }

    double calculate() {
        return left->calculate() + right->calculate();
    }

};

class Mul : public Expression {
    Expression *right;
    Expression *left;

public:
    Mul(Expression *left2, Expression *right2) {
        right = right2;
        left = left2;
    }

    double calculate() {
        return left->calculate() * right->calculate();
    }

};

class Div : public Expression {
    Expression *right;
    Expression *left;

public:
    Div(Expression *left2, Expression *right2) {
        right = right2;
        left = left2;
    }

    double calculate() {
        return left->calculate() / right->calculate();
    }

};


class Minus : public Expression {
    Expression *right;
    Expression *left;

public:
    Minus(Expression *left2, Expression *right2) {
        right = right2;
        left = left2;
    }

    double calculate() {
        return left->calculate() - right->calculate();
    }

};

class Neg: public Expression {
    Expression *right;

public:
    Neg(Expression * right2) {
        right = right2;
    }
    double calculate() {
        return  - right->calculate();
    }

};



#endif //AP3_EXPRESSION_H

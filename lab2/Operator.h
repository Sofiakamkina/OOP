#pragma once

#include <stack>
#include <math.h>
#include <iostream>
#include <string>
#include "consts.h"
#include "Operand.h"
#include "Exceptions.h"
using std::stack;
using std::string;
class Operator
{
private:
    Operand _first;
    Operand _second;
public:
    virtual void correctOperands(Context *context);
    void setOperands(Operand first, Operand second);
    Operand getFirstOperand();
    Operand getSecondOperand();
    virtual void calculate(Context *context);
    virtual ~Operator(){};
};

class Pop: public Operator
{
private:
public:
    void calculate(Context *context) override;

};

class Push: public Operator
{
private:
    Operand _first;
    Operand _second;
public:
    void correctOperands(Context *context) override;
    void calculate(Context *context) override;
    ~Push(){}
};
class Minus:public Operator
{
public:
    void calculate(Context *context) override;
};

class Plus:public Operator
{
public:
    void calculate(Context *context) override;
};

class Sqrt:public Operator
{
public:
    void calculate(Context *context) override;
};

class Multiplication:public Operator
{
public:
    void calculate(Context *context) override;
};

class Division:public Operator
{
public:
    void calculate(Context *context) override;
};

class Definition:public Operator
{
private:
    Operand _first, _second;
public:
    void correctOperands(Context *context) override;
    void calculate(Context *context) override;
};

class Print:public Operator
{
public:
    //Print():Operator(){};
    void calculate(Context *context)override;
};

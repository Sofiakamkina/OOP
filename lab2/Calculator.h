#pragma once

#include <string>
#include <stack>
#include "Input.h"
#include "Operand.h"
#include "consts.h"
#include "Iprocessor.h"
using std::stack;
class Calculator
{
private:
    bool programOn = false;
    Input* input;
    Iprocessor iprocessor;
public:
    Calculator(int argc, char* argv[]);
    void run();
    void closeProgram();
};

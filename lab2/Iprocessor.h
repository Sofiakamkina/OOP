#pragma once
#include <string>
#include <map>
#include "consts.h"
#include "Operand.h"
class Iprocessor
{
private:
public:
    void calculate(std::string &commandline, Context *a);
};

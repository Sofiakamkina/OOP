#pragma once

#include <string>
#include <algorithm>
#include <regex>
#include <map>
#include <string>
#include "consts.h"
class Operand
{
    double _value;
    std::string name;
public:
    Operand(){ _value  = 0;};
    Operand(double value);
    Operand(std::string &value, std::map<std::string, double> definitions);
    bool isValue(std::string str);

    double getValue();
    std::string getName();
    void setValue(std::string value, std::map<std::string, double> definitions);
};

struct Context
{
    std::stack <Operand> numbers;
    std::map <std::string,double> definitions;
};

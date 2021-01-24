#pragma once

#include <memory>
#include"Operator.h"
class OperatorFactory
{
private:
    std::map<std::string,std::shared_ptr<Operator>> listOfOerators;

    std::shared_ptr<Operator> p;
    Operand first;
    Operand second;
public:
    OperatorFactory();
    std::shared_ptr<Operator> getOperationType(std::vector<string> tokens, Context *context);
};

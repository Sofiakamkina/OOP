#pragma once

#include <memory>
#include"Operator.h"
class OperatorFactory
{
private:
    std::map<std::string, Operator*> makers;
public:
    OperatorFactory();

    static OperatorFactory& Instance();

    Operator* getOperationType(std::vector<string> tokens, Context *context);

    void registerOperationTypeMaker(const std::string& operatorName, IOperatorMaker* maker);
};

#pragma once

#include <memory>
#include "Operator.h"

class IOperatorTypeMaker
{
public:
    virtual Operator * Create() const = 0;
    virtual ~IOperatorTypeMaker() {}
};

class OperatorFactory {
private:
    std::map<std::string, IOperatorTypeMaker *> makers;
public:
    OperatorFactory();

    static OperatorFactory &Instance();

    Operator *getOperationType(std::vector<string> tokens, Context *context);

    void registerOperationTypeMaker(const std::string &operatorName, IOperatorTypeMaker *maker);
};

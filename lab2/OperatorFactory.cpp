#include "OperatorFactory.h"

OperatorFactory::OperatorFactory()
{
}

OperatorFactory& OperatorFactory::Instance()
{
    static OperatorFactory factory;
    return factory;
}

Operator* OperatorFactory::getOperationType(std::vector<string> tokens, Context *context)
{
    auto i = _makers.find(tokens[0]);
    if (i == _makers.end())
    {
        throw exceptions::WrongNameOfOperation();
    }
    IShapeMaker* maker = i->second;

    Operator* operator = maker->Create();
    Operand first = Operand(tokens[1],context->definitions);
    Operand second = Operand(tokens[2],context->definitions);

    operator->setOperands(first, second);
    return operator;
}

void registerOperationTypeMaker(const std::string& operatorName, IOperatorMaker* maker)
{
    if (_makers.find(key) != _makers.end())
    {
        throw new std::exception("Multiple makers for given key!");
    }
    _makers[key] = maker;
}

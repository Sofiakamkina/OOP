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
    auto i = makers.find(tokens[0]);
    if (i == makers.end())
    {
        throw exceptions::WrongNameOfOperation();
    }
    IOperatorTypeMaker* maker = i->second;

    Operator* operation = maker->Create();
    Operand first = Operand(tokens[1],context->definitions);
    Operand second = Operand(tokens[2],context->definitions);

    operation->setOperands(first, second);
    return operation;
}

void OperatorFactory::registerOperationTypeMaker(const std::string& operatorName, IOperatorTypeMaker* maker)
{
    if (makers.find(operatorName) != makers.end())
    {
        throw exceptions::TooManyOperatorTypeMakers();
    }
    makers[operatorName] = maker;
}


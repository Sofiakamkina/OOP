#include "OperatorFactory.h"

OperatorFactory::OperatorFactory()
{
    listOfOerators.emplace("pop", std::make_shared<Pop>());
    listOfOerators.emplace("push", std::make_shared<Push>());
    listOfOerators.emplace("+", std::make_shared<Plus>());
    listOfOerators.emplace("-", std::make_shared<Minus>());
    listOfOerators.emplace("/", std::make_shared<Division>());
    listOfOerators.emplace("*", std::make_shared<Multiplication>());
    listOfOerators.emplace("sqrt", std::make_shared<Sqrt>());
    listOfOerators.emplace("print", std::make_shared<Print>());
    listOfOerators.emplace("define", std::make_shared<Definition>());
}
std::shared_ptr<Operator> OperatorFactory::getOperationType(std::vector<string> tokens, Context *context)
{
    if(listOfOerators.find(tokens[0]) == listOfOerators.end())
        throw exceptions::WrongNameOfOperation();

    p = listOfOerators.at(tokens[0]);
    first = Operand(tokens[1],context->definitions);
    second = Operand(tokens[2],context->definitions);

    p->setOperands(first, second);
    return p;
}

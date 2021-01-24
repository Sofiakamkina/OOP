#include "Operator.h"

void Operator::setOperands(Operand first, Operand second)
{
    _first = first;
    _second = second;
}
void Operator::calculate(Context *context)
{
}
Operand Operator::getFirstOperand()
{
    return _first;
}

Operand Operator::getSecondOperand()
{
    return _second;
}

void Operator::correctOperands(Context *context)
{
    _first = getFirstOperand();
    _second = getSecondOperand();
    if(!(_first.getName().empty()) || !(_second.getName().empty()))
        throw exceptions::InvalidOperands();
}
void Push::correctOperands(Context *context)
{
    _first = getFirstOperand();
    _second = getSecondOperand();
    string name1 = _first.getName();
    string name2 = _second.getName();
    if(name1.empty() || (!_first.isValue(name1) && context->definitions.find(name1) == context->definitions.end()) || !name2.empty())
    {
        throw exceptions::InvalidOperands();
    }
}
void Definition::correctOperands(Context *context)
{
    _first = getFirstOperand();
    _second = getSecondOperand();
    string name1 = _first.getName();
    string name2 = _second.getName();
    if(_first.isValue(name1) || !(_second.isValue(name2)))
    {
        throw exceptions::InvalidOperands();
    }
}
void Pop::calculate(Context *context)
{
    correctOperands(context);
    if(context->numbers.empty())
        throw exceptions::StackIsEmpty();
    context->numbers.pop();
}
void Push::calculate(Context *context)
{
    correctOperands(context);
    double value = getFirstOperand().getValue();
    context->numbers.push(value);
}


void Minus::calculate(Context *context)
{
    correctOperands(context);
    if(context->numbers.size()<consts::BinaryOperation)
        throw exceptions::notEnoughParameters();
    double one = context->numbers.top().getValue();
    context->numbers.pop();
    double two =  context->numbers.top().getValue();
    context->numbers.pop();
    double result = one - two;
    context->numbers.push(Operand(result));
}
void Plus::calculate(Context *context)
{
    correctOperands(context);
    if(context->numbers.size()<consts::BinaryOperation)
        throw exceptions::notEnoughParameters();
    double one = context->numbers.top().getValue();
    context->numbers.pop();
    double two =  context->numbers.top().getValue();
    context->numbers.pop();
    double result =  one + two;
    context->numbers.push(Operand(result));
}

void Sqrt::calculate(Context *context)
{
    correctOperands(context);
    double result = sqrt(context->numbers.top().getValue());
    context->numbers.pop();
    context->numbers.push(Operand(result));
}
void Multiplication::calculate(Context *context)
{
    correctOperands(context);
    if(context->numbers.size()<consts::BinaryOperation)
        throw exceptions::notEnoughParameters();
    double one = context->numbers.top().getValue();
    context->numbers.pop();
    double two =  context->numbers.top().getValue();
    context->numbers.pop();
    double result =  one * two;
    context->numbers.push(Operand(result));
}

void Division::calculate(Context *context)
{
    correctOperands(context);
    if(context->numbers.size()<consts::BinaryOperation)
        throw exceptions::notEnoughParameters();
    double one = context->numbers.top().getValue();
    context->numbers.pop();
    double two =  context->numbers.top().getValue();
    context->numbers.pop();

    if(two == 0)
        throw exceptions::DivizionByZero();
    double result = one /  two;
    context->numbers.push(Operand(result));
}

void Print::calculate(Context *context)
{
    correctOperands(context);
    if(context->numbers.empty())
        std::cout<<"Nothing\n";
    else
    {
        double result = context->numbers.top().getValue();
        std::cout<<result<<std::endl;
    }
}
void Definition::calculate(Context *context)
{
    correctOperands(context);
    string name = getFirstOperand().getName();
    double value = getSecondOperand().getValue();
    if(context->definitions.find(name) != context->definitions.end())
    {
        context->definitions[name] = value;
    }
    else
    {
        context->definitions.insert(std::pair<string, double>(name,value));
    }
}

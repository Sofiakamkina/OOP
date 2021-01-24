#include <stack>
#include <vector>
#include <iostream>
#include "OperatorFactory.h"
#include "Iprocessor.h"
#include "Operand.h"
#include "Parser.h"
#include "consts.h"
void Iprocessor::calculate(std::string &commandline, Context *context)
{
    Parser parser;
    std::vector<string> tokens;
    tokens = parser.parser(commandline);
    if(tokens[consts::IndexComment].empty())
        return;
    OperatorFactory operatorFactory;
    std::shared_ptr<Operator> action = operatorFactory.getOperationType(tokens, context);
    action->calculate(context);
}

#include <stack>
#include <vector>
#include <iostream>
#include "OperatorFactory.h"
#include "Iprocessor.h"
#include "Operand.h"
#include "Parser.h"
#include "consts.h"
#include "OperatorTypeMaker.h"

void Iprocessor::calculate(std::string &commandline, Context *context)
{
    Parser parser;
    std::vector<string> tokens;
    tokens = parser.parser(commandline);
    if(tokens[consts::IndexComment].empty())
        return;
    OperatorFactory operatorFactory;

    static OperatorTypeMaker<Pop> popMaker("pop");
    static OperatorTypeMaker<Push> pushMaker("push");
    static OperatorTypeMaker<Plus> plusMaker("+");
    static OperatorTypeMaker<Minus> minusMaker("-");
    static OperatorTypeMaker<Division> divisionMaker("/");
    static OperatorTypeMaker<Multiplication> multiplicationMaker("*");
    static OperatorTypeMaker<Sqrt> sqrtMaker("sqrt");
    static OperatorTypeMaker<Print> printMaker("print");
    static OperatorTypeMaker<Definition> defineMaker("define");

    Operator* action = operatorFactory.getOperationType(tokens, context);
    action->calculate(context);
}

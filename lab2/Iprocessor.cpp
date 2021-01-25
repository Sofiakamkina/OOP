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

    static Common::ShapeMaker<Pop> popMaker("pop");
    static Common::ShapeMaker<Push> pushMaker("push");
    static Common::ShapeMaker<Plus> plusMaker("+");
    static Common::ShapeMaker<Minus> minusMaker("-");
    static Common::ShapeMaker<Division> divisionMaker("/");
    static Common::ShapeMaker<Multiplication> multiplicationMaker("*");
    static Common::ShapeMaker<Sqrt> sqrtMaker("sqrt");
    static Common::ShapeMaker<Print> printMaker("print");
    static Common::ShapeMaker<Definition> defineMaker("define");

    std::shared_ptr<Operator> action = operatorFactory.getOperationType(tokens, context);
    action->calculate(context);
}

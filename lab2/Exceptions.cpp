#include "Exceptions.h"

const char * exceptions::WrongNumberOfParamter::what() const noexcept
{
    return "You must write 3 parameters. You didn't do this.";
}

const char * exceptions::OpenFile::what() const noexcept
{
    return "I can't open input or output file. Please, check names of file.\n";
}

const char* exceptions::WrongNameOfOperation::what() const noexcept
{
    return "I don't understand you\n";
}
const char* exceptions::DivizionByZero::what() const noexcept
{
    return "Dividion by zero\n";
}

const char* exceptions::StackIsEmpty::what() const noexcept
{
    return  "Stack is empty. Can't do \"pop\".";
}

const char* exceptions::notEnoughParameters::what() const noexcept
{
    return "Stack has't enough numbers. \n";
}

const char* exceptions::InvalidOperands::what() const noexcept
{
    return "invalid operands\n";
}

const char* exceptions::TooManyOperatorTypeMakers::what() const noexcept
{
    return "More than 1 maker was registered.\n";
}

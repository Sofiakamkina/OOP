#include "Operand.h"

Operand::Operand(double value)
{
    _value = value;
}
Operand::Operand(std::string &value, std::map<std::string, double> definitions)
{

    setValue(value, definitions);
}

bool Operand::isValue(std::string str)
{
    if(str.empty())
        return false;
    int NumberOfR = 0;
    for(std::string::const_iterator it = str.begin(); it!=str.end();  ++it)
    {
        if((!isdigit(*it) && (*it != consts::DOT)) || NumberOfR>1)
            return false;
        if((*it == consts::DOT))
        {
            ++NumberOfR;
        }
    }
    return true;
}

double Operand::getValue()
{
    return _value;
}

std::string Operand::getName()
{
    return name;
}
void Operand::setValue(std::string value, std::map<std::string, double> definitions)
{
    if(definitions.find(value) != definitions.end())
        _value = definitions[value];
    else if(isValue(value))
    {
        _value = std::stod(value);
    }
    name = value;
}

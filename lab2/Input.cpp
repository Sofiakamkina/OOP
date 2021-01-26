#include "Input.h"

std::string InputConsole::getCommandLine()
{
    std::string result;
    std::getline(std::cin,result);
    return result;
}
bool InputConsole::hasMoreInput()
{
    return true;
}

void InputConsole::closeInput()
{

}
InputFile::InputFile(char* fileName)
{
    in.open(fileName);
}

std::string InputFile::getCommandLine()
{
    std::string result;
    std::getline(in,result);
    return result;
}

bool InputFile::hasMoreInput()
{
    return !in.eof();
}
void InputFile::closeInput()
{
    in.close();
}

#include "Calculator.h"
#include "Exceptions.h"

Calculator::Calculator(int argc, char* argv[])
{
    switch(argc)
    {
        case consts::WithoutNameOfFile:
            input = new InputConsole;
            break;
        case consts::IndexInputFile:
            input = new InputFile(argv[consts::IndexInputFile]);
            break;
        default:
            throw exceptions::WrongNumberOfParamter();
    }
}

void Calculator::run()
{
    Context a;
    programOn = true;
    while(programOn &&  input->hasMoreInput())
    {
        try
        {
            std::string inputLine = input->getCommandLine();
            if(inputLine.empty())
                closeProgram();
            else
                iprocessor.calculate(inputLine, &a);
        }
        catch(exceptions::WrongNameOfOperation &e)
        {
            std::cerr<<e.what();
        }
        catch(exceptions::StackIsEmpty &e)
        {
            std::cerr<<e.what();
        }
        catch(exceptions::notEnoughParameters &e)
        {
            std::cerr<<e.what();
        }
    }
    closeProgram();

}

void Calculator::closeProgram()
{
    programOn = false;
    input->closeInput();
}

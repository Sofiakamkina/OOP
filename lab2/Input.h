#include <fstream>
#include <string>
#include <map>
#include <iostream>

using std::map;
class Input
{
public:
    virtual std::string getCommandLine() = 0;
    virtual bool hasMoreInput() = 0;
    virtual void closeInput() = 0;
};

class InputConsole: public Input
{
public:
    std::string getCommandLine();
    bool hasMoreInput();
    void closeInput();
};

class InputFile: public Input
{
private:
    std::ifstream in;
public:
    InputFile(char* fileName);
    std::string getCommandLine();
    bool hasMoreInput();
    void closeInput();
};

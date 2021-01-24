using std::map;
class Input
{
public:
    virtual string getCommandLine() = 0;
    virtual bool hasMoreInput() = 0;
    virtual void closeInput() = 0;
};

class InputConsole: public Input
{
public:
    string getCommandLine();
    bool hasMoreInput();
    void closeInput();
};

class InputFile: public Input
{
private:
    std::ifstream in;
public:
    InputFile(char* fileName);
    string getCommandLine();
    bool hasMoreInput();
    void closeInput();
};

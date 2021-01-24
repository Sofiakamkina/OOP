#include "Parser.h"

std::vector<string> Parser::parser(string str)
{
    string action, operatorFirst, operatorSecond;
    std::vector<string> tokens;
    size_t spaceFirst = str.find(consts::SPACE), spaceSecond = str.rfind(consts::SPACE);
    long long int spaceCount = std::count(str.begin(),str.end(), consts::SPACE);
    std::string::iterator pbegin = str.begin(), pend = str.begin();

    if(str[consts::IndexComment] == consts::COMMENTS)
    {
        tokens.push_back(action);
        return tokens;
    }
    switch (spaceCount)
    {
        case consts::NULLSPACES:
            action = str;
            break;
        case consts::ONESPACE:
            pend += spaceFirst;
            std::copy(pbegin, pend, std::back_inserter(action));
            pbegin = pend + consts::ONESPACE;
            pend = str.end();
            std::copy(pbegin , pend, std::back_inserter(operatorFirst));
            break;
        case consts::TWOSPACES:
            pend += spaceFirst;
            std::copy(pbegin, pend, std::back_inserter(action));

            pbegin = pend + consts::ONESPACE;
            pend += spaceSecond - spaceFirst;
            std::copy(pbegin, pend, std::back_inserter(operatorFirst));

            pbegin = pend + consts::ONESPACE;
            pend = str.end();
            std::copy(pbegin , pend, std::back_inserter(operatorSecond));
            break;
        default:
            throw exceptions::InvalidOperands();
    }
    std::transform(action.begin(), action.end(), action.begin(), tolower);
    tokens.push_back(action);

    tokens.push_back(operatorFirst);
    tokens.push_back(operatorSecond);
    return tokens;
}

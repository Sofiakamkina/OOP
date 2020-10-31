#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <exception>
#include <algorithm>

class FrequencyWords {
public:
    FrequencyWords();
    void ReadFile(const std::string& fileInName);
    void WriteFile(const std::string& fileOutName);
private:
    size_t words = 0;
    std::map<std::string, size_t> frequencyWords;
};

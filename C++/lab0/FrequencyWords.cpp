#include "FrequencyWords.h"

    FrequencyWords::FrequencyWords() = default;

    void FrequencyWords::ReadFile(const std::string& fileInName) {
        std::ifstream input;
        input.open(fileInName);
        if(!input) {
            throw std::logic_error("Unable to open input file.");
        }

        std::string buffer, word;
        while(!input.eof()) {
            std::getline(input, buffer);
            for(size_t i = 0; i < buffer.size(); ++ i) {
                if((buffer[i] > 47 && buffer[i] < 58) || (buffer[i] > 64  && buffer[i] < 91) ||
                   (buffer[i] > 96 && buffer[i] < 123)) {
                    word += buffer[i];
                } else if(!word.empty()) {
                    frequencyWords[word]++;
                    words++;
                    word.clear();
                }
            }
        }
    }

    void FrequencyWords::WriteFile(const std::string& fileOutName) {
        std::ofstream output;
        output.open(fileOutName);
        if(!output) {
            throw std::logic_error("Unable to open output file.");
        }

        std::vector<std::pair<std::string, size_t> > sortFrequency;

        for(const auto& elem : frequencyWords) {
            sortFrequency.emplace_back(make_pair(elem.first, elem.second));
        }

        sort(begin(sortFrequency), end(sortFrequency),
             [](const std::pair<std::string, size_t>& lhs,
                const std::pair<std::string, size_t>& rhs) {
                 return lhs.second > rhs.second;
             });

        for(const auto& elem : sortFrequency) {
            output << elem.first << "," << elem.second << ","
                   << 100 * elem.second / (float)words << "%" << std::endl;
        }
    }

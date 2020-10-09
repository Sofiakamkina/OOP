#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>
#include <map>

class FrequencyWords {
public:
    explicit FrequencyWords(char* argv[]) : words(0) {
        input.open(argv[1]);
        output.open(argv[2]);
        ReadFail();
        ParsingWords();
    }

    void ReadFail() {
        std::string buffer, word;
        while(!input.eof()) {
            std::getline(input, buffer);
            for(size_t i = 0; i < buffer.size(); ++ i) {
                if((buffer[i] > 47 && buffer[i] < 58) || (buffer[i] > 64  && buffer[i] < 91) ||
                        (buffer[i] > 96 && buffer[i] < 123)) {
                    word += buffer[i];
                } else if(!word.empty()) {
                    auto it = frequencyWords.find(word);
                    if(it != end(frequencyWords)) {
                        frequencyWords[word] = ++(it->second);
                    } else {
                        frequencyWords[word] = 1;
                    }
                    words++;
                    word.clear();
                }
            }
        }
    }

    void ParsingWords() {
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

    ~FrequencyWords() {
        input.close();
        output.close();
    }
private:
    std::ifstream input;
    std::ofstream output;
    size_t words;
    std::map<std::string, size_t> frequencyWords;
};

int main(int argc, char* argv[]) {
    if(argc == 3) {
        FrequencyWords frequencyWords(argv);
    } else {
        throw std::invalid_argument("arguments is not 3");
    }
    return 0;
}	

#include "FrequencyWords.h"

int main(int argc, char* argv[]) {
    if(argc == 3) {
        FrequencyWords frequencyWords;
        frequencyWords.ReadFile(argv[1]);
        frequencyWords.WriteFile(argv[2]);
    } else {
        throw std::invalid_argument("arguments is not 3");
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>


const unsigned int letterCount = 9;
const unsigned int min = 4;
const unsigned int max = 9;

bool validWordLength(std::string x, int lenMin, int lenMax){
    if (x.length() >= lenMin && x.length() <= lenMax){
        return true;
    } else {
        return false;
    }
}

bool checkLetterMatch(std::string x, char letterList[letterCount]){
    bool letterUsed[letterCount];
    for (int i = 0; i < letterCount; i ++){
        letterUsed[i] = false;
    }
    for (int i = 0; i < x.length(); i++){
        for (int j = 0; j <= letterCount; j++){
            if (j == letterCount){
                return false;
            }
            if (!letterUsed[j] && letterList[j] == x[i]){
                letterUsed[j] = true;
                break;
            }
        }
    }
    return true;
}

int main(){
    char letters[letterCount];
    while (true){
        std::cout << "Enter the letters seperated by a space: ";
        for (int i = 0; i < letterCount; i++){
            std::cin >> letters[i];
        }
        std::ifstream dictionary("dictionary.txt");
        std::string output;
        std::vector<std::string> usableWords;
        while(true){
            std::getline(dictionary, output);
            if (output == ""){
                break;
            }
            if (validWordLength(output, min, max)){
                if (checkLetterMatch(output, letters)){
                    usableWords.push_back(output);
                    //std::cout << output << std::endl;
                }
            }
        }
        std::cout << std::endl;
        for (int i = min; i <= max; i++){
            std::cout << std::endl << i << " LETTER WORDS: " << std::endl << std::endl;
            for (int j = 0; j < usableWords.size(); j++){
                if (usableWords[j].length() == i){
                    std::cout << usableWords[j] << std::endl;
                }
            }
        }
        system("pause");
    }
}
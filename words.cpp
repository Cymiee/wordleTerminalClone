//
// Created by Avyukt Chamria on 08/06/26.
//

#include "words.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>


std::vector<std::string> loadWords() {
    std::vector<std::string> words;
    std::ifstream wordF(WORDS_FILE);
    if (!wordF.is_open()) {
        std::cerr << "Error: Could not open file\n";
        return words;
    }
    std::string word;
    while (std::getline(wordF, word)) {
        if (!word.empty() && word.back() == '\r')
            word.pop_back();
        if (word.length() == 5)
            words.push_back(word);
    }
    return words;
}

std::string getWord() {
    const std::vector<std::string> words = loadWords();
    if (words.empty()) {
        std::cerr << "Error: word list is empty\n";
        return "";
    }
    static std::mt19937 rng { std::random_device{}() };
    std::uniform_int_distribution<std::size_t> dist {0, words.size() - 1};
    return words[dist(rng)];
}
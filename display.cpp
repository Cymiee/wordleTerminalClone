//
// Created by Avyukt Chamria on 08/06/26.
//

#include "display.h"
#include <string>
#include <iostream>
#include <array>
#include <vector>

constexpr const char* GRAY = "\033[100m";
constexpr const char* YELLOW = "\033[43m";
constexpr const char* GREEN = "\033[42m";
constexpr const char* RESET = "\033[0m";

void printRow(const std::string& guess, const std::array<LetterResult, 5>& guessScores) {
    for (int i = 0; i < 5; i++) {
        if (guessScores[i] == LetterResult::Correct) {
            std::cout << GREEN << guess[i] << RESET;
        }
        else if (guessScores[i] == LetterResult::Misplaced) {
            std::cout << YELLOW << guess[i] << RESET;
        }
        else if (guessScores[i] == LetterResult::Wrong) {
            std::cout << GRAY << guess[i] << RESET;
        }
        else {
            std::cout << guess[i];
            std::cerr << "Unexpected state, cannot determine color.\n";
        }
    }
    std::cout << '\n';
}

void printBoard(const std::vector<GuessResult>& board) {
    for (const GuessResult& currResult: board) {
        printRow(currResult.guess, currResult.scores);
    }
}
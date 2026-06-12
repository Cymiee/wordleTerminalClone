//
// Created by Avyukt Chamria on 08/06/26.
//

#include "display.h"
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <map>

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

void printKeyboard(const std::vector<GuessResult>& board) {
    std::map<char, LetterResult> letterStates;

    for (const GuessResult& result : board) {
        for (int i = 0; i < 5; i++) {
            char c = result.guess[i];
            LetterResult score = result.scores[i];

            if (!letterStates.contains(c)) {
                letterStates.insert(std::pair(c, score));
            } else {
                if (score == LetterResult::Correct ||
                    (score == LetterResult::Misplaced && letterStates[c] == LetterResult::Wrong)) {
                    letterStates[c] = score;
                    }
            }
        }
    }

    const std::string rows[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

    for (const std::string& row : rows) {
        for (char c : row) {
            auto it = letterStates.find(c);
            if (it == letterStates.end()) {
                std::cout << c;
            } else if (it->second == LetterResult::Correct) {
                std::cout << GREEN << c << RESET;
            } else if (it->second == LetterResult::Misplaced) {
                std::cout << YELLOW << c << RESET;
            } else {
                std::cout << GRAY << c << RESET;
            }
        }
        std::cout << '\n';
    }
}
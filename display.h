//
// Created by Avyukt Chamria on 08/06/26.
//

#ifndef WORDLECLONE_DISPLAY_H
#define WORDLECLONE_DISPLAY_H

#include "guess.h"
#include <string>
#include <array>
#include <vector>

struct GuessResult {
    std::string guess;
    std::array<LetterResult, 5> scores;
};

void printBoard(const std::vector<GuessResult>& board);
void printKeyboard(const std::vector<GuessResult>& board);

#endif //WORDLECLONE_DISPLAY_H

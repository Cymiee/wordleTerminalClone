//
// Created by Avyukt Chamria on 08/06/26.
//

#ifndef WORDLECLONE_GUESS_H
#define WORDLECLONE_GUESS_H
#include <array>
#include <string>
#include <vector>

enum class LetterResult { Wrong, Misplaced, Correct};

std::array<LetterResult, 5> scoreGuess(const std::string& guess, const std::string& answer);
bool validateGuess(const std::string& guess, const std::vector<std::string>& words);

#endif //WORDLECLONE_GUESS_H

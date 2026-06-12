//
// Created by Avyukt Chamria on 08/06/26.
//

#include "guess.h"

#include <algorithm>
#include <array>
#include <string>
#include <vector>

std::array<LetterResult, 5> scoreGuess(const std::string& guess, const std::string& answer) {
    std::array<LetterResult, 5> result {LetterResult::Wrong};
    std::array<bool, 5> answerUsed {false};

    for (int i = 0; i < 5; i++) {
        if (guess[i] == answer[i]) {
            result[i] = LetterResult::Correct;
            answerUsed[i] = true;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (result[i] == LetterResult::Correct) continue;

        for (int j = 0; j < 5; j++) {
            if (answerUsed[j]) continue;

            if (guess[i] == answer[j]) {
                result[i] = LetterResult::Misplaced;
                answerUsed[j] = true;
                break;
            }
        }
    }

    return result;
}

bool validateGuess(const std::string& guess, const std::vector<std::string>& words) {
    return std::ranges::binary_search(words, guess);
}
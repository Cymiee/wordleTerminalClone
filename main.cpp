#include <algorithm>

#include "words.h"
#include "display.h"
#include "guess.h"

#include <iostream>


void clearTerminal() {
    // \033[2J clears the screen, \033[1;1H moves cursor to row 1, column 1
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    int guessNo {0};
    const std::vector<std::string> words {loadWords()};
    const std::string answer = pickWord(words);
    std::vector<GuessResult> board;

    while (true) {
        clearTerminal();
        std::cout << "Guess the word:\n";
        std::string guess;
        std::cin >> guess;

        if (guess.length() != 5) {
            std::cout << "Please enter a 5-letter word.\n";
            continue;
        }

        if (!validateGuess(guess, words)) {
            std::cout << "Please enter a valid word.\n";
            continue;
        }

        const std::array result {scoreGuess(guess, answer)};
        GuessResult guessResult {guess, result};
        board.push_back(guessResult);
        printBoard(board);
        std::cout << '\n';
        printKeyboard(board);
        guessNo++;

        if (guess == answer) {
            std::cout << "You won!\n";
            break;
        }
        if (guessNo >= 6) {
            std::cout << "Game over! The word was: " << answer << '\n';
            break;
        }
    }
}
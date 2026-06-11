#include "words.h"
#include "display.h"
#include "guess.h"

#include <iostream>
#include <cstdlib>

void clearTerminal() {
    // \033[2J clears the screen, \033[1;1H moves cursor to row 1, column 1
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    int guessNo {0};
    const std::vector<std::string> words {loadWords()};
    const std::string answer = pickWord(words);
    std::cout << answer << '\n';
    std::vector<GuessResult> board;

    while (true) {
        std::system("clear");
        std::cout << "Guess the word:\n";
        std::string guess;
        std::cin >> guess;

        if (guess.length() != 5) {
            std::cout << "Please enter a 5-letter word.\n";
            continue;
        }

        const std::array result {scoreGuess(guess, answer)};
        GuessResult guessResult {guess, result};
        board.push_back(guessResult);
        printBoard(board);
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
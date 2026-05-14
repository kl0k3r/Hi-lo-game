#include <iostream>
#include "Random.h"


int getGuess(int currentGuess) {
    std::cout << "Guess #" << currentGuess << ": ";
    int userNum{};
    std::cin >> userNum;
    return userNum;
}

void printRes(int currentGuess, int myNum) {
    if (currentGuess < myNum) {
        std::cout << "Your guess is too low.\n";
    }
    else if (currentGuess > myNum) {
        std::cout << "Your guess is too high.\n";
    }
    else {
        std::cout << "Correct! You win!\n";
    }
}

bool compare(int myNum, int currentGuess) {
    if (myNum > currentGuess) {
        std::cout << "Your guess is too low.\n";
        return false;
    }
    else if (myNum < currentGuess) {
        std::cout << "Your guess is too high.\n";
        return false;
    }
    else {
        std::cout << "Correct! You win!\n";
        return true;
    }
}

char askToPlayAgain() {
    char answer{};
    do {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> answer;
    }
    while (!(answer == 'y' || answer == 'n'));

    return answer;
}

int getRandNum() {
    int myNum{Random::get(1, 100)};
    return myNum;
}

int main() {
    bool won{false};
    char wannaPlay {'y'};
    do {
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
        int myNum{getRandNum()};
        std::cout << myNum << '\n'; // FOR DEVELOPING PURPOSES ONLY
        for (int i {1}; i <= 7; ++i) {
            int userNum{getGuess(i)};
            won = compare(myNum, userNum);
            if (won) {
                wannaPlay = askToPlayAgain();
                break;
            }
            else
                continue;
        }
        if (!won) {
            std::cout << "Sorry, you lose. The correct number was " << myNum << ".\n";
            wannaPlay = askToPlayAgain();
        }
    } while (wannaPlay != 'n');
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void displayWelcome() {
    cout << "\n==================================" << endl;
    cout << "   🎮 NUMBER GUESSING GAME 🎮    " << endl;
    cout << "==================================" << endl;
    cout << "\nI'm thinking of a number between 1 and 100." << endl;
    cout << "Can you guess it?\n" << endl;
}

void playGame() {
    int secretNumber = (rand() % 100) + 1;
    int guess;
    int attempts = 0;
    int maxAttempts = 10;
    bool won = false;

    while (attempts < maxAttempts && !won) {
        cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << " - Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "❌ Invalid input! Please enter a number.\n" << endl;
            continue;
        }

        attempts++;

        if (guess < 1 || guess > 100) {
            cout << "❌ Please guess a number between 1 and 100!\n" << endl;
            attempts--;
        }
        else if (guess < secretNumber) {
            cout << "📈 Too low! Try higher.\n" << endl;
        }
        else if (guess > secretNumber) {
            cout << "📉 Too high! Try lower.\n" << endl;
        }
        else {
            won = true;
            cout << "\n🎉 CONGRATULATIONS! 🎉" << endl;
            cout << "You guessed the number " << secretNumber << " in " << attempts << " attempts!" << endl;
            
            if (attempts <= 3) {
                cout << "⭐⭐⭐ AMAZING! You're a mind reader!" << endl;
            } else if (attempts <= 6) {
                cout << "⭐⭐ Great job! Very impressive!" << endl;
            } else {
                cout << "⭐ Good effort! You got it!" << endl;
            }
        }
    }

    if (!won) {
        cout << "\n😞 Game Over! You've used all " << maxAttempts << " attempts." << endl;
        cout << "The secret number was: " << secretNumber << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    char playAgain;

    do {
        displayWelcome();
        playGame();

        cout << "\n==================================" << endl;
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye! 👋\n" << endl;

    return 0;
}
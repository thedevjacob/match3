#include <iostream>  // For input/output operations
#include <cstdlib>   // For random number generation
#include <ctime>     // For time function to seed the random number generator

using namespace std;

// Function to generate a random character from a set of characters
char generateRandomCharacter() {
    const char chars[] = {'#', '*', '%', '+'};  // Set of possible characters
    return chars[rand() % 4];  // Randomly select a character from the set
}

// Function to play the casino match game
void playCasinoGame(int& cash) {
    char guess;
    int matchCount = 0;

    cout << "Pick a character from the following: #, *, %, + : ";
    cin >> guess;

    // Check if the guess is valid
    if (guess != '#' && guess != '*' && guess != '%' && guess != '+') {
        cout << "Invalid guess! Choose one of the following characters: #, *, %, +" << endl;
        return;
    }

    // Check how many times the random character matches the user's guess
    for (int i = 0; i < 3; ++i) {
        if (generateRandomCharacter() == guess) {
            matchCount++;
        }
    }

    if (matchCount == 3) {
        cout << "You won! All 3 characters matched!" << endl;
        cash *= 10;  // Win 10x the bet
    } else {
        cout << "You lost. Only " << matchCount << " match(es)." << endl;
        cash = 0;  // Lose all cash if not all 3 characters match
    }

    cout << "Final cash: $" << cash << endl;
}

int main() {
    int cash;

    cout << "Welcome to the Casino Match 3 Game!" << endl;
    cout << "Enter cash to play: $";
    cin >> cash;

    if (cash <= 0) {
        cout << "You need positive cash to play!" << endl;
        return 0;
    }

    srand(time(0));  // Seed random number generator

    playCasinoGame(cash);  // Call the game function

    return 0;
}

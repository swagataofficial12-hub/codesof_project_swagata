#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess, tries = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Guess the number between 1 and 100\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess > number)
            cout << "Too high! Try again.\n";
        else if (guess < number)
            cout << "Too low! Try again.\n";
        else
            cout << "Congratulations! You guessed it in " << tries << " attempts.\n";
    } while (guess != number);

    return 0;
}

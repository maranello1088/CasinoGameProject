// CasinoGameProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawLine(int n, char symbol);
void rules();

int main()
{
    string playerName;
    int amount;
    int stake;
    int guess;
    int dice;
    char choice;

    srand(time(0));

    drawLine(60, '_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60, '_');

    cout << "\n\nEnter Your Name: ";
    getline(cin, playerName);

    cout << "\n\nEnter Deposit amount to play this game: $";
    cin >> amount;

    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << amount << "\n";

        do
        {
            cout << playerName << ", enter money to bet : $";
            cin >> stake;
            if (stake > amount)
                cout << "Insufficient funds to place this bet\n"
                << "\nPlease use an amount lower than your available balance\n";
        } while (stake > amount);

        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "Please check the number!! Select a number from 1 to 10\n"
                << "\nRe-enter data\n";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1;

        if (dice == guess)
        {
            cout << "\n\nGood Luck!! You won $ " << stake * 10;
            amount = amount + stake * 10;
        }
        else
        {
            cout << "Bad luck this time!! You lost $ " << stake << "\n";
            amount = amount - stake;
        }
        cout << "\nThe winning number was : " << dice << "\n";
        cout << "\n" << playerName << ", You have $ " << amount << "\n";
        if (amount == 0)
        {
            cout << "You have no money to play";
            break;
        }
        cout << "\n\n-->Do you want to play again(y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\nThanks for playing the game, better luck next time. Your balance amount is $ " << amount << "\n\n";
    drawLine(70, '=');
    return 0;
}

void drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
        cout << symbol;
    cout << "\n";
}

void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80, '-');
    cout << "\nt1. Choose any number between 1 to 10\n";
    cout << "\nt2. If you win you will get 10 times the money you bet\n";
    cout << "nt3. Iff you bet on wrong number you will loose your betting amount\n\n";
    drawLine(80, '-');
}

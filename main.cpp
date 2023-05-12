#include<iostream>
#include "Blackjack.h"
using namespace std;


int main()
{

    int GameHandCount = 1;

    do
    {
        cout << "\nHand #:" << GameHandCount << "\n\n";
        Blackjack vegas_fun;
        vegas_fun.playGame();
        GameHandCount++;
    }while (GameHandCount <=100);

    cout << "\nThanks for playing!\n";
    system("pause");
    return 0;
}

#include<iostream>
#include "Blackjack.h"
using namespace std;

Blackjack::Blackjack()
{
    srand(time(0));
    DealerHandSize = 0;
    PlayerHandSize = 0;
    DealerHandSum = 0;
    PlayerHandSum = 0;
    playerDone = false;
    dealerDone = false;
}

void Blackjack::playGame()
{
    cout << "Welcome to Blackjack!\n";

    // Start the player and dealer with two cards
    addPlayerCard();
    addPlayerCard();
    addDealerCard();
    addDealerCard();
    sumHands();
    printHand();

    if (DealerHandSum == 21)
    {
        cout << "Dealer has blackjack. Dealer wins.\n";
        return;
    }
    else if (PlayerHandSum == 21)
    {
        cout << "Player has blackjack. Player wins.\n";
        return;
    }

    while (dealerDone == false || playerDone == false)
    {
        if (playerDone == false)
        {
            cout << "Would you like to hit? (1 - Yes, 2 - No)\n";
            cin >> PlayerHit;

            if (PlayerHit == 1)
            {
                addPlayerCard();
                printHand();
                sumHands();

                if (PlayerHandSum > 21)
                {
                    cout << "Player's hand exceeded 21. Player loses.\n";
                    return;
                }
            }
        }

        if (playerDone == false)
        {
            cout << "Would you like to stand? (1 - Yes, 2 - No)\n";
            cin >> PlayerStand;
        }

        if (PlayerStand == 1)
        {
            playerDone = true;
        }

        if (DealerHandSum < 17 && dealerDone != true)
        {
            addDealerCard();
            printHand();
            sumHands();

            if (DealerHandSum > 21)
            {
                cout << "Dealer hand exceeded 21. Dealer loses.\n";
                return;
            }
        }
        else if (DealerHandSum >= 17)
        {
            dealerDone = true;
        }

        if (PlayerHandSum == 21 && DealerHandSum == 21)
        {
            cout << "Push, player and dealer reached 21.\n";
            return;
        }
        else if (PlayerHandSum == 21)
        {
            cout << "Player reached 21. Player wins.\n";
            return;
        }
        else if (DealerHandSum == 21)
        {
            cout << "Dealer reached 21. Dealer wins.\n";
            return;
        }

        if ((playerDone == true && dealerDone == true) || (PlayerHandSize == 5 && DealerHandSize == 5))
        {
            if (DealerHandSum < PlayerHandSum)
            {
                cout << "Sum of your hand exceeds the dealer's sum of " << DealerHandSum << "! You win!\n";
                return;
            }
            else if (PlayerHandSum == DealerHandSum)
            {
                cout << "Dealer sum of " << DealerHandSum << " is equal to the sum of your hand. Tie game.\n";
                return;
            }
            else if (DealerHandSum > PlayerHandSum)
            {
                cout << "Sum of your hand is lower than the dealer's sum of " << DealerHandSum << ". You lose!\n";
                return;
            }
        }
    }
}

int DealerHand[5];
int PlayerHand[5];
int DealerHandSize;
int PlayerHandSize;
int DealerHandSum;
int PlayerHandSum;
int PlayerHit;
int PlayerStand;
bool playerDone;
bool dealerDone;

void Blackjack::addPlayerCard()
{
    if (PlayerHandSize <= 5)
    {
        PlayerHand[PlayerHandSize] = 1 + (rand() % 11);
        PlayerHandSize++;
    }
    else
    {
        cout << "Sorry. You have reached the maximum number of cards (5).\n" << endl;
        playerDone = true;
    }
}

void Blackjack::addDealerCard()
{
    if (DealerHandSize <= 5)
    {
        DealerHand[DealerHandSize] = 1 + (rand() % 11);
        DealerHandSize++;
    }
    else
    {
        dealerDone = true;
    }
}

void Blackjack::printHand()
{
    cout << "Your current hand is...\n";

    for (int i = 0; i < PlayerHandSize; i++)
    {
        cout << "    -" << PlayerHand[i] << "-    \n\n";
    }

    cout << "Dealer's current hand is...\n";

    for (int j = 0; j < DealerHandSize; j++)
    {
        cout << "    -" << DealerHand[j] << "-    \n\n";
    }
}

void Blackjack::sumHands()
{
    DealerHandSum = 0;
    PlayerHandSum = 0;
    for (int i = 0; i < DealerHandSize; i++)
    {
        DealerHandSum += DealerHand[i];
    }

    for (int j = 0; j < PlayerHandSize; j++)
    {
        PlayerHandSum += PlayerHand[j];
    }

    cout << "Current player hand sum is: " << PlayerHandSum << endl;
}

#pragma once
#include<iostream>
using namespace std;

class Blackjack
{
public:
    Blackjack();
    void playGame();

private:
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
    void addPlayerCard();
    void addDealerCard();
    void printHand();
    void sumHands();
};

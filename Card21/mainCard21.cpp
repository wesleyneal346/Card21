#pragma once
#include <iostream>

#include "math.h"

#include "Card.h"
#include "Deck.h"
using namespace std;

void main(int argc, char* argv[]) {
    char c;
    Deck casino;
    Deck hand(NO_FACE, NO_SUIT);
	
	//Shuffle the Deck
    casino.shuffle();

	// Print the cards to show where they are
	cout << "\n\tCasion Deck:" << endl;
	casino.printRemaining();

	cout << "\n\tHand Deck:" << endl;
	hand.printRemaining();

	// Deal Half of the deck
    for (int i = 0; i < MAX_CARDS / 2; i++) {
        hand.pickUpCard(casino.draw());
    }

	// Print the cards to show where they are
    cout << "\n\tCasion Deck:" << endl;
    casino.printRemaining();

    cout << "\n\tHand Deck:" << endl;
    hand.printRemaining();

	// Discard from the player hand a fourth of the deck
    for (int i = 0; i < MAX_CARDS / 4; i++) {
        casino.pickUpCard(hand.draw());
    }

	// Print the cards to show where they are
    cout << "\n\tCasion Deck:" << endl;
    casino.printRemaining();

    cout << "\n\tHand Deck:" << endl;
    hand.printRemaining();

	// A pause to show screen
    cin >> c;
    return;
}
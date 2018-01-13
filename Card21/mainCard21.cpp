#pragma once
#include <iostream>

#include "math.h"

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Person.h"
#include "Dealer.h"
#include "Name_Generator.h"
using namespace std;

void main(int argc, char* argv[]) {
    char c;
	Card nullCard(NO_FACE, NO_SUIT);
	Hand nullHand(nullCard);
	Person p1("Wesley", 12345, nullHand, 20.0, 0, 0, 0);
	Dealer dealer(0.0, "DEALER", 12346, nullHand, 20.0, 0, 0, 0);

	// Print begining stats
	dealer.printStats();
	p1.printStats();

	// Shuffle the Deck
	dealer.suffle();

	// Print the cards to show where they are
	dealer.printDeck();

	// Deal Half of the deck
	for (int i = 0; i < MAX_HAND_CAP; i++) {
		p1.acceptCard(dealer.dealCard());
		dealer.acceptCard(dealer.dealCard());
	}
	
	// Print the cards to show where they are
	dealer.printDeck();
	dealer.printStats();

	p1.printStats();

	// Discard from the player hand a fourth of the deck
	for (int i = 0; i < MAX_HAND_CAP / 2; i++) {
		dealer.returnCardToDeck(p1.discardCard(i));
		dealer.returnCardToDeck(dealer.discardCard(i));
	}

	// Place bets
	dealer.acceptBet(dealer.placeBet(19.99));
	dealer.acceptBet(p1.placeBet(10.23));

	// Print the cards to show where they are
	dealer.printDeck();
	dealer.printStats();

	p1.printStats();

	p1.~Person();
	dealer.~Dealer();
	// A pause to show screen
    cin >> c;
    return;
}
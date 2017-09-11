#pragma once
#include <iostream>

#include "math.h"

#include "Card.h"
#include "Deck.h"
using namespace std;

void main(int argc, char* argv[])
{
	char c;
	Deck casino;
	Deck hand(NO_FACE, NO_SUIT);
	
	casino.shuffle();


	for (int i = 0; i < MAX_CARDS / 2; i++) {
		hand.pickUpCard(casino.draw());
	}

	cout << "\n\tCasion Deck:" << endl;
	casino.printRemaining();

	cout << "\n\tHand Deck:" << endl;
	hand.printRemaining();

	for (int i = 0; i < MAX_CARDS / 4; i++) {
		casino.pickUpCard(hand.draw());
	}

	cout << "\n\tCasion Deck:" << endl;
	casino.printRemaining();

	cout << "\n\tHand Deck:" << endl;
	hand.printRemaining();

	cin >> c;
	return;
}
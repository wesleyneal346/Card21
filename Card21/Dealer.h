#pragma once
#include "Deck.h"
#include "Person.h"

class Dealer : public Person {
private:
	float bank;
	Deck deck;

public:
	Dealer() : bank(0), deck(), Person() {}
	Dealer(float inBank, char* inName, int inNumber, Hand inHand,
		float inWallet, int inScore, int inWins, int inLosses) :
		bank(inBank), deck(),
		Person(inName, inNumber, inHand, inWallet, inScore, inWins, inLosses) {}
	~Dealer();

	void Dealer::suffle();

	void Dealer::printStats();

	void Dealer::printDeck();

	Card Dealer::dealCard();

	void Dealer::returnCardToDeck(Card);

	float Dealer::acceptBet(float);
};


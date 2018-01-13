#include <iostream>

#include "Dealer.h"


Dealer::~Dealer() {
	this->bank = 0.0;
	this->deck.~Deck();
	this->name = "";
	this->number = 0;
	this->playerHand.~Hand();
	this->wallet = 0.0;
	this->score = 0;
	this->wins = 0;
	this->losses = 0;
	return;
}


void Dealer::suffle() {
	this->deck.shuffle();
	return;
}

void Dealer::printStats() {
	printf("\n\t%s", this->name);
	this->playerHand.printHand();
	for (int i = 0; i < this->playerHand.get_count(); i++) {
		printf("%*i", 4, i + 1);
	}
	printf("\n    Wins: %i    Losses: %i    Wallet: %.2f    Bank: \n",
		this->wins,	this->losses, this->wallet, this->bank);
	return;
}


void Dealer::printDeck() {
	this->deck.printRemaining();
	return;
}


Card Dealer::dealCard() {
	return this->deck.draw();
}


void Dealer::returnCardToDeck(Card inCard){
	this->deck.pickUpCard(inCard);
	return;
}


float Dealer::acceptBet(float bet) {
	this->bank += bet;
	return this->bank;
}
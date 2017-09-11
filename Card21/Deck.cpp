#pragma once
#include <iostream>
#include <time.h>

#include "Deck.h"



Deck::Deck()
{
	int i = 0;
	for (int j = HEARTS; j <= SPADES; j++) {
		for (int k = ACE; k <= KING; k++) {
			if (i < MAX_CARDS){
				this->arr[i].set_card(k, j);
			}
			i++;
		}
	}
	this->deckPlacePtr = 0;
	this->cardCount = MAX_CARDS;
}


Deck::Deck(int special_face, int specail_suit)
{
	int i = 0;
	for (int j = HEARTS; j <= SPADES; j++) {
		for (int k = ACE; k <= KING; k++) {
			if (i < MAX_CARDS){
				this->arr[i].set_card(special_face, specail_suit);
			}
			i++;
		}
	}
	this->deckPlacePtr = 0;
	this->cardCount = 0;
}


Deck::~Deck()
{
	for (int i = 0; i < MAX_CARDS; i++) {
		this->arr[i].~Card();
	}
	this->deckPlacePtr = 0;
	this->cardCount = 0;
	return;
}



int Deck::get_cardCount()
{
	return cardCount;
}


Card Deck::nextCard()
{
	Card result;
	Card nullCard(NO_FACE, NO_SUIT);

	if (this->deckPlacePtr >= 52){
		this->deckPlacePtr = 0;
	}
	result = this->arr[this->deckPlacePtr];
	this->deckPlacePtr++;

	return result;
}


void Deck::printDeck()
{
	Card card;
	for (int i = 0; i < MAX_CARDS; i++) {
		card = this->nextCard();
		if (card.get_face() != TEN) {
			printf(" ");
		}
		if (card.get_face() == NO_FACE) {
			printf(" ");
		}
		printf(" ");
		card.printCard();
		if ((i + 1) % 13 == 0) {
			printf("\n");
		}
	}
	this->deckPlacePtr = 0;
	return;
}


void Deck::printRemaining()
{
	Card card;
	int counter = 0;
	for (int i = 0; i < MAX_CARDS; i++) {
		card = this->nextCard();
		if (card.get_face() == NO_FACE) {
			continue;
		}
		if (card.get_face() != TEN) {
			printf(" ");
		}
		printf(" ");
		card.printCard();
		if ((counter + 1) % 13 == 0) {
			printf("\n");
		}
		counter++;
	}
	this->deckPlacePtr = 0;
	return;
}


void Deck::swapDeckCards(int p1, int p2)
{
	Card dummy;
	dummy = this->arr[p1];
	this->arr[p1] = this->arr[p2];
	this->arr[p2] = dummy;
	return;
}


void Deck::shuffle()
{
	srand(time(NULL));
	int counter = 0, swap1, swap2;
	Card dummy;

	do {
		swap1 = rand() % MAX_CARDS;
		swap2 = rand() % MAX_CARDS;
		this->swapDeckCards(swap1, swap2);
		counter++;
	} while (counter < 1000);
	return;
}


Card Deck::draw()
{
	Card drawCard;
	Card nullCard(NO_FACE, NO_SUIT);

	if (this->is_empty()) {
		printf("\n\tDECK EMPTY\n");
		return nullCard;
	}

	do {
		drawCard = nextCard();
	} while (drawCard == nullCard);

	this->arr[deckPlacePtr - 1] = nullCard;
	this->cardCount--;

	return drawCard;
}


void Deck::pickUpCard(Card card)
{
	int i = this->deckPlacePtr;
	Card nullCard(NO_FACE, NO_SUIT);
	if (!this->is_full()) {
		while (this->arr[i] != nullCard) {
			if (i >= MAX_CARDS) {
				i = 0;
			} 
			else {
				i++;
			}
		}
		this->arr[i] = card;
		this->cardCount++;
	}
}


bool Deck::is_full()
{
	if (this->cardCount == MAX_CARDS) {
		return true;
	}
	else {
		return false;
	}
}


bool Deck::is_empty()
{
	if (this->cardCount == 0) {
		return true;
	}
	else {
		return false;
	}
}


void Deck::operator=(const Deck& inDeck)
{
	for (int i = 0; i < MAX_CARDS; i++) {
		this->arr[i] = inDeck.arr[i];
	}
	this->cardCount = inDeck.cardCount;
	this->deckPlacePtr = inDeck.deckPlacePtr;
}
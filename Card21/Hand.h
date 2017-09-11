#pragma once
#include "Card.h"

const int MAX_HAND_CAP = 13;

class Hand
{
private:
	Card arr[MAX_HAND_CAP];
	int cardCount;

public:
	Hand();
	Hand(Card, int);
	Hand(Card);
	~Hand();

	void Hand::set_cards(Card);
	void Hand::set_card(Card, int);
	void Hand::set_card(Card);

	Card Hand::get_card(int);
	Card* Hand::get_cards();
	int Hand::get_count();

	void Hand::printHand();

	void Hand::pickUpCard(Card);
	Card Hand::discardCard(int);
	Hand Hand::discardHand();

	bool Hand::is_full();
	bool Hand::is_empty();

	void Hand::operator=(const Hand&);
};


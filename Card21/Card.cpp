#pragma once
#include <iostream>
#include <string>

#include "string.h"

#include "Card.h"



Card::Card()
{
	value = ACE;
	suit = suitChar[HEARTS];
}


Card::Card(int val, char* st)
{
	value = checkCardValue(val);
	suit = checkCardSuit(st);
}


Card::Card(int val, int suitIndex)
{
	value = checkCardValue(val);
	suit = checkCardSuit(suitIndex);
}


Card::~Card()
{
	value = 0;
	free((void*)suit);
}


void Card::set_card(int val, char* st)
{
	value = checkCardValue(val);
	suit = checkCardSuit(st);
}


void Card::set_card(int val, int suitIndex)
{
	value = checkCardValue(val);
	suit = checkCardSuit(suitIndex);
}

int Card::get_value()
{
	return value;
}



int Card::checkCardValue(int val)
{
	if (val >= 0 && val < 14) {
		return val;
	}
	else {
		return 0;
	}
}


char* Card::checkCardSuit(int suitIndex)
{
	if (suitIndex >= 0 && suitIndex < 4) {
		return suitChar[suitIndex];
	}
	else {
		return suitChar[0];
	}
}


char* Card::checkCardSuit(char* st)
{
	for (int i = 0; i < 4; i++) {
		if (suitChar[i] == st) {
			return st;
		}
	}
	return suitChar[0];
}

void Card::printCard()
{
	switch (value)
	{
	case ACE:
		printf("A%s", suit);
		break;
	case JACK:
		printf("J%s", suit);
		break;
	case QUEEN:
		printf("Q%s", suit);
		break;
	case KING:
		printf("K%s", suit);
		break;
	case JOKER:
		printf("Joker");
		break;
	default:
		printf("%d%s", value + 1, suit);
		break;
	}
}

int Card::operator+(const Card& card)
{
	return (this->value + 1) + (card.value + 1);
}

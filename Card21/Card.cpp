#pragma once
#include <iostream>
#include <string>

#include "string.h"

#include "Card.h"



Card::Card()
{
	face = NO_FACE;
	value = 0;
	suit = suitChar[NO_SUIT];
	color = NO_COLOR;
}


Card::Card(int val, char* st)
{
	face = checkCardFace(val);
	value = checkCardValue(val);
	suit = checkCardSuit(st);
}


Card::Card(int val, int suitIndex)
{
	face = checkCardFace(val);
	value = checkCardValue(val);
	suit = checkCardSuit(suitIndex);
}


Card::~Card()
{
	face = NO_FACE;
	value = 0;
	suit = suitChar[NO_SUIT];
	color = NO_COLOR;
}


void Card::set_card(int val, char* st)
{
	face = checkCardFace(val);
	value = checkCardValue(val);
	suit = checkCardSuit(st);
	color = checkCardColor(st);
}


void Card::set_card(int val, int suitIndex)
{
	face = checkCardFace(val);
	value = checkCardValue(val);
	suit = checkCardSuit(suitIndex);
	color = checkCardColor(suitIndex);
}


void Card::set_ace_value(int val)
{
	if (face == ACE) {
		value = val;
	}
}


int Card::get_face()
{
	return face;
}


int Card::get_value()
{
	return value;
}


char* Card::get_suit()
{
	return suit;
}


int Card::get_color()
{
	return color;
}


int Card::checkCardFace(int val)
{
	if (val > 0 && val < 14) {
		return val;
	}
	else {
		return 0;
	}
}


int Card::checkCardValue(int val)
{
	if (val > 0 && val < 10) {
		return val;
	}
	else if (val >= 10) {
		return 10;
	}
	else {
		return 0;
	}
}


char* Card::checkCardSuit(int suitIndex)
{
	if (suitIndex >= 0 && suitIndex <= 4) {
		return suitChar[suitIndex];
	}
	else {
		return suitChar[0];
	}
}


char* Card::checkCardSuit(char* st)
{
	for (int i = 1; i <= 4; i++) {
		if (suitChar[i] == st) {
			return st;
		}
	}
	return suitChar[0];
}


int Card::checkCardColor(int suitIndex)
{
	if (suitIndex == HEARTS || suitIndex == DIAMONDS) {
		return RED;
	}
	else if (suitIndex == CLUBS || suitIndex == SPADES) {
		return BLACK;
	}
	else {
		return NO_COLOR;
	}
}


int Card::checkCardColor(char* st)
{
	for (int i = 0; i < 5; i++) {
		if (suitChar[i] == st) {
			if (st == "\3" || st == "\4" || st == "H" || st == "D") {
				return RED;
			}
			else if (st == "\5" || st == "\6" || st == "C" || st == "S") {
				return BLACK;
			}
			else{
				return NO_COLOR;
			}
		}
	}
}


void Card::printCard()
{
	switch (face)
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
	default:
		printf("%d%s", face, suit);
		break;
	}
}


bool Card::is_Ace()
{
	if (face == ACE) {
		return true;
	}
	else {
		return false;
	}
}


Card Card::operator+(const Card& card)
{
	Card result;
	result.value = this->value + card.value;
	return result;
}


void Card::operator=(const Card& card)
{
	this->face = card.face;
	this->value = card.value;
	this->suit = card.suit;
	this->color = card.color;
}


bool Card::operator==(const Card& card)
{
	if (this->face == card.face && this->suit == card.suit) {
		return true;
	}
	else {
		return false;
	}
}


bool Card::operator!=(const Card& card)
{
	if (this->face != card.face || this->suit != card.suit) {
		return true;
	}
	else {
		return false;
	}
}
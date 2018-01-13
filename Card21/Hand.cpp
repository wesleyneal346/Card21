#include <iostream>

#include "Hand.h"
#include "Card.h"

Hand::Hand() {
    for (int i = 0; i < MAX_HAND_CAP; i++) {
        this->arr[i].set_card(NO_FACE, NO_SUIT);
    }
    cardCount = 0;
}


Hand::Hand(Card inCard, int index) {
    this->set_card(inCard, index);
    return;
}


Hand::Hand(Card inCard) {
    this->set_cards(inCard);
    return;
}


Hand::~Hand() {
    for (int i = 0; i < MAX_HAND_CAP; i++) {
        this->arr[i].set_card(NO_FACE, NO_SUIT);
    }
    cardCount = 0;
    return;
}


void Hand::set_cards(Card inCard) {
	Card nullCard(NO_FACE, NO_SUIT);
    for (int i = 0; i < MAX_HAND_CAP; i++) {
        this->set_card(inCard);
    }
	if (inCard == nullCard) {
		this->cardCount = 0;
	}
	else {
		this->cardCount = MAX_HAND_CAP;
	}
    return;
}


void Hand::set_card(Card inCard, int index) {
    Card nullCard(NO_FACE, NO_SUIT);
	for (int i = 0; i < MAX_HAND_CAP; i++) {
		if (this->arr[index].get_card() == nullCard) {
			this->arr[index] = inCard;
			cardCount++;
			return;
		}
		else {
			index++;
			if (index >= MAX_HAND_CAP) {
				index = 0;
			}
		}	
	}
	// maybe indicate an error here.
    return;
}


void Hand::set_card(Card inCard) {
    Card nullCard(NO_FACE, NO_SUIT);
    int i = 0;
    if (this->is_full()) {
        printf("\n\tHAND FULL\n");
        return;
    } else {
        while (this->arr[i] != nullCard && this->arr[i] != inCard) {
            i++;
			if (i >= MAX_HAND_CAP) {
				// maybe indicate an error here as well.
				return;
			}
        }
        this->arr[i] = inCard;
        cardCount++;
    }
    return;
}


Card Hand::get_card(int index) {
    return this->arr[index];
}


Card* Hand::get_cards() {
    return this->arr;
}


int Hand::get_count() {
    return this->cardCount;
}


void Hand::printHand() {
    Card card;
    int counter = 0;
	printf("\n");
    for (int i = 0; i < MAX_HAND_CAP; i++) {
        card = this->arr[i];
        if (card.get_face() == NO_FACE) {
            continue;
        }
        card.printCard();
        counter++;
    }
	printf("\n");
    return;
}


void Hand::pickUpCard(Card inCard) {
    this->set_card(inCard);
    return;
}


Card Hand::discardCard(int index) {

    Card discarded;
    Card nullCard(NO_FACE, NO_SUIT);

    if (this->is_empty()) {
        printf("\nHAND EMPTY\n");
        return nullCard;
    }

    discarded = this->arr[index];
    this->arr[index] = nullCard;
    this->cardCount--;

    return discarded;
}


Hand Hand::discardHand() {
    Hand result;
	result.cardCount = this->cardCount;
    for (int i = 0; i < MAX_HAND_CAP; i++) {
        result.arr[i] = this->discardCard(i);
    }
	this->cardCount = 0;
    return result;
}


bool Hand::is_full() {
    if (this->cardCount >= MAX_HAND_CAP) {
        return true;
    } else {
        return false;
    }
}


bool Hand::is_empty() {
    if (this->cardCount <= 0) {
        return true;
    } else {
        return false;
    }
}


void Hand::operator=(const Hand& inHand) {
    for (int i = 0; i < MAX_HAND_CAP; i++) {
        this->arr[i] = inHand.arr[i];
    }
    this->cardCount = inHand.cardCount;
}
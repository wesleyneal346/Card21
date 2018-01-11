#pragma once
#include <iostream>
#include <string>

#include "string.h"

#include "Card.h"



Card::Card() {
    this->face = NO_FACE;
    this->value = 0;
    this->suit = suitChar[NO_SUIT];
    this->color = NO_COLOR;
    return;
}


Card::Card(int val, char* st) {
    this->set_card(val, st);
    return;
}


Card::Card(int val, int suitIndex) {
    this->set_card(val, suitIndex);
    return;
}


Card::~Card() {
    this->face = NO_FACE;
    this->value = 0;
    this->suit = suitChar[NO_SUIT];
    this->color = NO_COLOR;
}


void Card::set_card(int val, char* st) {
    this->face = checkCardFace(val);
    this->value = checkCardValue(val);
    this->suit = checkCardSuit(st);
    this->color = checkCardColor(st);
}


void Card::set_card(int val, int suitIndex) {
    this->face = checkCardFace(val);
    this->value = checkCardValue(val);
    this->suit = checkCardSuit(suitIndex);
    this->color = checkCardColor(suitIndex);
}


void Card::set_card(Card inCard) {
    this->face = inCard.face;
    this->value = inCard.value;
    this->suit = inCard.suit;
    this->color = inCard.color;
}


void Card::set_ace_value(int val) {
    if (this->face == ACE) {
        this->value = val;
    }
}


int Card::get_face() {
    return this->face;
}


int Card::get_value() {
    return this->value;
}


char* Card::get_suit() {
    return this->suit;
}


int Card::get_color() {
    return this->color;
}


Card Card::get_card() {
    return *this;
}


int Card::checkCardFace(int val) {
    if (val > NO_FACE && val <= KING ) {
        return val;
    } else {
        return 0;
    }
}


int Card::checkCardValue(int val) {
    if (val > NO_FACE && val < TEN) {
        return val;
    } else if (val >= TEN) {
        return 10;
    } else {
        return 0;
    }
}


char* Card::checkCardSuit(int suitIndex) {
    if (suitIndex >= 0 && suitIndex <= 4) {
        return suitChar[suitIndex];
    } else {
        return suitChar[0];
    }
}


char* Card::checkCardSuit(char* st) {
    for (int i = 1; i <= 4; i++) {
        if (suitChar[i] == st) {
            return st;
        }
    }
    return suitChar[0];
}


int Card::checkCardColor(int suitIndex) {
    if (suitIndex == HEARTS || suitIndex == DIAMONDS) {
        return RED;
    } else if (suitIndex == CLUBS || suitIndex == SPADES) {
        return BLACK;
    } else {
        return NO_COLOR;
    }
}


int Card::checkCardColor(char* st) {
    for (int i = 0; i < 5; i++) {
        if (suitChar[i] == st) {
            if (st == "\3" || st == "\4" || st == "H" || st == "D") {
                return RED;
            } else if (st == "\5" || st == "\6" || st == "C" || st == "S") {
                return BLACK;
            } else {
                return NO_COLOR;
            }
        }
    }
}


void Card::printCard() {
    switch (this->face) {
    case ACE:
        printf("A%s", this->suit);
        break;
    case JACK:
        printf("J%s", this->suit);
        break;
    case QUEEN:
        printf("Q%s", this->suit);
        break;
    case KING:
        printf("K%s", this->suit);
        break;
    default:
        printf("%d%s", this->face, this->suit);
        break;
    }
}


bool Card::is_Ace() {
    if (this->face == ACE) {
        return true;
    } else {
        return false;
    }
}


int Card::operator+(const Card& card) {
    int result;
    result = this->value + card.value;
    return result;
}


void Card::operator=(const Card& inCard) {
    this->face = inCard.face;
    this->value = inCard.value;
    this->suit = inCard.suit;
    this->color = inCard.color;
}


bool Card::operator==(const Card& card) {
    if (this->face == card.face && this->suit == card.suit) {
        return true;
    } else {
        return false;
    }
}


bool Card::operator!=(const Card& card) {
    if (this->face != card.face || this->suit != card.suit) {
        return true;
    } else {
        return false;
    }
}
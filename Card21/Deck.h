#pragma once
#include "Card.h"

const int MAX_CARDS = 52;

class Deck {
private:
    Card arr[MAX_CARDS];
    int deckPlacePtr;
    int cardCount;

public:
    Deck();
    Deck(int, int);
    ~Deck();

    int Deck::get_cardCount();

    Card Deck::nextCard();
    void Deck::printDeck();
    void Deck::printRemaining();
    void Deck::swapDeckCards(int, int);
    void Deck::shuffle();
    Card Deck::draw();
    void Deck::pickUpCard(Card);
    bool Deck::is_full();
    bool Deck::is_empty();

    void Deck::operator=(const Deck&);
};
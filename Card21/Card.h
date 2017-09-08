#pragma once
enum SUIT { HEARTS, DIAMONDS, CLUBS, SPADES };
enum CARD_VAL { ACE, TWO, THREE, FOUR, FIVE, SIX, 
	SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, JOKER};

char* suitChar[] = { "H", "D", "C", "S" };

class Card
{
private:
	int value;
	char* suit;

public:
	Card();
	Card(int, char*);
	Card(int, int);
	~Card();

	void Card::set_card(int, char*);
	void Card::set_card(int, int);
	int Card::get_value();
	int Card::checkCardValue(int);
	char* Card::checkCardSuit(int);
	char* Card::checkCardSuit(char*);
	void Card::printCard();

	int Card::operator+(const Card&);
};
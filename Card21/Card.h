#pragma once
enum SUIT { 
	HEARTS, 
	DIAMONDS, 
	CLUBS, 
	SPADES , 
	NONE
};

enum CARD_VAL { 
	ACE = 1, 
	TWO = 2, 
	THREE = 3, 
	FOUR = 4, 
	FIVE = 5, 
	SIX = 6, 
	SEVEN = 7, 
	EIGHT = 8, 
	NINE = 9, 
	TEN = 10, 
	JACK = 11, 
	QUEEN = 12, 
	KING = 13
};

char* suitChar[] = { "H", "D", "C", "S" , "\0"};

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

	Card Card::operator+(const Card&);
};
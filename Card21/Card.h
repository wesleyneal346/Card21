#pragma once
enum SUIT {
	NO_SUIT,
	HEARTS,
	DIAMONDS,
	CLUBS,
	SPADES,
};

enum CARD_VAL {
	NO_FACE,
	ACE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING
};

enum CARD_COLOR {
	NO_COLOR,
	BLACK,
	RED
};

//char* suitChar[] = { "\0", "H", "D", "C", "S" };
char* suitChar[] = { "\0", "\3", "\4", "\5", "\6" };

class Card
{
private:
	int face;
	int value;
	char* suit;
	int color;

public:
	Card();
	Card(int, char*);
	Card(int, int);
	~Card();

	void Card::set_card(int, char*);
	void Card::set_card(int, int);
	void Card::set_card(Card);
	void Card::set_ace_value(int);

	int Card::get_face();
	int Card::get_value();
	char* Card::get_suit();
	int Card::get_color();
	Card Card::get_card();

	int Card::checkCardFace(int);
	int Card::checkCardValue(int);
	char* Card::checkCardSuit(int);
	char* Card::checkCardSuit(char*);
	int Card::checkCardColor(int);
	int Card::checkCardColor(char*);

	void Card::printCard();

	bool Card::is_Ace();

	Card Card::operator+(const Card&);
	void Card::operator=(const Card&);
	bool Card::operator==(const Card&);
	bool Card::operator!=(const Card&);
};
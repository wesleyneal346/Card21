#pragma once

/// An enumeration for the suits a card can be.
enum SUIT {
    NO_SUIT,///<0 - Base number for the suits; kind of like NULL
    HEARTS,///<1 - For the Hearts Suit
    DIAMONDS,///<2 - For the Diamonds Suit
    CLUBS,///<3 - For the Clubs Suit
    SPADES,///<4 - for the Spaess Suit
};


/// An enumeration for the numbers a Card can be
enum CARD_VAL {
    NO_FACE,///<0, or NULL
    ACE,///<1
    TWO,///<2
    THREE,///<3
    FOUR,///<4
    FIVE,///<5
    SIX,///<6
    SEVEN,///<7
    EIGHT,///<8
    NINE,///<9
    TEN,///<10
    JACK,///<11
    QUEEN,///<12
    KING///<13
};


/// An enumeration for the colors a Card can be
enum CARD_COLOR {
    NO_COLOR,///<0, or NULL
    BLACK,///<1 - For Black
    RED///<2 - For Red
};

/// 1 if normal characters, 0 if special escape characters
#define __SUIT_CHAR 0;

#if __SUIT_CHAR == 1
char* suitChar[] = { "\0", "H", "D", "C", "S" };
#else __SUIT_CHAR == 0
char* suitChar[] = { "\0", "\3", "\4", "\5", "\6" };
#endif

/// A class that handles all the parameters of a card with public functions
class Card {
protected:
    int face;///<A number indicating what card the Card is. @see SUIT
    int value;///<A number indicating the value for the card. @see CARD_VAL
    char* suit;///<A char indicating the suit of the Card; @see __SUIT_CHAR
    int color;///<A number indicating the color of the Card. @see CARD_COLOR

public:
	/// The default Card constructor that sets everything to 0.
    Card();

	/// @brief A Card constructor overload that sets the Card to the input given
	/// @param val The value to set the Card to
	/// @param st the char string to set the suit and color of the Card
    Card(int, char*);

	/// @brief a Card constructor overload that sets the Card to the input given
	/// @param val The value to set the Card to
	/// @param suitIndex A number indicating what to set the suit and color of
	/// the Card to
    Card(int, int);

	/// the default Card deconstructor that sets everything to 0
    ~Card();

	/// @brief Sets the Card to the input given
	/// @param val The value to set the Card to
	/// @param st the char string to set the suit and color of the Card
	void Card::set_card(int, char*);

	/// @brief Sets the Card to the input given
	/// @param val The value to set the Card to
	/// @param suitIndex A number indicating what to set the suit and color of
	/// the Card to
    void Card::set_card(int, int);

	/// @brief Sets the Card to the Card given. @note This is like the '=' sign
	/// @param inCard The incoming Card for to copy data from
    void Card::set_card(Card);

	/// @brief Set the value of the Ace card. Can be either 11 or a 1
	/// @param val The value to set the Ace card to. Should be either an 11 or 1
    void Card::set_ace_value(int);

	/// @brief Returns the Face of the card; Ace to King
	/// @return Returns an integer indicating the face of the Card
	int Card::get_face();

	/// @brief Returns the value of the card; 0 - 11
	/// @return Returns an integer indicating the value of the Card
	int Card::get_value();

	/// @brief Returns the suit of the card; @see SUIT or __SUIT_CHAR
	/// @return Returns a char pointer indicating the suit of the Card
	char* Card::get_suit();

	/// @brief Returns the color of the card; red or black
	/// @return Returns an integer indicating the color of the Card
	int Card::get_color();

	/// @brief Returns the entire Card
	/// @return Returns a Card instance
    Card Card::get_card();

	/// @brief Checks the input given to see if it's within range of the values
	/// for the face.
	/// @return Returns an integer indicating the face of the Card
	/// @note No private variables are changed in the function.
	int Card::checkCardFace(int);

	/// @brief Checks the input given to see if it's within range of the values
	/// for the values.
	/// @return Returns an integer indicating the value of the Card
	/// @note No private variables are changed in the function.
	/// Score is calculated as follows:
	/// - Ace    1 or 11 points depending on the Person
	/// - Two    2 points
	/// - Three  3 points
	/// - Four   4 points
	/// - Five   5 points
	/// - Six    6 points
	/// - Seven  7 points
	/// - Eight  8 points
	/// - Nine   9 points
	/// - Ten   10 points
	/// - Jack  10 points
	/// - Queen 10 points
	/// - King  10 points
	int Card::checkCardValue(int);

	/// @brief Checks the input given to see if it's within range of the values
	/// for the suit.
	/// @return Returns a char indicating the suit of the Card
	/// @note No private variables are changed in the function.
	char* Card::checkCardSuit(int);

	/// @brief Checks the input given to see if it's within range of the values
	/// for the suit.
	/// @return Returns a char indicating the suit of the Card
	/// @note No private variables are changed in the function.
	char* Card::checkCardSuit(char*);

	/// @brief Checks the input given to see if it's within range of the values
	/// for the color.
	/// @return Returns an integer indicating the color of the Card
	/// @note No private variables are changed in the function.
    int Card::checkCardColor(int);


	/// @brief Checks the input given to see if it's within range of the values
	/// for the color.
	/// @return Returns an integer indicating the color of the Card
	/// @note No private variables are changed in the function.
    int Card::checkCardColor(char*);

	/// @brief Prints the face and suit of the Card; A "switch case" statement
	/// is implemented for the 5 types of Cards there are.
    void Card::printCard();

	/// @brief Checks the Card instance if it is an Ace
	/// @return Returns a boolean:
	/// - true if it is an Ace
	/// - false if it is an Ace
    bool Card::is_Ace();

	/// @brief An operation overload for adding two cards together
	/// @details This operation adds the values of the Cards together
	/// @return Returns the resulting value of the operation.
    int Card::operator+(const Card&);

	/// @brief An operation overload for setting one Card equal to another
    void Card::operator=(const Card&);

	/// @brief Checks to see if one Card equals another. It only checks the face
	/// and suit
	/// @return Returns a boolean
	/// - true if they are equal
	/// - false if they are not equal
	/// @todo Think about how this function might be useful and change it
	/// according to the new design.
	bool Card::operator==(const Card&);

	/// @brief Checks to see if one Card does not equal another. It only checks
	/// the face and suit
	/// @return Returns a boolean
	/// - true if either the face or the suit or both are not equal
	/// - false if they are equal
	/// @todo Think about how this function might be useful and change it
	/// according to the new design.
    bool Card::operator!=(const Card&);
};
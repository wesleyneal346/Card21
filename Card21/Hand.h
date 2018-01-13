#pragma once
#include "Card.h"

/// The maximum allowable number of cards in a Person's Hand
const int MAX_HAND_CAP = 13;

/// A class to handle an array of Cards to be used with player Persons
class Hand : public Card {
private:
    Card arr[MAX_HAND_CAP];///<A Card array
    int cardCount;///<The current number of cards in the Card array

public:
	/// @brief The default Hand constructor; sets everything to 0.
    Hand();

	/// @brief An overloaded Hand constructor that sets one Card in the position
	/// specified by index.
	/// @param inCard The Card to be inserted in the Hand Card array.
	/// @param index The position for to insert the Card into the Card array
	/// @note This is probably not the best way or the most desireable way to
	/// set a Card into the Hand.
	Hand(Card, int);

	/// @brief An overloaded Hand constructor to sets all the Cards in the array
	/// to the Card given.
	/// @param inCard The Card to be inserted in the Hand Card array.
    Hand(Card);

	/// @brief The default Hand deconstructor; sets everthing to 0.
    ~Hand();

	/// @brief Sets all the cards in the Card array to the Card given.
	/// @param inCard The Card to set all the Cards in the array to
    void Hand::set_cards(Card);

	/// @brief Sets a single Card to the Card given in the position specified.
	/// @param inCard The Card to be inserted in the Hand Card array.
	/// @param index The position for to insert the Card into the Card array
	/// @note This is probably is not the best or the most desireable way to set
	/// a Card into the Hand. It doesn't check for duplicates and there is no
	/// guarantee that it will be inserted in the index desired.
	/// @todo Come up with a better way to do this.
    void Hand::set_card(Card, int);

	/// @brief Sets all the Cards in the array to the Card given.
	/// @param inCard The Card to be inserted in the Hand Card array.
    void Hand::set_card(Card);

	/// @brief Get the Card specified or indicated by the index
	/// @param index The position of the desired card
	/// @return Returns the card without checking for NULL or removing it from
	/// the array.
    Card Hand::get_card(int);

	/// @brief Gets all the Cards in the array.
	/// @return Returns the Card array without checking for NULL or removing
	/// them from memory
    Card* Hand::get_cards();

	/// @brief Get the count of the number of Cards in the Card array
	/// @return Returns an integer indicating the number of Cards in the Card
	/// array.
    int Hand::get_count();

	/// @brief Prints the cards in the Card array while skipping gaps.
    void Hand::printHand();

	/// @brief Puts the Card specified into the Card array
	/// @param inCard The Card to be inserted into the Card array.
	/// @todo Handle what happens when the hand is full.
    void Hand::pickUpCard(Card);

	/// @brief Discards a Card specified
	/// @param index The position of the Card in the Card array to be removed
	/// @return A Card instance that was removed from the Card array
    Card Hand::discardCard(int);

	/// @brief Discard the entire Card array
	/// @return Returns a Hand instance.
    Hand Hand::discardHand();

	/// @brief Checks to see if a Hand is full
	/// @return Returns a boolean:
	/// - true if the Hand is full
	/// - false if the Hand is not full
	bool Hand::is_full();

	/// @brief Checks to see if a Hand is empty
	/// @return Returns a boolean:
	/// - true if the Hand is empty
	/// - false if the Hand is not not empty
    bool Hand::is_empty();

	/// @brief An overloaded = operator that sets on Hand equal to another
	/// @note could possibly use this for discarding hands if clever enough
    void Hand::operator=(const Hand&);
};


#pragma once
#include "Card.h"

/// The maximum number of cards in a deck
const int MAX_CARDS = 52;

/// A class to hold cards, a place-holder in the deck, and a count of cards
class Deck {
private:
    Card arr[MAX_CARDS];///<An array to hold the Cards for the Deck
    int deckPlacePtr;///<A place-holder indicating position in the Deck
    int cardCount;///<A count of the number Cards in the Deck

public:
	/// @brief The default pointer for the Deck class.
	/// @details Sets 52 unique Cards in the Deck
	Deck();

	/// @brief The default pointer for the Deck class.
	/// @details Sets all the private member variables to 0 or NULL.
	/// @param special_face Set all faces in the deck to this user defined face.
	/// @param special_suit Set all suits in the deck to this user defined suit.
    Deck(int, int);

	/// @brief The default deconstructor for the Deck class.
	/// @details This deconstructor sets all Card slots in the Deck to 0.
    ~Deck();

	/// @brief Gets the card count of the Cards that aren't 0 or NULL. This
	/// will never be less than 0 or never greater than 52
	/// @return Returns the number of Cards in the Deck (integer).
    int Deck::get_cardCount();

	/// @brief Gets the current card pointed to by the deckPlacePointer index.
	/// @details This function actually returns the Card currently indicated by
	/// the deckPlacePtr, then it will increment the deckPlacePtr by one so it
	/// points to the "next" Card in the Deck
	/// @return Returns a Card instance pointed to by deckPlacPtr.
    Card Deck::nextCard();

	/// @brief Prints the entire deck regardless of blank slots in the Deck
	/// @details This function was inteded as a debug function to display holes
	/// in the Deck, if any exist, to prove that cards were being removed and
	/// added. Use printRemaining() instead of this function
    void Deck::printDeck();

	/// @brief Prints all Cards and skips empty slots.
	/// @details If there are any empty slots in the Deck, this function will
	/// skip them and continue on to the next Card in the Deck. It maintains
	/// "columns" for the cards to be printed in neatly.
    void Deck::printRemaining();

	/// @brief Swaps or switchs position of two Cards with eachother.
	/// @param p1 The first index or position of the Card to be swapped
	/// @param p2 The second index or position of the Card to be swapped
	/// @note This function is used in the funciton suffle().
    void Deck::swapDeckCards(int, int);

	/// @brief Suffles the Deck's Cards in a psudo-random fassion
	/// @details This function will swap the position of two randomly selected 
	/// cards. The action will repeat 1000 times. @note This gives the feel of a
	/// "good" shuffle.
    void Deck::shuffle();

	/// @brief Removes the next card form the deck.
	/// @details This funciton takes the next Card in the Deck pointed to by the
	/// deckPlacePtr index, replaces it with a null Card, then returns it to the
	/// caller. This is usefull for giving Cards to Players or discarding Cards.
	/// Returns Returns the Card that was drawn, discarded, or given.
	/// @todo Give this function a better name.
    Card Deck::draw();

	/// @brief Recieves the Card specified in the parameters into the Deck.
	/// @details This function checks to see if the Deck is_full(), which should
	/// never happen, then replaces the incoming Card with the first null Card
	/// it encounters.
	/// @param card A Card instance to be inserted in the Deck.
    void Deck::pickUpCard(Card);

	/// @brief Checks to see if the Deck contains the maximum number of Cards
	/// indicated by MAX_CARDS.
	/// @return Returns a boolean value
	/// - true if it is full
	/// - false if it not full
    bool Deck::is_full();

	/// @brief Checks to see if the Deck contains the minimum number of Cards
	/// (zero).
	/// @return Returns a boolean value
	/// - true if it is empty
	/// - false if it not empty
    bool Deck::is_empty();

	/// @brief An equal sign overload to set one Deck with the data of another.
    void Deck::operator=(const Deck&);
};
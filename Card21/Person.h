#pragma once
#include "Hand.h"

/// The maximum length a name can be
const int MAX_CHAR_CAP = 20;

/// @brief A class to handle a Person in the game.
/// @todo Add a save and load method te be invoked on startup and close
class Person {
protected:
    char* name;///<The name of the Person
    int number;///<Could be a unique identifier
    Hand playerHand;///<A Hand of Cards that the Person owns
    float wallet;///A number indicating how much money a Person has to bet
    int score;///<The number of points earned in the last game; Update in-game
    int wins;///<The total number of wins the Person has accrued
    int losses;///<The total number of losses the Person has incurred

public:
	/// @brief The default constructor for the Person class
	Person();

	/// @brief A constructor overload for the Person class
	/// @param inName The name specified for this Person
	/// @param playerNumber The unique specifier for this person
	Person(char*, int);

	/// @brief A constructor overload for the Person class
	/// @param inName The name specified for this Person
	/// @param inHand The Hand this Person is to start with
	Person(char*, Hand);

	/// @brief A constructor overload for the Person class
	/// @param inName The name specified for this Person
	/// @param inScore The score the Person is to start with; a handi-cap
	/// @param inWins The number of wins a Person is to start with; a handi-cap
	/// @param inLosses The number of wins a Person is to start with
	Person(char*, int, int, int);

	/// @brief A constructor overload for the Person class
	/// @param inName The name specified for this Person
	/// @param playerNumber The unique specifier for this person
	/// @param inHand The Hand this Person is to start with
	/// @param inWallet The amount of money a Person is to start with
	Person(char*, int, Hand, float);

	/// @brief A constructor overload for the Person class
	/// @param inName The name specified for this Person
	/// @param playerNumber The unique specifier for this person
	/// @param inHand The Hand this Person is to start with
	/// @param inWallet The amount of money a Person is to start with
	/// @param inScore The score the Person is to start with; a handi-cap
	/// @param inWins The number of wins a Person is to start with; a handi-cap
	/// @param inLosses The number of wins a Person is to start with
	Person(char*, int, Hand, float, int, int, int);

	/// @brief The default deconstructor for the Person class
    ~Person();

	/// @brief OVERLOAD Sets specific parameters for the Person class
	/// @param inName The name specified for this Person
	/// @param playerNumber The unique specifier for this person
	void Person::set_person(char*, int);

	/// @brief OVERLOAD Sets specific parameters for the Person class
	/// @param inName The name specified for this Person
	/// @param inHand The Hand this Person is to start with
	void Person::set_person(char*, Hand);

	/// @brief OVERLOAD Sets specific parameters for the Person class
	/// @param inName The name specified for this Person
	/// @param inScore The score the Person is to start with; a handi-cap
	/// @param inWins The number of wins a Person is to start with; a handi-cap
	/// @param inLosses The number of wins a Person is to start with
	void Person::set_person(char*, int, int, int);

	/// @brief OVERLOAD Sets specific parameters for the Person class
	/// @param inName The name specified for this Person
	/// @param playerNumber The unique specifier for this person
	/// @param inHand The Hand this Person is to start with
	/// @param inWallet The amount of money a Person is to start with
	void Person::set_person(char*, int, Hand, float);

	/// @brief OVERLOAD Sets all parameters for the Person class
	/// @param inName The name specified for this Person
	/// @param playerNumber The unique specifier for this person
	/// @param inHand The Hand this Person is to start with
	/// @param inWallet The amount of money a Person is to start with
	/// @param inScore The score the Person is to start with; a handi-cap
	/// @param inWins The number of wins a Person is to start with; a handi-cap
	/// @param inLosses The number of wins a Person is to start with
	void Person::set_person(char*, int, Hand, float, int, int, int);

	/// @brief Sets the name of the Person by checking if is within the allowed
	/// range.
	/// @param inName The name specified for this Person
	void Person::set_name(char*);

	/// @brief Sets the unique ID of the Person
	/// @param inNumber
	void Person::set_number(int);

	/// @brief Sets the Hand of Cards for the Person
	/// @param inHand The Hand of Cards
	void Person::set_playerHand(Hand);

	/// @brief Sets the wallet for the Person
	/// @param inWallet The amount of money a Person has to bet with
	void Person::set_wallet(float);

	/// @brief Sets the score for the Person
	/// @param inScore The score the Person that is updated periodically
	void Person::set_score(int);

	/// @brief Sets the number of wins for the Person
	/// @param inWins The number of wins for the Person, updated periodically
	void Person::set_wins(int);

	/// @brief Sets the number of losses for the Person
	/// @param inLosses The number of losses for the Person updated periodically
    void Person::set_losses(int);

	/// @brief Gets the name of the Person
	/// @return Returns a char pointer consisting of chars that make up a name
	char* Person::get_name();

	/// @brief Gets the unique ID of the Person
	/// @return Returns an integer that is the Persons unique ID
	int Person::get_number();
	
	/// @brief Gets the had of the Person; for debugging mainly
	/// @return Returns a Hand instance that belongs to the player
	Hand Person::get_playerHand();
	
	/// @brief Gets the amount of money a Person has
	/// @return Returns a float indicating how much money the Person has
	float Person::get_wallet();
	
	/// @brief Gets the score of the Person
	/// @return Returns an integer indicating how many points the Person has
	int Person::get_score();

	/// @breif Gets the number of wins of the Person
	/// @return Returns an integer indicating how many times the Person has won
	int Person::get_wins();

	/// @breif Gets the number of losses of the Person
	/// @return Returns an integer indicating how many times the Person has lost
    int Person::get_losses();

	/// @brief A greeting between two Persons
	/// @param opponent The name of the person to be greeted by this Person
	void Person::sayHello(char*);

	void Person::acceptCard(Card);

	Card Person::discardCard(int);

	/// @brief Places a bet on the game and removes that ammount from the wallet
	/// @param bet The amount the Person wants to bet on the round
	/// @return Returns a float indicating the amount of money bet by the Person
	float Person::placeBet(float);

	/// @brief Sets the Value for the Ace card a play may have
	/// @details The function will check (in the Card class) if the card is, in
	/// fact, an Ace. Then, it will check if the value entered is correct for an
	/// Ace card (i.e. a 1 or an 11) Then it will set the value of that Card.
	/// @param index The position of the card in the Hand
	/// @param val The value of the Ace the player wishes to make it.
	/// @see Refer to
	/// <a href="http://www.cplusplus.com/doc/tutorial/polymorphism/" target="_blank">
	/// Polymorphism</a> at cplusplus.com for more information.
	void Person::set_Ace(int, int);

	/// @brief Checks to see if there is actually an Ace in the Person's Hand
	/// @param index A integer pointer array (return by reference) of the
	/// position of the Ace or Aces in the Person's Hand
	/// @return The number of Aces in the Person's Hand is returned as an
	/// integer and the position indecies are returned by reference.
	/// @see Refer to
	/// <a href="http://www.cplusplus.com/doc/tutorial/polymorphism/" target="_blank">
	/// Polymorphism</a> at cplusplus.com for more information.
	int Person::has_Ace(int[]);

	/// @brief Calculates the score of the Person; happens when a card is drawn
	/// @return Returns an integer indicating how many points the Person has
	/// @see Refer to checkCardValue() in the Card class for more info.
    int Person::calculateScore();

	/// @brief Prints the person's Name, Hand, and stats
	void Person::printStats();

	void Person::printHand();

	/// @brief An overloaded = operator to set one Person equal to another
	/// @param inPerson A Person instance pointer set on the right side of the =
    void Person::operator=(const Person&);
};


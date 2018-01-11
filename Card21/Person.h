///
///
///
#pragma once
#include "Hand.h"

const int MAX_CHAR_CAP = 20;


///
///
///
class Person {
private:
    char* name;
    int number;
    Hand playerHand;
    float wallet;
    int score;
    int wins;
    int losses;

public:
	///
	///
	///
    Person();
    Person(char*, int);
    Person(char*, Hand);
    Person(char*, int, int, int);
    Person(char*, int, Hand, float);
    Person(char*, int, Hand, float, int, int, int);
    ~Person();

	///
	///
	///
    void Person::set_person(char*, int);
    void Person::set_person(char*, Hand);
    void Person::set_person(char*, int, int, int);
    void Person::set_person(char*, int, Hand, float);
	void Person::set_person(char*, int, Hand, float, int, int, int);
	///
	///
	///
	void Person::set_name(char*);
	///
	///
	///
	void Person::set_number(int);
	///
	///
	///
	void Person::set_playerHand(Hand);
	///
	///
	///
	void Person::set_wallet(float);
	/***/
	void Person::set_score(int);
	/***/
	void Person::set_wins(int);
	/***/
    void Person::set_losses(int);

	///
	///
	///
	char* Person::get_name();
	///
	///
	///
	int Person::get_number();
	///
	///
	///
	Hand Person::get_playerHand();
	///
	///
	///
	float Person::get_wallet();
	///
	///
	///
	int Person::get_score();
	///
	///
	///
	int Person::get_wins();
	///
	///
	///
    int Person::get_losses();

	///
	///
	///
	void Person::sayHello(char*);
	///
	///
	///
	float Person::placeBet(float);
	///
	///
	///
    int Person::calculateScore();

	///
	///
	///
    void Person::operator=(const Person&);
};


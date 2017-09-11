#include <iostream>

#include "Person.h"
#include "Card.h"

Person::Person()
{
	Card nullCard(NO_FACE, NO_SUIT);
	this->set_name("Player0");
	this->number = 0;
	this->playerHand.set_cards(nullCard);
	this->wallet = 20.0;
	this->score = 0;
	this->wins = 0;
	this->losses = 0;
	return;
}


Person::Person(char* inName, int playerNumber)
{
	this->set_person(inName, playerNumber);
	return;
}


Person::Person(char* inName, Hand inHand)
{
	this->set_person(inName, inHand);
	return;
}


Person::Person(char* inName, int inScore, int inWins, int inLosses)
{
	this->set_person(inName, inScore, inWins, inLosses);
	return;
}


Person::Person(char* inName, int inNumber, Hand inHand, float inWallet)
{

}


Person::Person(char* inName, int inNumber, 
	Hand inHand, float inWallet, int inScore, int inWins, int inLosses)
{
	this->set_person(inName, inNumber, inHand, 
		inWallet, inScore, inWins, inLosses);
	return;
}


Person::~Person()
{
	Card nullCard(NO_FACE, NO_SUIT);
	this->name = "";
	this->number = 0;
	this->playerHand.set_cards(nullCard);
	this->wallet = 0.0;
	this->score = 0;
	this->wins = 0;
	this->losses = 0;
	return;
}


void Person::set_person(char* inName, int playerNumber)
{
	Card nullCard(NO_FACE, NO_SUIT);
	this->set_name(inName);
	this->number = playerNumber;
	this->playerHand.set_cards(nullCard);
	this->wallet = 20.0;
	this->score = 0;
	this->wins = 0;
	this->losses = 0;
	return;
}


void Person::set_person(char* inName, Hand inHand)
{
	this->set_name(inName);
	this->number = 0;
	this->playerHand = inHand;
	this->wallet = 20.0;
	this->score = 0;
	this->wins = 0;
	this->losses = 0;
	return;
}


void Person::set_person(char* inName, int inScore, int inWins, int inLosses)
{
	Card nullCard(NO_FACE, NO_SUIT);
	this->set_name(inName);
	this->number = 0;
	this->playerHand.set_cards(nullCard);
	this->wallet = 20.0;
	this->score = inScore;
	this->wins = inWins;
	this->losses = inLosses;
	return;
}


void Person::set_person(char* inName, int inNumber, 
	Hand inHand, float inWallet, int inScore, int inWins, int inLosses)
{
	this->set_name(inName);
	this->number = inNumber;
	this->playerHand = inHand;
	this->wallet = inWallet;
	this->score = inScore;
	this->wins = inWins;
	this->losses = inLosses;
}


void Person::set_name(char* inName)
{
	if (sizeof(inName) <= MAX_CHAR_CAP) {
		this->name = inName;
	}
	else {
		for (int i = 0; i < MAX_CHAR_CAP - 1; i++) {
			this->name[i] = inName[i];
		}
		this->name[MAX_CHAR_CAP - 1] = '\0';
	}
	return;
}


void Person::set_number(int inNumber)
{
	this->number = inNumber;
	return;
}


void Person::set_playerHand(Hand inHand)
{
	this->playerHand = inHand;
	return;
}


void Person::set_wallet(float inWallet)
{
	this->wallet = inWallet;
	return;
}


void Person::set_score(int inScore)
{
	this->score = inScore;
	return;
}


void Person::set_wins(int)
{
	this->wins = wins;
	return;
}


void Person::set_losses(int)
{
	this->losses = losses;
	return;
}


char* Person::get_name()
{
	return this->name;
}


int Person::get_number()
{
	return this->number;
}


Hand Person::get_playerHand()
{
	return this->playerHand;
}


float Person::get_wallet()
{
	return this->wallet;
}


int Person::get_score()
{
	return this->score;
}


int Person::get_wins()
{
	return this->wins;
}


int Person::get_losses()
{
	return this->losses;
}


void Person::sayHello(char* opponent)
{
	printf("Hellow %s, I'm %s.", opponent, this->name);
	return;
}


float Person::placeBet(float bet)
{
	float maxBet = this->get_wallet();
	float result = 0.0;
	if (bet < maxBet && bet > 0) {
		printf("%s placing bet of $%d", this->get_name(), bet);
		this->set_wallet(maxBet - bet);
		return bet;
	}
	else if (bet < 0) {
		printf("%s placing min-bet of $%d", this->get_name(), 1);
		this->set_wallet(maxBet - 1);
		return maxBet;
	}
	else {
		printf("%s placing max-bet of $%d", this->get_name(), maxBet);
		this->set_wallet(0);
		return maxBet;
	}
}


int Person::calculateScore()
{
	Card nullCard(NO_FACE, NO_SUIT);
	Card currCard;
	int result = 0;
	for (int i = 0; i < MAX_CHAR_CAP; i++) {
		currCard = this->playerHand.get_card(i);
		if (currCard == nullCard) {
			continue;
		}
		else {
			result += currCard.get_value();
		}
	}
	this->score += result;
	return result;
}


void Person::operator=(const Person& inPerson)
{
	this->set_person(inPerson.name, inPerson.number, inPerson.playerHand, 
		inPerson.wallet, inPerson.score, inPerson.wins, inPerson.losses);
}
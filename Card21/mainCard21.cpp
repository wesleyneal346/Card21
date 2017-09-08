#pragma once
#include <iostream>

#include "math.h"

#include "Card.h"
using namespace std;

void main(int argc, char* argv[])
{
	char c;
	Card card1(12, 3);
	Card card2(4, 2);
	Card card3(1, 0);

	int result;
	result = card1.get_value() + card2.get_value() + card3.get_value();
	
	card1.printCard();
	cout << " + ";
	card2.printCard();
	cout << " + ";
	card3.printCard();
	cout << " = " << result << endl;
	cin >> c;
	return;
}
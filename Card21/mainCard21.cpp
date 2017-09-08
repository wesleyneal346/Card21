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

	Card result;
	result = card1 + card2 + card3;
	
	card1.printCard();
	cout << " + ";
	card2.printCard();
	cout << " + ";
	card3.printCard();
	cout << " = " << result.get_value() << endl;
	cin >> c;
	return;
}
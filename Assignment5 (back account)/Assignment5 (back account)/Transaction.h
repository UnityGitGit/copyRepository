#pragma once
#include <string>
#include <iostream>
using namespace std;

class Transaction {
public:
	Transaction(bool _isPositive, int _amount, string _date);
	bool getPositiveness() const;
	int getAmount() const;
	string getDate() const;

private:
	bool isPositive;
	int amount;
	string date;
};


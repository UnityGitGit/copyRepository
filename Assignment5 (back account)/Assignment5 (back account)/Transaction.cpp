#include "Transaction.h"

Transaction::Transaction(bool _isPositive, int _amount, string _date) {
	isPositive = _isPositive;
	amount = _amount;
	date = _date;
}

bool Transaction::getPositiveness() const{
	return isPositive;
}

int Transaction::getAmount() const{
	return amount;
}

string Transaction::getDate() const{
	return date;
}
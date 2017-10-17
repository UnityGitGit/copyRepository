#pragma once
#include "Transaction.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class BankAccount{
public:
	BankAccount();
	BankAccount(vector<Transaction> _transactions);
	BankAccount operator+(const Transaction& transaction) const;
	BankAccount operator-(const Transaction& transaction) const;
	int balance() const;

	vector<Transaction> transactions;//public needed for the << operator to output all the transaction info
	friend ostream& operator<<(ostream& os, const BankAccount& acc);

private:
	int transactionID(const Transaction* transaction) const;
};


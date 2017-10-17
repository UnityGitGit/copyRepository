#include "BankAccount.h"

BankAccount::BankAccount(){}
BankAccount::BankAccount(vector<Transaction> _transactions): transactions(_transactions) {}

BankAccount BankAccount::operator+(const Transaction& transaction) const{
	vector<Transaction> tempTransactions = transactions;
	tempTransactions.push_back(transaction);
	return BankAccount(tempTransactions);
}

BankAccount BankAccount::operator-(const Transaction& transaction) const {
	vector<Transaction> tempTransactions = transactions;
	int id = transactionID(&transaction);
	if (id != -1) {
		tempTransactions.erase(tempTransactions.begin());
	}
	return BankAccount(tempTransactions);
}

int BankAccount::balance() const {
	int cashAmount = 0;

	for (int i = 0; i < (int)transactions.size(); i ++) {
		if (transactions.at(i).getPositiveness() == true) {
			cashAmount += transactions.at(i).getAmount();
		}
		else {
			cashAmount -= transactions.at(i).getAmount();
		}
	}

	return cashAmount;
}

int BankAccount::transactionID(const Transaction* transaction) const {
	int transactionSize = (int)transactions.size();

	for (int i = 0; i < transactionSize; i ++) {
		if (transactions[i].getAmount() == transaction->getAmount()) {
			if (transactions[i].getDate() == transaction->getDate()) {
				if (transactions[i].getPositiveness() == transaction->getPositiveness()) {
					return i;
				}
			}
		}
	}

	//return invalid id:
	return -1;
}

ostream& operator<<(ostream& os, const BankAccount& acc)
{
	os << "# Bank account with saldo: " << acc.balance() << " #" << endl;
	for (int i = 0; i < (int)acc.transactions.size();  i++) {
		string date = acc.transactions.at(i).getDate() + ": ";
		int remainingSpaces = 12 - date.size();
		for (int r = 0; r < remainingSpaces; r++)date = date + " ";

		string positiveIndicator = (acc.transactions.at(i).getPositiveness()) ? "+" : "-";
		string transactionValue = positiveIndicator + to_string(acc.transactions.at(i).getAmount());

		os << date << transactionValue << endl;
	}

	return os;
}

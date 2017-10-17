#include "BankAccount.h"
#include "Transaction.h"

int main() {
	Transaction t1 = Transaction(true, 15, "15-2-2017");
	Transaction t2 = Transaction(true, 3, "19-2-2017");
	Transaction t3 = Transaction(false, 30, "2-3-2017");//dit is een opname van de bank

	BankAccount bankAccount = BankAccount();

	//definieer +/- operators en gebruik deze om transacties toe te schrijven aan bankAcc:
	bankAccount = bankAccount + t1;
	bankAccount = bankAccount + t2;
	bankAccount = bankAccount + t3;
	cout << bankAccount.balance() << endl;	
	bankAccount = bankAccount - t1;
	cout << bankAccount.balance() << endl;	

	//definieer outputstream insertion operator:
	cout << endl << bankAccount << endl;//print saldo & transaction history

	cin.get();

	return 0;
}
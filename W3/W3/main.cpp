#include <iostream>    
#include "customer.h"  
#include "account.h"

using namespace std;

int main()
{
	cout << "Creating a customer..." << endl;
	Customer customer_1(100, "John", "Smith");
	cout << "Customer ID: " << customer_1.get_id() << endl;
	cout << "Name: " << customer_1.get_name() << endl;
	cout << endl;

	cout << "Creating an account..." << endl;
	Account savings(12345, customer_1);
	cout << "Account Number: " << savings.get_account_num() << endl;
	cout << "Account Owner: " << savings.get_owner_name() << endl;
	cout << "Account Owner ID: " << savings.get_owner_id() << endl;
	cout << "Account balance: " << savings.get_balance() << endl;
	cout << endl;

	cout << "Creating an account with an opening balance..." << endl;
	Account checking(67890, customer_1, 500.25);
	cout << "Account Number: " << checking.get_account_num() << endl;
	cout << "Account balance: " << checking.get_balance() << endl;
	cout << "Depositing 25.00..." << endl;
	checking.deposit(25.00);
	cout << "New account balance: " << checking.get_balance() << endl;
	cout << "Withdrawing 25.00..." << endl;
	checking.withdraw(25.00);
	cout << "New account balance: " << checking.get_balance() << endl;

	cout << "Done" << endl;

	return 0;
}
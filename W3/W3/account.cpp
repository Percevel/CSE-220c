#include "account.h"
#include <string>
using namespace std;

Account::Account(int account_num, const Customer& owner) :
	account_number{ account_num }, owner{ owner }, balance{ 0 } {}

Account::Account(int account_num, const Customer& owner, double opening_balance) :
	account_number{ account_num }, owner{ owner }, balance{ opening_balance }
{
}

int Account::get_account_num() const
{
	return account_number;
}
double Account::get_balance() const
{
	return balance;
}
std::string Account::get_owner_name() const
{
	return owner.get_name();
}
int Account::get_owner_id() const
{
	return owner.get_id();
}
void Account::set_balance(double balance)
{
	this->balance = balance;
}
void Account::deposit(double amount)
{
	balance += amount;
}
void Account::withdraw(double amount)
{
	balance -= amount;
}

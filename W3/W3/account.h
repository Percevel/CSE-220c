#ifndef account_h
#define account_h

#include <string>
#include "customer.h"

using namespace std;

class Account {
private:
    int account_number;
    double balance;
    const Customer& owner;
public:
    Account(int account_number, const Customer& owner);
    Account(int account_number, const Customer& owner, double opening_balance);
    int get_account_num() const;
    double get_balance() const;
    string get_owner_name() const;
    int get_owner_id() const;
    void set_balance(double balance);
    void deposit(double amount);
    void withdraw(double amount);
};
#endif
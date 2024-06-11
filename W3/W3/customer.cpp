#include "customer.h"
#include <string>
using namespace std;

Customer::Customer(int id, string given_name, string family_name) :
	id{ id }, given_name{ given_name }, family_name{ family_name } {}

int Customer::get_id() const {
	return id;
}

string Customer::get_name() const {
	return given_name + " " + family_name;
}
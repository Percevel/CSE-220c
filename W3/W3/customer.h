#ifndef customer_h
#define customer_h
#include <string>

using namespace std;

class Customer {
private:
    string given_name;
    string family_name;
    int id;
public:
    Customer(int id, string given_name, string family_name);
    string get_name() const;
    int get_id() const;
};

#endif 
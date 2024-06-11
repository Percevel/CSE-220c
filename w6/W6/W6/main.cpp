#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include "checkList.h"
checkList c;

void prompt() {
	int ans;
	string input;
	c.displayList();
	cout << "what is your descision? \n 1) add item \n 2) remove item\n";
	cin >> ans;
	if (ans == 1) {
		cout << "what is the value you want to add?";
		cin >> input;
		c.addItem(input);
	}
	else if (ans == 2) {
		cout << "what is the position you want to remove?";
		cin >> ans;
		c.removeItem(ans);
	}
}

int main() {
	bool cont = true;
	int ans;
	c.readFile();
	while (cont == true) {
		prompt();
		cout << "want to continue? 1 for yes, 2 for no";
		cin >> ans;
		if (ans == 2) {
			cont = false;
		}
		else {
			cont = true;
		}
	}
}
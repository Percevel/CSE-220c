#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include "checkList.h"

vector<string> cList;
void checkList::writeFile() {
	string filstuff;
	fstream MyReadFile("checkList.txt");
	for (int i = 0; i < cList.size(); i++) {
		filstuff = filstuff + cList.at(i) + "\n";
	}
	filstuff = filstuff + "filler";
	MyReadFile << filstuff;
}

void checkList::readFile() {
	string myText;
	fstream MyReadFile("checkList.txt");
	while (getline(MyReadFile, myText)) {
		cList.push_back(myText);
	}
	cList.pop_back();
}

void checkList::removeItem(int arrayPlace) {
	cList.erase (cList.begin()+arrayPlace);
	writeFile();
}

void checkList::addItem(string value) {
	cList.push_back(value);
	writeFile();
}

void checkList::displayList() {
	fstream MyReadFile("checkList.txt");
	for (int i = 0; i < cList.size(); i++) {
		cout << cList.at(i) + "\n";
	}
}
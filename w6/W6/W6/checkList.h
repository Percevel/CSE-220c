#ifndef checkList_h
#define checkList_h
using namespace std;
#include <string>
#include <list>
#include <vector>

class checkList {
public:
	void writeFile();
	void readFile();
	void removeItem(int arrayPlace);
	void addItem(string value);
	void displayList();
};

#endif
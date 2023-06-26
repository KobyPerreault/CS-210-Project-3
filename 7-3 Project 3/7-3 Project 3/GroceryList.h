#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

class GroceryList {
	public:
		void PrintList(map<string, int> grList);
		void PrintHistogram(map<string, int> grList);
		void FindItem(map<string, int> grList);
	private:
		string itemToFind;
};

void GroceryList::PrintList(map<string, int> grList) {
	//Prints the map with the key followed by the value
	typedef map<string, int>::iterator iterator;
	for (iterator p = grList.begin(); p != grList.end(); p++)
		cout << p->first << ": " << p->second << endl;
}

void GroceryList::PrintHistogram(map<string, int> grList) {
	//Prints the key and a * to represent the frequency
	typedef map<string, int>::iterator iterator;
	for (iterator p = grList.begin(); p != grList.end(); p++) {
		//Prints the item name
		cout << p->first << ": ";
		//Based of the keys value it prints a *
		for (int i = 0; i < grList.at(p->first); i++) {
			cout << "*";
		}
		cout << endl;
	}
}

void GroceryList::FindItem(map<string, int> grList) {
	//Gets the specific item form the list
	cout << "Item to find: ";
	cin >> itemToFind;
	
	//Checks if the given item is in the map
	if (grList.count(itemToFind) == 0) {
		cout << "\nItem Not Found";
	}
	//If so it returns the item with its frequency
	else
	{
		cout << endl << itemToFind << ": " << grList.at(itemToFind);
	}
}




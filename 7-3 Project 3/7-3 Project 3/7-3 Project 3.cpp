#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "GroceryList.h"

using namespace std;

int main()
{
	ifstream inList;
	fstream dataFile("frequency.dat", ios::app);
	string tempWord;
	int choice = -1;
	map<string, int> wordCount;
	GroceryList myList;

	inList.open("CS210_Project_Three_Input_File.txt");

	while (!inList.eof())
	{
		//Gets the word from the open file
		inList >> tempWord;
		
		//checks to see if the word is in the map if not it adds it and set the value of that word to 1
		if (wordCount.count(tempWord) == 0) {
			wordCount.emplace(tempWord, 1);
		}
		//If it does exist already it incriments the value of that word by 1
		else if (wordCount.count(tempWord) == 1) {
			wordCount.at(tempWord)++;
		}
	}
	
	typedef map<string, int>::iterator iterator;
	for (iterator p = wordCount.begin(); p != wordCount.end(); p++)
		dataFile << p->first << ": " << p->second << endl;

	inList.close();
	dataFile.close();

	while (choice != 0) {
		//Prints menu for user
		cout << "=====================================================================" << endl;
		cout << "| 1. Find specific item frequency                                   |" << endl;
		cout << "| 2. Print the list with the frequency of all items purchased       |" << endl;
		cout << "| 3. Print item frequency histogram                                 |" << endl;
		cout << "| Enter 0 to quit                                                   |" << endl;
		cout << "=====================================================================" << endl;

		cin >> choice;
		
		//Calls the class method based on the chosen function
		switch (choice)
		{
		case 1:
			myList.FindItem(wordCount);
			break;
		case 2:
			myList.PrintList(wordCount);
			break;
		case 3:
			myList.PrintHistogram(wordCount);
			break;
		default:
			break;
		}
		cout << endl;
	}
	return 0;
}
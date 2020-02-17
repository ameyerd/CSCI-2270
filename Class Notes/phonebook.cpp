#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

//#define filename "testFile.txt"

// Define struct -> No data initialized!
struct PhoneContact {
	string name, nickName;
	int number;
	bool block;
} globalStruct1, globalStruct2; // won't use these!

int main(int argc, char* argv[]) {
	// Declare a local instance of PhoneContact
	PhoneContact localStruct;
	// Initialize struct data
	localStruct.name = "Christopher";
	localStruct.nickName = "Chris";
	localStruct.number = 42;
	localStruct.block = false;

	//cout << *localStruct << endl; // DOESN'T WORK!
	// '/*' and '*/' create a comment block!
	/*
	cout << localStruct.name << endl;
	cout << localStruct.nickName << endl;
	cout << localStruct.number << endl;
	cout << localStruct.block << endl;
	*/

	// Take in command line args
	string filename = "";
	if (argc < 2) {
		cout << "Not enough arguments!\n";
	} else if (argc > 2) {
		cout << "Too many arguments\n";
	} else {
		filename = argv[1];
	}

	ifstream fs; // input stream OBJECT
	fs.open(filename);


	// Keep loop relavent variables above loop for organization
	string line; // Internal program destination
	int numEntries = 0;
	PhoneContact phoneBook[5];
	string name; // also moved outside loop, read comment below:
	/* 
		Moved our first call to getline() to our while() condition:
		   - while(!fs.eof()) does not break until the last line has been read TWICE! The eof isn't set until we fail to read a line. This was why we segfaulted in lecture. The EOF flag is set to true when a line has been failed to be read, effectively requiring two checks of fs.eof() before we know the end has been reached.

		   - It is good practice to use the getline() to break your loop, that way you can rest assured that you read *while* you can, until you absolutely can't anymore. 
	*/
	while (getline(fs, name, ',')) {
		// Initialize line variables
		string nickName;
		string number;
		string block;

		// Populate all the line variables
		getline(fs, nickName, ',');
		getline(fs, number, ',');
		getline(fs, block);

		// Populate the struct at index "numEntries"
		phoneBook[numEntries].name = name;
		phoneBook[numEntries].nickName = nickName;
		phoneBook[numEntries].number = stoi(number);
		phoneBook[numEntries].block = stoi(block); // 
		//phoneBook[numEntries].block = (bool) stoi(block); // <--- more explicit about what's going on, using type casting

		numEntries++;
	}

	// Test that we filled these in correctly
	for (int i=0; i<numEntries; i++) {
		cout << phoneBook[i].name << endl;
		cout << phoneBook[i].nickName << endl;
		cout << phoneBook[i].number << endl;
		cout << phoneBook[i].block << endl;
		cout << endl;
	}

	return 0;
}

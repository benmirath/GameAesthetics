#include <iostream>
#include <fstream>
using namespace std;

int main() {
	//ofstream is for OUTPUT
	//ifstream is for INPUT

	ifstream theFile("players.txt");

	int id;
	string name;
	int level;

	int arr[10];
	int counter = 0;

	//every file has an "end of file marker", returning a null pointer and breaking the loop
	// while(theFile >> id >> name >> level) {
	while (theFile >> arr[counter]) {
		// cout << id << ", " << name << ", " << level << endl;
		cout << arr[counter] << "\n";
		counter++;
		
	}

	//close file method automatically called by ifstream deconstructor

	return 0;
}
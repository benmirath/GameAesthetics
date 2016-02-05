#include <iostream>
#include <string>
using namespace std;

class Room {
public:
	Room ();
	Room (string _desc, bool _north, bool _east, bool _south, bool _west);
	string description;
	char representation;
	bool canGoNorth;
	bool canGoSouth;
	bool canGoEast;
	bool canGoWest;
};

Room::Room () {
	description = "A room";
	canGoNorth = false;
	canGoSouth = false;
	canGoEast = false;
	canGoWest = false;
}
Room::Room (string _desc, bool _north, bool _east, bool _south, bool _west):
	description(_desc),
	canGoNorth (_north),
	canGoSouth (_south),
	canGoWest (_west),
	canGoEast (_east)
{}

class AI {
public:
	AI (int _x, int _y);
	int x;
	int y;
	string lastDir;
};

int main () {
	//global variables
	//a string to store player input
	string userInput;
	//2 variables for user position
	int userX = 0;
	int userY = 0;
	//2D array to store our map
	const int WIDTH = 4;
	const int HEIGHT = 4;
	// string map[HEIGHT][WIDTH];
	Room map [WIDTH][HEIGHT];

	// for (int i = 0; i < WIDTH; i++) {
	// 	for (int j = 0; j < HEIGHT; j++) {
	// 		// map[i][j].description = "There's nothing here!";
	// 		// map[i][j].canGoNorth = false;
	// 		// map[i][j].canGoSouth = false;
	// 		// map[i][j].canGoEast = false;
	// 		// map[i][j].canGoWest = false;
	// 		// map[]

	// 	}
	// }

	// map[0][1].description = "Here lies a chocolate chip cookie.";
	// map[2][0].description = "You crane your neck skyward to see the grand Empire State Building up among the clouds! You feel dizzy.";
	// map[userX][userY].description = "There's a path going east and west";
	// map[userX][userY].canGoWest = true;
	// map[userX][userY].canGoEast = true;

	//create rudimentary AI that moves the space
	//north - east - south - west
	map[0][0] = Room ("A barren room. A path leads South.", false, false, true, false);
	map[1][0] = Room ("You win!.", false, true, false, false);
	map[2][0] = Room ("An ominous hallway with doors to the West and East.", false, true, false, true);
	map[3][0] = Room ("You're getting close! Let's get .", false, false, true, true);
	
	map[0][1] = Room ("A damp hallway with doors to the North and South.", true, false, true, false);
	map[1][1] = Room ("Room 6.", false, false, true, false);
	map[2][1] = Room ("Room 7.", false, false, false, false);
	map[3][1] = Room ("Room 8.", true, false, true, false);
	
	map[0][2] = Room ("A creepy torture chamber, with paths leading to the North, South and East", true, true, true, false);
	map[1][2] = Room ("Room 10.", true, false, false, true);
	map[2][2] = Room ("A decidely unsexy room, with standard entrances to the East and South. Meh.", false, true, true, false);
	map[3][2] = Room ("Room 12.", true, false, false, true);
	
	map[0][3] = Room ("A corner office, you made it! Wait corner room, sorry. There are entrances to the North and East", true, true, false, false);
	map[1][3] = Room ("A sexy hallway, leading sexily to the West and East", false, true, false, true);
	map[2][3] = Room ("A sexy room, with entrances sexily leading West and North", true, false, false, true);
	map[3][3] = Room ("Room 16.", false, false, false, false);


	//game loop will be a 'while' loop
		//check for exit condition in 'while' loop
	while (userInput != "q") {	//<-- string for playerInput
		// map[userX][userY] = 'o';
		//based on what input? NORTH WEST EAST SOUTH
		cout << "Which direction?" << endl;
		cin >> userInput;	//go north --> input == gof

		if (userInput == "NORTH") {
			// if (userY > 0) {	//can move
			if (map[userX][userY].canGoNorth) {
				userY--;
			} else {
				cout << "A wall blocks your way to the north" << "\n\n";
			}
		}  else if (userInput == "SOUTH") {
			// if (userY < HEIGHT) {	//can move
			if (map[userX][userY].canGoSouth) {
				userY++;
			} else {
				cout << "A wall blocks your way to the south" << "\n\n";
			}
		} else if (userInput == "WEST") {
			// if (userX > 0) {	//can move
			if (map[userX][userY].canGoWest) {
				userX--;
			} else {
				cout << "A wall blocks your way to the west" << "\n\n";
			}
		} else if (userInput == "EAST") {
			// if (userX < WIDTH) {	//can move
			if (map[userX][userY].canGoEast) {
				userX++;
			} else {
				cout << "A wall blocks your way to the east" << "\n\n";
			}
		} else {
			cout << "I don't understand " << userInput << "\n";
		}


		cout << "You are in room X: " << userX << " Y: " << userY << endl;
		cout << map[userX][userY].description << endl;
		//move the players position on the map

		// for (int i = 0; i < WIDTH; i++) {
		// 	for (int j = 0; j < HEIGHT; j++) {
		// 		if (map[j][i] != 'o') {
		// 			map[j][i] = '_';	
		// 		}
				
		// 	}
		// }
		// map[userX][userY] = 'X';

		// for (int i = 0; i < WIDTH; i++) {
		// 	for (int j = 0; j < HEIGHT; j++) {
		// 		cout << map[j][i] << "|";
		// 	}
		// 	cout << endl;
		// }



		//set grid
		
	}

	return 0;
}
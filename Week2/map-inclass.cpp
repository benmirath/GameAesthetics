#include <iostream>
#include <string>
#include <vector>
using namespace std;

//2D array to store our map
const int WIDTH = 4;
const int HEIGHT = 4;

class Room {
public:
	Room ();
	Room (string _desc, bool _north, bool _east, bool _south, bool _west);
	string description;
	char occupant;
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

string NextRoute (Room curRoom) {
	vector<string> roomOptions;
	if (curRoom.canGoNorth) {
		roomOptions.push_back ("NORTH");
	} 
	if (curRoom.canGoSouth) {
		roomOptions.push_back ("SOUTH");
	} 
	if (curRoom.canGoEast) {
		roomOptions.push_back ("EAST");
	} 
	if (curRoom.canGoWest) {
		roomOptions.push_back ("WEST");
	} 
	
	if (roomOptions.size () > 0) {
		int index = rand() % roomOptions.size();
		return roomOptions[index];	
	} else {
		return "NA";
	}
	
}


void DrawUI (Room map[][HEIGHT], int userX, int userY, int aiX, int aiY, int treasureX, int treasureY) {
	cout << "------------------------------------------------" << endl;
	// cout << "You are in room X: " << userX << " Y: " << userY << endl;
	cout << map[userX][userY].description << endl;
	//move the players position on the map

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			map[j][i].occupant = '_';
		}
	}
	map[userX][userY].occupant = 'X';
	map[aiX][aiY].occupant = 'M';
	map[treasureX][treasureY].occupant = '$';
	

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			cout << map[j][i].occupant << "|";
		}
		cout << endl;
	}
}


int main () {
	//global variables
	//a string to store player input
	string userInput;
	//2 variables for user position
	int userX = 0;
	int userY = 0;
	int userTreasure = 0;
	
	int aiX = 2;
	int aiY = 3;
	
	int treasureX = 1;
	int treasureY = 1;

	int exitX = 3;
	int exitY = 3;


	// AI ai = AI (2, 3);
	Room map [WIDTH][HEIGHT];	
	//create rudimentary AI that moves the space
	//north - east - south - west
	map[0][0] = Room ("A barren room. A path leads South.", false, false, true, false);
	map[1][0] = Room ("You win!.", false, true, false, false);
	map[2][0] = Room ("An ominous hallway with doors to the West and East.", false, true, false, true);
	map[3][0] = Room ("The sound of faint chimes drifts from the West. Paths lead off to the South and West.", false, false, true, true);
	
	map[0][1] = Room ("A damp hallway with doors to the North and South.", true, false, true, false);
	map[1][1] = Room ("The room is barren, containing only broken pottery fragments. A door leads back South.", false, false, true, false);
	map[2][1] = Room ("CHEATER.", false, false, false, false);
	map[3][1] = Room ("A welcoming and familiar scent drifts through the tiled hall. Paths lead off to the North and South.", true, false, true, false);
	
	map[0][2] = Room ("A creepy torture chamber, with paths leading to the North, South and East", true, true, true, false);
	map[1][2] = Room ("Mist hangs thick in the room, though you can just make out a path to the North and West.", true, false, false, true);
	map[2][2] = Room ("A decidely unsexy room, with standard entrances to the East and South. Meh.", false, true, true, false);
	map[3][2] = Room ("A light dances enticingly in the center of the room, though doesn't respond to you. Doors sit to the North and West.", true, false, false, true);
	
	map[0][3] = Room ("A corner office, you made it! Wait corner room, sorry. There are entrances to the North and East", true, true, false, false);
	map[1][3] = Room ("A sexy hallway, leading sexily to the West and East", false, true, false, true);
	map[2][3] = Room ("A sexy room, with entrances sexily leading West and North", true, false, false, true);
	map[3][3] = Room ("CHEATER.", false, false, false, false);

	DrawUI (map, userX, userY, aiX, aiY, treasureX, treasureY);

	bool alive = true;
	bool treasureFound = false;
	while (userInput != "q" && alive && !treasureFound) {	//<-- string for playerInput
		//based on what input? NORTH WEST EAST SOUTH
		cout << "Which direction?" << endl;
		cin >> userInput;	//go north --> input == gof
		if (userInput == "q") break;

		bool calculateAI = true;

		if (userInput == "NORTH") {
			if (map[userX][userY].canGoNorth) {	//can move
				userY--;
			} else {
				cout << "A wall blocks your way to the north" << "\n\n";
			}
		}  else if (userInput == "SOUTH") {
			if (map[userX][userY].canGoSouth) {	//can move
				userY++;
			} else {
				cout << "A wall blocks your way to the south" << "\n\n";
			}
		} else if (userInput == "WEST") {
			if (map[userX][userY].canGoWest) {	//can move
				userX--;
			} else {
				cout << "A wall blocks your way to the west" << "\n\n";
			}
		} else if (userInput == "EAST") {
			if (map[userX][userY].canGoEast) {	//can move
				userX++;
			} else {
				cout << "A wall blocks your way to the east" << "\n\n";
			}
		} else if (userInput == "WAIT") {

		} else {
			calculateAI = false;	//not a valid move, so don't move enemy
			cout << "I don't understand " << userInput << "\n";
		}

		if (calculateAI) {
			string aiInput = NextRoute (map[aiX][aiY]);
			if (aiInput == "NORTH") {
				aiY--;	
			} else if (aiInput == "SOUTH") {
				aiY++;
			} else if (aiInput == "WEST") {
				aiX--;
			} else if (aiInput == "EAST") {
				aiX++;
			}	
		}
		
		if (userX == treasureX && userY == treasureY) {
			cout << "You've found the treasure! A rich future awaits" << endl;
			treasureFound = true;
		} else if (userX == aiX && userY == aiY)	{
			cout << "You've been eaten. How Grue-some" << endl;
			alive = false;
		} else {
			DrawUI (map, userX, userY, aiX, aiY, treasureX, treasureY);	
		}

		
	}

	return 0;
}
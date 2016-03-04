#pragma once

#include "ofMain.h"


class mapTile {
public:
	bool isGround;
	bool hasTreasure;
	bool hasPlayer;
	
	mapTile () {
		isGround = false;
		hasTreasure = false;
		hasPlayer = false;
	}
	//	int occupant;
};

const int COLS = 100;
const int ROWS = 100;
class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
//	bool[][] grid;
	
	float cellSize;
	mapTile cellmap[COLS][ROWS];
	
	int playerX;
	int playerY;
	bool playerAlive;
	
	vector<ofPoint> treasures;
//	bool treasure[COLS][ROWS];
	
	int countAliveNeighbors(mapTile map[][ROWS] , int x, int y);
	void reset ();
	void generateMap();
	void initializeRandWorld ();
	void drawWorld ();
	void queueFloodFill(int x, int y);
	void floodFill(int x, int y);
	void placeTreasure ();
	void placePlayer ();

	
	void handleInput (int x, int y);
	bool movePlayer (int x, int y);
//	int arraySize (bool array[]);
};

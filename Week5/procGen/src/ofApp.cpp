#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	

	cellSize = ofGetWidth() / COLS;
//	size(500, 500);
//	noStroke();
	ofFill();
	playerAlive = true;
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
			cellmap[i][j].isGround = false;
			cellmap[i][j].hasTreasure = false;
			cellmap[i][j].hasPlayer = false;
		}
	}
//	cellSize = width/COLS;
	initializeRandWorld();
	
	

	generateMap();
	placeTreasure();
	placePlayer();
	
	//get seed
	//create tile grid
	//based on seed
	//0 = open
	//1 = ground
	//2 = treasure
	//3 = player

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	drawWorld();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//	cellmap = new boolean[COLS][ROWS];

//	treasure = new boolean[COLS][ROWS];
	
	
	if (key == OF_KEY_RETURN || !playerAlive) {
		reset ();
	}
	
	if (key == OF_KEY_RIGHT) {
		handleInput(1, 0);
	} else if (key == OF_KEY_LEFT) {
		handleInput(-1, 0);
	} else if (key == OF_KEY_UP) {
		handleInput(0, -1);
	} else if (key == OF_KEY_DOWN) {
		handleInput(0, 1);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::reset () {
	playerAlive = true;
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
			cellmap[i][j].isGround = false;
			cellmap[i][j].hasTreasure = false;
			cellmap[i][j].hasPlayer = false;
		}
	}
	initializeRandWorld();
	generateMap();
	placeTreasure();
	placePlayer();

}

void ofApp::generateMap() {
	int numberOfSteps = 5;
	for (int i = 0; i < numberOfSteps; i++) {
		int deathLimit = 3;
		int birthLimit = 4;
		for (int x = 0; x < COLS; x++) {
			for (int y = 0; y < ROWS; y++) {
				int nbs = countAliveNeighbors(cellmap, x, y);
				if (cellmap[x][y].isGround) {
					if (nbs < deathLimit) {
						cellmap[x][y].isGround = false;
					} else {
						cellmap[x][y].isGround = true;
					}
			  //otherwise if cell is dead, check if it has the right number of neighbors to be born
				} else {
					if (nbs > birthLimit) {
						cellmap[x][y].isGround = true;
					} else {
						cellmap[x][y].isGround = false;
					}
				}
				
			}
		}
	}
	
}

int ofApp::countAliveNeighbors(mapTile map[][ROWS] , int x, int y) {
	int count = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			int neighborX = x+i;
			int neighborY = y+j;
			if (!(i == 0 && j == 0)) {
				if (neighborX < 0 || neighborY < 0 || neighborX >= COLS || neighborY >= ROWS) {
					count = count + 1;
				} else if (map[neighborX][neighborY].isGround) {
					count = count + 1;
				}
			}
		}
	}
	return count;
}

void ofApp::initializeRandWorld() {
	float aliveChance = 0.45;
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (ofRandom(1) < aliveChance) {
				cellmap[i][j].isGround = true;
			}
		}
	}
}

void ofApp::drawWorld() {
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
			
			if (i == playerX && j == playerY) {
				ofSetColor(0, 200, 0);
			} else if (cellmap[i][j].isGround == true) {
				//cell occupied (brown)
				ofSetColor(67, 56, 45);
			} else if (cellmap[i][j].hasTreasure == true) {
				if (playerAlive)
					ofSetColor(200, 200, 0);
				else
					ofSetColor(200, 0, 0);
			} else {
				//cell open (blue)
				ofSetColor(51, 98, 175);
			}
			ofRect(i * cellSize, j * cellSize, (i * cellSize) + cellSize, (j * cellSize) + cellSize);
		}
	}
}

void ofApp::queueFloodFill(int x, int y) {
	if (x < 0
		|| y < 0
		|| x >= COLS
		|| y >= ROWS) {
		return;
	}
	if (cellmap[x][y].isGround) {
		return;
	}
	vector<ofVec2f> queue = vector<ofVec2f> ();
	queue.push_back(ofVec2f(x,y));
	while (queue.size() > 0) {
		ofVec2f p = queue.front();
		queue.erase(queue.begin());
		if (p.x < 0
			|| p.y < 0
			|| p.x >= COLS
			|| p.y >= ROWS) {
			continue;
		}
		if (cellmap[(int)p.x][(int)p.y].isGround == false) {
			cellmap[(int)p.x][(int)p.y].isGround = true;
			ofSetColor(255, 255, 255);
			ofEllipse(p.x * cellSize, p.y * cellSize, cellSize, cellSize);
			queue.push_back(ofVec2f(p.x-1, p.y));
			queue.push_back(ofVec2f(p.x+1, p.y));
			queue.push_back(ofVec2f(p.x, p.y-1));
			queue.push_back(ofVec2f(p.x, p.y+1));
		}
	}
}

void ofApp::floodFill(int x, int y) {
	if (x < 0 || y < 0 || x >= COLS || y >= ROWS) {
		return;
	}
	if (cellmap[x][y].isGround) {
		return;
	}
	
	cellmap[x][y].isGround = true;
	ofSetColor(255, 255, 255);
	ofEllipse(x*cellSize, y*cellSize, cellSize, cellSize);
	
	floodFill(x+1, y);
	floodFill(x, y+1);
	floodFill(x-1, y);
	floodFill(x, y-1);
}

void ofApp::placeTreasure() {
	int hiddenLimit = 5;
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (!cellmap[i][j].isGround) {
				int nbs = countAliveNeighbors(cellmap, i, j);
				if (nbs >= hiddenLimit) {
					treasures.push_back(ofPoint (i,j));
					cellmap[i][j].hasTreasure = true;
				}
			}
		}
	}
}

void ofApp::placePlayer() {
	bool playerPlaced = false;
	while (!playerPlaced) {
		for (int i = 0; i < COLS; i++) {
			for (int j = 0; j < ROWS; j++) {
				if (!cellmap[i][j].isGround && !cellmap[i][j].hasTreasure) {
					playerX = i;
					playerY = j;
					cellmap[i][j].hasPlayer = true;
					playerPlaced = true;
					return;
				}
			}
		}
	}
}

bool ofApp::movePlayer (int x, int y) {
	if (x == 1 && playerX < COLS) {
		playerX++;
		return true;
	} else if (x == -1 && playerX > 0) {
		playerX--;
		return true;
	} else if (y == 1 && playerY < ROWS) {
		playerY++;
		return true;
	} else if (y == -1 && playerY > 0) {
		playerY--;
		return true;
	} else {
		return false;
	}

}
void ofApp::handleInput (int x, int y) {
	if (movePlayer (x, y)) {
		if (cellmap[playerX][playerY].isGround) {
			cellmap[playerX][playerY].isGround = false;
		} else {
			int newX = playerX + x;
			int newY = playerY + y;
			
			if (newX > 0 && newX < COLS && newY > 0 && newY < ROWS && cellmap[newX][newY].isGround) {
				movePlayer (x, y);
			}
		}
	}
	
	vector<ofPoint> newPoints;
	for (int i = 0; i < treasures.size(); i++) {
		
		
		ofPoint point = treasures[i];
		if (point.x + 1 < COLS) {
			if (!cellmap[int (point.x + 1)][int (point.y)].isGround
				&& !cellmap[int (point.x + 1)][int (point.y)].hasTreasure)
			{
				cellmap[int (point.x + 1)][int (point.y)].hasTreasure = true;
				newPoints.push_back(ofPoint(point.x + 1, point.y));
			}
		}
		if (point.x - 1 > 0) {
			if (!cellmap[int (point.x - 1)][int (point.y)].isGround
				&& !cellmap[int (point.x - 1)][int (point.y)].hasTreasure)
			{
				cellmap[int (point.x - 1)][int (point.y)].hasTreasure = true;
				newPoints.push_back(ofPoint(point.x - 1, point.y));
			}
		}
		if (point.y + 1 < ROWS) {
			if (!cellmap[int (point.x)][int (point.y + 1)].isGround
				&& !cellmap[int (point.x)][int (point.y + 1)].hasTreasure)
			{
				cellmap[int (point.x)][int (point.y + 1)].hasTreasure = true;
				newPoints.push_back(ofPoint(point.x, point.y + 1));
			}
		}
		if (point.y - 1 > 0) {
			if (!cellmap[int (point.x)][int (point.y - 1)].isGround
				&& !cellmap[int (point.x)][int (point.y - 1)].hasTreasure)
			{
				cellmap[int (point.x)][int (point.y - 1)].hasTreasure = true;
				newPoints.push_back(ofPoint(point.x, point.y - 1));
			}
		}
	}
	
	for (int i = 0; i < newPoints.size(); i++) {
		treasures.push_back(newPoints[i]);
	}
}










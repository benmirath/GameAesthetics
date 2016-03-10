#include "ofApp.h"

// comparison routine for sort - this would be used for elements on top of the background to ensure elements at the bottom of the screen are drawn in front of objects higher up on the screen. see the ofx addon example code.
bool sortVertically(basicSprite * a, basicSprite * b ) {
	return a->pos.y > b->pos.y;
}

// this method will be used to get the index of the sprite the player is standing on, or to check for possible collisions with "solid" tiles.
int ofApp::getTileName(int x, int y) {
	return backgrounds[y * GRIDW + x]->tileName;
}
basicSprite* ofApp::getTile(int x, int y) {
	return backgrounds[y * GRIDW + x];
}


//--------------------------------------------------------------
void ofApp::setup(){
	//set a limited frame rate, enable alpha blending, and set no anti-aliasing for more pixel arty kind of vibe.
	ofSetFrameRate(30);
	ofEnableAlphaBlending();
	ofDisableAntiAliasing();
	
	//create the sprite renderer with 2 layers, and 16x16 tiles.
	spriteRenderer = new ofxSpriteSheetRenderer(2, 10000, 0, 16);
	
	//load in the 64x64 pixels texture.
	spriteRenderer->loadTexture("link.png", 64, GL_NEAREST);
	
	wallBreaktimer = 0;
	wallBreaktimerDuration = 30; //30 frames
	
	//create "player" as an instance of our basicSprite struct, then set his position, speed, and default animation.
	player = new basicSprite();
	
	initializeRandomWorld ();
	paintMap();
	
	vector<ofPoint> placementOptions;
	for (int y = 0; y < GRIDH; y++) {
		for (int x = 0; x < GRIDW; x++) {
			basicSprite* sprite = getTile (x,y);
			if (!sprite->isWall) {
				placementOptions.push_back(sprite->pos);
			}
		}
	}
	player->pos.set(placementOptions[ofRandom(0, placementOptions.size())]);
	player->speed = 0.1;
	player->animation = walkAnimation;
	
	//override the walkAnimation's default index to have Link starting facing down.
	player->animation.index = 6;

	
}



//--------------------------------------------------------------
void ofApp::update(){
	//clear and update the renderer
	spriteRenderer->clear();
	spriteRenderer->update(ofGetElapsedTimeMillis());
	
	//add the Link sprite to the renderer.
	spriteRenderer->addCenteredTile(&player->animation, player->pos.x - cameraCenter.x, player->pos.y - cameraCenter.y, 1, F_NONE, SCALE);
	
	//if there are backgrounds, loop through it and add each one to the renderer.
	if (backgrounds.size() > 0) {
		for (int i = backgrounds.size()-1; i>=0; i--) {
			//this line isn't necessary and in fact is imperfect, but uncomment to see how we might limit drawing to only the current screen area.
			//if (backgrounds[i]->pos.x > 0 && backgrounds[i]->pos.x < ofGetWindowWidth() && backgrounds[i]->pos.y > 0 && backgrounds[i]->pos.y < ofGetWindowHeight()) {
			spriteRenderer->addCenteredTile(backgrounds[i]->tileName, 0, backgrounds[i]->pos.x, backgrounds[i]->pos.y, 0, 1, 1, F_NONE, SCALE);
			//}
		}
	}
	
	//update the background position based on the grid and the camera position.
	for (int i = 0; i < GRIDH; i++) {
		for (int j = 0; j < GRIDW; j++) {
			backgrounds[i * GRIDW + j]->pos.set(j*spriteRenderer->getTileSize()*SCALE - cameraCenter.x, i*spriteRenderer->getTileSize()*SCALE - cameraCenter.y);
		}
	}
	
	//update the player's position and animation index based on key presses.
	int runModifier = runPressed ? 2 : 1;
	
	ofPoint newPos = player->pos;
	
	if (leftPressed) {
		newPos.x -= player->speed * runModifier * spriteRenderer->getTileSize()*SCALE;
		player->animation.index = 4;
	}
	if (rightPressed) {
		newPos.x += player->speed * runModifier * spriteRenderer->getTileSize()*SCALE;
		player->animation.index = 2;
	}
	if (upPressed) {
		newPos.y -= player->speed * runModifier * spriteRenderer->getTileSize()*SCALE;
		player->animation.index = 0;
	}
	if (downPressed) {
		newPos.y += player->speed * runModifier * spriteRenderer->getTileSize()*SCALE;
		player->animation.index = 6;
	}
	
	//if no keys are being pressed, stop animating.
	//if keys are being pressed, animate Link's sprite.
	if (!leftPressed && !rightPressed && !upPressed && !downPressed) {
		player->animation.loops = 0;
	} else {
		player->animation.loops = -1;
		
		//this is an application of how we could check the player's position against the tiles.
		//we could use this approach to do collision detection for example.
		
		float xAdj = player->pos.x > newPos.x
			? (spriteRenderer->getTileSize() * SCALE) / 2
			: (spriteRenderer->getTileSize() * SCALE) / 2;
		float yAdj = player->pos.y > newPos.y
			? (spriteRenderer->getTileSize() * SCALE) / 2
			: (spriteRenderer->getTileSize() * SCALE) / 2;

		int tilePosX = floor((newPos.x + (spriteRenderer->getTileSize() * SCALE) / 2) / (spriteRenderer->getTileSize() * SCALE));
		int tilePosY = floor((newPos.y + (spriteRenderer->getTileSize() * SCALE) / 2) / (spriteRenderer->getTileSize() * SCALE));

		
		
		basicSprite* tile = getTile(tilePosX, tilePosY);
		if (tile != NULL) {
			if (!tile->isWall) {
				player->pos = newPos;
				wallBreaktimer = 0;
			} else {
				wallBreaktimer++;
				if (wallBreaktimer > wallBreaktimerDuration) {
					wallBreaktimer = 0;
					tile->isWall = false;
					tile->tileName = (int)ofRandom(8,11);
				}
			}
		} else {
			player->pos = newPos;
			wallBreaktimer = 0;
		}
		
		
		cout << "pos.x relative to tiles: " <<  tilePosX << ", pos.y relative to tiles: " <<  tilePosY << endl;
		
		cout << "background sprite index: " << getTileName(tilePosX, tilePosY) << endl;
	}
	
	//update the camera position to focus on the player's position.
	cameraCenter.x = player->pos.x - ofGetWindowWidth()/2;
	cameraCenter.y = player->pos.y - ofGetWindowHeight()/2;
}

//--------------------------------------------------------------
void ofApp::draw(){
	spriteRenderer->draw();
}

//in keyPressed and keyReleased, we just check for the directional keys and then turn on or off our corresponding booleans.

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_LEFT) {
		leftPressed = true;
	}
	if (key == OF_KEY_RIGHT) {
		rightPressed = true;
	}
	if (key == OF_KEY_UP) {
		upPressed = true;
	}
	if (key == OF_KEY_DOWN) {
		downPressed = true;
	}
	if (key == OF_KEY_SHIFT) {
		runPressed = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_LEFT) {
		leftPressed = false;
	}
	if (key == OF_KEY_RIGHT) {
		rightPressed = false;
	}
	if (key == OF_KEY_UP) {
		upPressed = false;
	}
	if (key == OF_KEY_DOWN) {
		downPressed = false;
	}
	if (key == OF_KEY_SHIFT) {
		runPressed = false;
	}
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
void ofApp::mouseEntered(int x, int y){
	
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	
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
void ofApp::generateMap() {
	int numberOfSteps = 2;
	for (int i = 0; i < numberOfSteps; i++) {
		int deathLimit = 3;
		int birthLimit = 4;
		for (int y = 0; y < GRIDH; y++) {
			for (int x = 0; x < GRIDW; x++) {

				int nbs = countAliveNeighbors(backgrounds, x, y);
				basicSprite* tile = getTile (x, y);
				
				if (tile->isWall) {
					if (nbs < deathLimit) {
						tile->isWall = false;
					}
			  //otherwise if cell is dead, check if it has the right number of neighbors to be born
				} else {
					if (nbs > birthLimit) {
						tile->isWall = true;
					}
				}
			}
		}
	}
}
void ofApp::paintMap () {
	for (int i = 0; i < backgrounds.size(); i++) {
		basicSprite* sprite = backgrounds[i];
		if (sprite->isWall) {
			sprite->tileName = 11;
		} else {
			sprite->tileName = (int)ofRandom(8,11);
		}
	}
}

void ofApp::initializeRandomWorld() {
	float aliveChance = 0.45;
	for (int i = 0; i < GRIDH; i++) {
		for (int j = 0; j < GRIDW; j++) {
			basicSprite * newSprite = new basicSprite();
			newSprite->pos.set(j*spriteRenderer->getTileSize()*SCALE, i*spriteRenderer->getTileSize()*SCALE);
			if (ofRandom(1) < aliveChance) {
				newSprite->isWall = true;
			}
			backgrounds.push_back(newSprite);
		}
	}
	generateMap ();
}

int ofApp::countAliveNeighbors(vector<basicSprite *> _backgrounds, int x, int y) {
	int count = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			int neighborX = x+i;
			int neighborY = y+j;
			if (!(i == 0 && j == 0)) {
				if (neighborX < 0 || neighborY < 0 || neighborX >= GRIDW || neighborY >= GRIDH) {
					count = count + 1;
				} else if (getTile (neighborX, neighborY)->isWall) {
					count = count + 1;
				}
			}
		}
	}
	return count;
}

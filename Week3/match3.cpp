#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int w = 8;
const int h = 8;

class point {
public:
	point (int _x, int _y);
	int x;
	int y;

};
class pointPair {
public:
	pointPair (point _p1, point _p2);
	point p1;
	point p2;
};

char getTile(int x, int y, unsigned char data[], int size, int w, int h);
int writeBytes(int offset, unsigned char data[]);
// vector<point> getMatches (point p1, point p2, char grid[][h]);
vector<point> getMatches (point p1, char grid[][h], vector<point> prevPoints);
void clearMatches (point p, char (&grid)[w][h]);
bool validTile (point p, int x, int y, char grid[][h]); 
bool contains (vector<point> points, point val);
// void clearMatches (point p, char *grid[][h]);



int main() {

	ifstream map("8x8flipped.bmp"); //NEED TO FLIP ROW ORDER IN PS! otherwise counts from bottom
	
	const int BMPSIZE = 248;	//actual size in bytes of the bmp file
	unsigned char bmpBytes[BMPSIZE];	//array of 8-bit integers to store our bytes
	unsigned char data;	//variable to store temporary bytes
	
	int whichByte = 0;
	while (map >> data) {		
		//as long as the file has bytes, plug it into the array
		bmpBytes[whichByte] = data;
		whichByte++;
	}

	map.close();


	char grid[h][w];

	//load tiles
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			grid[j][i] = getTile(j,i,bmpBytes,BMPSIZE,w,h);
		}
	}	

	//game loop
	while(true) {
		//draw game board
		cout << "\n\n\n\n";
		cout << "MATCH3!  Press Control-C to quit.";
		cout << "\n\n\n\n";
		cout << "\t     0 1 2 3 4 5 6 7\n";
		cout << "\t     ===============\n";
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (j == 0) {
					cout << "\t" << i << " || ";
				}
				cout << grid[j][i] << " ";
			}
			cout << endl;
		}

		cout << "\n\n";

		//user input
		int inputX;
		int inputY;
		int inputSwapX;
		int inputSwapY;

		cout << "\tPick x coord: ";
		cin >> inputX;
		while (inputX < 0 || inputX >= w) {
			cout << "\tInvalid Entry\n";
			cout << "\tPick a valid entry\n";
			cin >> inputX;
		}

		cout << "\tPick y coord: ";
		cin >> inputY;
		while (inputY < 0 || inputY >= h) {
			cout << "\tInvalid Entry\n";
			cout << "\tPick a valid entry\n";
			cin >> inputY;
		}

		cout << "\tSwap which x coord: ";
		cin >> inputSwapX;
		while (inputSwapX < 0 || inputSwapX >= w) {
			cout << "\tInvalid Entry\n";
			cout << "\tPick a valid entry\n";
			cin >> inputSwapX;
		}

		cout << "\tSwap which y coord: ";
		cin >> inputSwapY;
		while (inputSwapY < 0 || inputSwapY >= h) {
			cout << "\tInvalid Entry\n";
			cout << "\tPick a valid entry\n";
			cin >> inputSwapY;
		}

		if (inputX == inputSwapX && inputY == inputSwapY) {
			cout << "\n\nCan't swap the same points! \nTry again!" << endl;
			continue;
		}
		if (abs (inputX - inputSwapX) > 1 || abs (inputY - inputSwapY) > 1) {
			cout << "\n\nMust swap adjacent points! \nTry again!" << endl;
			continue;	
		}

		//make sure is adjacent tile
		// if ()

		// if (!validTile (point(inputX, inputY))
		// 	!validTile (point(inputSwapX, inputY))) {

		// }

		//swap grid positions!
		//STUDENTS: make sure you can only swap with ADJACENT positions
		char temp = grid[inputX][inputY];
		grid[inputX][inputY] = grid[inputSwapX][inputSwapY];
		grid[inputSwapX][inputSwapY] = temp;

		//check for matches:
		//STUDENTS: (advanced) - to do this properly you'll need a recursive function.
		// int matches = 0;
		// for (int i = -1; i < 2; i++) {
		// 	for (int j = -1; j < 2; j++) {
		// 		if (grid[inputX][inputY] == grid[inputX+i][inputY+j]) {
		// 			matches++;
		// 			cout << "match on " << inputX+i << ", " << inputY+j << endl;
		// 		}
		// 		if (grid[inputSwapX][inputSwapY] == grid[inputSwapX+i][inputSwapY+j]) {
		// 			matches++;
		// 			cout << "match on " << inputSwapX+i << ", " << inputSwapY+j << endl;
		// 		}
		// 	}
		// }

		// vector<point> points = getMatches (point(inputX, inputY), point (inputSwapX, inputSwapY), grid);
		vector<point> emptyStarterPoints;
		vector<point> points = getMatches (point(inputX, inputY), grid, emptyStarterPoints);

		points = getMatches (point(inputSwapX, inputSwapY), grid, points);
		// points.insert (points.end(), newPoints.begin(), newPoints.end());
		if (points.size () > 0) {
			for (int i = 0; i < points.size(); i++) {
				cout << "current point " <<  points[i].x << ", " << points[i].y << endl;
				grid[points[i].x][points[i].y] = ' ';
				// clearMatches (points[i], grid);
			}

		} else {
			//no matches, swap back
			temp = grid[inputX][inputY];
			grid[inputX][inputY] = grid[inputSwapX][inputSwapY];
			grid[inputSwapX][inputSwapY] = temp;
		}

		// for ()

		// if (matches >= 2) {
		// 	//destroy everything around the original swap position.
		// 	//STUDENTS: try making it destroy only the tiles matching it.
		// 	for (int i = -1; i < 2; i++) {
		// 		for (int j = -1; j < 2; j++) {
		// 			//BEGINNER STUDENTS: make sure it doesn't go off the grid! 
		// 			//right now we can escape the grid entirely by accessing a negative position on the array!
		// 			grid[inputX+i][inputY+j] = ' ';
		// 		}
		// 	}
		// } else {
		// 	//BEGINNER STUDENTS: make it swap back!
		// }

		//ALL STUDENTS: 
			//add a win state
			//try other mechanics, for example: 
				//match only 1
				//try fewer types of tiles
				//try 16x16 instead of 8x8
		
		//ADVANCED STUDENTS: 
			//add a lose state
			//make remaining tiles fall down if there is empty space
	}	
	return 0;
}

bool validTile (point p, int x, int y, char grid[][h]){
	return p.x + x >= 0 && p.x + x < w && p.y + y >= 0 && p.y + y < h;
}

vector<point> getMatches (point p1, char grid[][h], vector<point> prevPoints) {
	vector<point> returnPoint;
	returnPoint.insert (returnPoint.end(), prevPoints.begin(), prevPoints.end());	//add in all previous points
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (validTile (p1, i, j, grid) && grid[p1.x][p1.y] == grid[p1.x+i][p1.y+j]) {	//matching tiles
				if (!contains (returnPoint, point(p1.x, p1.y))) {
					returnPoint.push_back (point (p1.x, p1.y));	
				}

				if (!contains (returnPoint, point(p1.x + i, p1.y + j))) {
					vector<point> recursivePoints = getMatches (point (p1.x + i, p1.y + j), grid, returnPoint);
					returnPoint.insert (returnPoint.end(), recursivePoints.begin(), recursivePoints.end());	
				}
			}			
		}
	}

	return returnPoint;
}
bool contains (vector<point> points, point val) {
	for (int i = 0; i < points.size(); i++) {
		if (points[i].x == val.x && points[i].y == val.y) {
			return true;
		}
	}
	return false;
}

void clearMatches (point p, char (&grid)[w][h]) {
	cout << "current point " <<  p.x << ", " << p.y << endl;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			// if (p.x + i > 0 && p.x + i < w && p.y + j > 0 && p.y + j < h) {
			if (validTile (p, i, j, grid)) {
				
				if (grid[p.x + i][p.y + j] == grid[p.x][p.y]) {
					cout << "removing on " << p.x + i << ", " << p.y + j << endl;
					grid[p.x + i][p.y + j] = ' ';	
				}
				


			}
			//BEGINNER STUDENTS: make sure it doesn't go off the grid! 
			//right now we can escape the grid entirely by accessing a negative position on the array!
			// grid[inputX+i][inputY+j] = ' ';
		}
	}

}

point::point (int _x, int _y) :
	x(_x),
	y(_y)
{}

pointPair::pointPair (point _p1, point _p2) :
	p1(_p1),
	p2(_p2)
{}


char getTile(int x, int y, unsigned char data[], int size, int w, int h) {
	int r = 0;
	int g = 0;
	int b = 0;
	int i = 54 + (y * w + x) * 3;

	//each row has to add up to a multiple of four bytes.
	int numBytesPerRow = w * 3;
	int paddingValue = numBytesPerRow % 4;

	// cout << y * (4-paddingValue) << "\t";

	if (paddingValue != 0) {
		i += y * (4-paddingValue);
	}

	b = writeBytes(i,data);
	g = writeBytes(i+1,data);
	r = writeBytes(i+2,data);

	// cout << "x: " << x << ", y: " << y;
	// cout << "\t- " << r << ", " << g << ", " << b << "\n";

	if (r == 255 && g == 0 && b == 0) { //red
		return 'O';
	} else if (r == 0 && g == 255 && b == 0) { //green
		return 'X';
	} else if (r == 0 && g == 0 && b == 255) { //blue
		return '.';
	} else if (r == 255 && g == 0 && b == 255) { //purple
		return '#';
	} else if (r == 255 && g == 255 && b == 0) { //yellow
		return '?';
	} else {
		return ' ';
	}
}

int writeBytes(int offset, unsigned char data[]) {
	return data[offset];
}
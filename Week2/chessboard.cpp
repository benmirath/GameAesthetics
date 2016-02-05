#include <iostream>
using namespace std;


int main () {
	// Ball ball;
	// Ball chaserBall = Ball (9, 6, 1, 1);
	const int COLS = 8;
	const int ROWS = 8;
	char grid[COLS][ROWS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			//elegant, good
			if (i == j) {
				cout << 'U';
			} else if ((i + j) % 2) {
				cout << 'O';
			} else {
				cout << 'X';
			}

			//Sloppy, bad
			// if (i % 2 == 0) {
			// 	// if (i > 0 && 2 % i == 0) {
			// 		cout << 'U';
			// 		// grid[j][i] = 'U';
			// 	} else if (j % 2 == 0) {
			// 		cout << 'X';
			// 		// grid[j][i] = 'X';
			// 	} else {
			// 		cout << 'O';
			// 		// grid[j][i] = 'O';	
			// 	}
			// } else {
			// 	// if (j > 0 && 2 % j == 0) {
			// 	if (i == )
			// 		// grid[j][i] = 'U';
			// 		cout << 'U';
			// 	} else if (j % 2 == 0) {
			// 		cout << 'O';
			// 		// grid[j][i] = 'O';
			// 	} else {
			// 		cout << 'X';
			// 		// grid[j][i] = 'X';	
			// 	}
			// }
			

		}
		cout << endl;
	}

	return 0;	
}
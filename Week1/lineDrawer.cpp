#include <iostream>
using namespace std;

class Ball {
public:
	Ball(int _x = 1, int _y = 1, int _vx = 1, int _vy = 1);
	void update (int _r, int _c);
	void handleInput (char _input, int _maxX, int _maxY);
	void chaseOtherBall (Ball _otherBall);
	int getX ();
	int getY ();


private:
	int x;
	int y;
	int vx;
	int vy;
};

Ball::Ball (int _x, int _y, int _vx, int _vy):
	x(_x),
	y(_y),
	vx(_vx),
	vy(_vy)
{}

void Ball::handleInput (char _input, int _maxX, int _maxY) {
	if (_input == 'w') {
		y--;
	} else if (_input == 's') {
		y++;
	} else if (_input == 'a') {
		x--;
	} else if (_input == 'd') {
		x++;
	}

	if (x < 0) x = _maxX - 1;
	else if (x > _maxX - 1) x = 0;
	if (y < 0) y = _maxY - 1;
	else if (y > _maxY - 1) y = 0;
}

void Ball::update (int _c, int _r) {
	if (x > 0 && x < _c - 1) {
		// x += vx;
	} else {
		vx *= -1;
		// x += vx;
	}

	if (y > 0 && y < _r - 1) {
		// y += vy;
	} else {
		vy *= -1;
		// y += vy;
	}
}
void Ball::chaseOtherBall (Ball _otherBall) {
	if (x <_otherBall.x) {
		x++;
	} else if (x > _otherBall.x) {
		x--;
	}

	if (y < _otherBall.y) {
		y++;
	} else if (y > _otherBall.y) {
		y--;
	}
}

int Ball::getX () {
	return x;
}
int Ball::getY () {
	return y;
}

int main () {
	Ball ball;
	Ball chaserBall = Ball (9, 6, 1, 1);
	const int COLS = 35;
	const int ROWS = 15;
	char grid[COLS][ROWS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			grid[j][i] = '-';

		}
	}
	char input;
	while (input != 'q') {
		ball.handleInput (input, COLS, ROWS);
		ball.update(COLS, ROWS);
		grid [ball.getX()][ball.getY()] = 'O';
		// grid [ball.getX()][ball.getY()-1] = 'O';
		// grid [ball.getX()-1][ball.getY()] = 'O';
		// grid [ball.getX()][ball.getY()+1] = 'O';
		// grid [ball.getX()+1][ball.getY()] = 'O';

		chaserBall.chaseOtherBall (ball);
		grid [chaserBall.getX()][chaserBall.getY()] = 'X';


		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				cout << grid[j][i];
			}
			cout << endl;
		}

		//clear grid
		// for (int i = 0; i < ROWS; i++) {
		// 	for (int j = 0; j < COLS; j++) {
		// 		grid[j][i]= '-';
		// 	}
		// }
		cin >> input;

	}
	
	return 0;	
}
#pragma once
#pragma once
// Example program
#include<iostream>
#include<ctime>
using namespace std;
int pows(int a, int val) {//функция возведения в квадрат
	int rtn(1);
	for (size_t i(0); i < val; i++) {
		rtn *= a;
	}
	return rtn;
}
int sqrts(int val) {//функция нахождения степени двойки
	int rtn(0);
	for (; val != 1; rtn++) {
		val /= 2;
	}
	return rtn;
}


int rand_elem() {
	int rtn;
	int possibility = rand() % 10;
	if (possibility < 9) {
		rtn = pows(2, 1);
	}
	else {
		rtn = pows(2, 2);
	}
	return rtn;
}


class game {
private:
	
	int score;

	void rand_elem_fill() {
		int count(0);
		for (size_t i(0); i < 4; i++) {
			for (size_t j(0); j < 4; j++) {
				if (!this->matrix[i][j]) count++;
			}
		}
		if (!count) return;
		count = rand() % count;
		for (size_t i(0); i < 4; i++) {
			for (size_t j(0); j < 4; j++) {
				if (!this->matrix[i][j]) {
					if (!count) {
						this->matrix[i][j] = rand_elem();
						return;
					}
					else {
						count -= 1;
					}
				}
			}
		}
	}


public:
	int matrix[4][4];
	void restart() {
		for (size_t i(0); i < 4; i++) {
			for (size_t j(0); j < 4; j++) {
				matrix[i][j] = 0;
			}
		}
		srand(time(nullptr));
		int n = rand() % 4 + 3;
		int b, a, st;
		for (size_t i(0); i < n; i++) {
			a = rand() % 4;
			b = rand() % 4;
			st = rand() % 2 + 1;
			matrix[a][b] = pows(2, st);
		}
		score = 0;

		matrix[1][0] = 2;
		matrix[2][0] = 2;
		matrix[3][0] = 2;
	}
	game() {
		restart();
	}
	int get_score() {
		return score;
	}
	void move_right() {
		int summed = 0;
		bool moved(0);
		for (size_t i(0); i < 4; i++) {
			for (size_t k(0); k < 4; k++) {

				for (int j(3); j > 0; j--) {
					if (!matrix[i][j]) {
						matrix[i][j] += matrix[i][j - 1];
						matrix[i][j - 1] = 0;
						if(matrix[i][j]) moved = 1;
					}
					else if (matrix[i][j] == matrix[i][j - 1] && matrix[i][j] != summed) {
						matrix[i][j] += matrix[i][j - 1];
						matrix[i][j - 1] = 0;
						summed = matrix[i][j];
						score += matrix[i][j];
						moved = 1;
					}
				}
			}
			summed = 0;
		}
		if(moved)rand_elem_fill();
	}
	void move_top() {
		game tmp;
		for (size_t i(0); i < 4; i++) {
			for (size_t j(0); j < 4; j++) {
				tmp.matrix[i][j] = matrix[3 - j][i];
			}
		}
		tmp.move_right();
		for (size_t i(0); i < 4; i++) {
			for (size_t j(0); j < 4; j++) {
				matrix[3 - i][j] = tmp.matrix[j][i];
			}
		}
		score += tmp.score;
	}
	void move_bottom() {
		game tmp;
		for (size_t i(0); i < 4; i++) {
			for (size_t j(0); j < 4; j++) {
				tmp.matrix[i][3 - j] = matrix[3 - j][i];
			}
		}
		tmp.move_right();
		for (size_t i(0); i < 4; i++) {
			for (size_t j(0); j < 4; j++) {
				matrix[i][j] = tmp.matrix[j][i];
			}
		}
		score += tmp.score;
	}
	void move_left() {
		game tmp;
		for (size_t i(0); i < 4; i++) {
			for (size_t j(0); j < 4; j++) {
				tmp.matrix[i][j] = matrix[i][3 - j];
			}
		}
		tmp.move_right();
		for (size_t i(0); i < 4; i++) {
			for (size_t j(0); j < 4; j++) {
				matrix[i][j] = tmp.matrix[i][3 - j];
			}
		}
		score += tmp.score;
	}
	int can_move() {
		for (size_t i(0); i < 4; i++) {
			for (size_t j(0); j < 4; j++) {
				if (!matrix[i][j] || !matrix[j][i]) return 1;
				if (j != 3) {
					if (matrix[i][j] == matrix[i][j + 1]) return 1;
					if (matrix[j][i] == matrix[j + 1][i]) return 1;
				}

			}
		}
		return 0;
	}

};
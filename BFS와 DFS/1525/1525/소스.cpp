#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef vector<vector<int>> BOARD;

void printBoard(BOARD& board) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

int factorial(int i) {
	if (i == 1 || i == 0) return 1;
	else return i * factorial(i - 1);
}

int getOrder(vector<vector<int>>& board) {
	vector<bool> isUsed(9, false);
	int sum = 0;
	int temp;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp = 0;

			for (int k = 0; k <board[i][j]; k++)
				if (!isUsed[k]) temp++;

			//cout << temp << " ";
			
			sum += temp * factorial(8 - (i * 3 + j));
			isUsed[board[i][j]] = true;
		}
		//cout << endl;
	}

	return sum;
}

int main(void) {
	BOARD board;
	queue<vector<vector<int>>> Q;
	vector<bool> visited(362880, false);
	BOARD now, next;
	int move = 0;
	int r, c; //0ÀÇ À§Ä¡

	int dr[] = { 0, 0, 1, -1 };
	int dc[] = { 1, -1, 0, 0 };

	board.resize(3);
	for (int i = 0; i < 3; i++)
		board[i].resize(3);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];

	//cout << getOrder(board);

	Q.push(board);
	visited[getOrder(board)] = true;

	while (!Q.empty()) {

		move++;

		for (int i = 0; i < move; i++) {
			if (!Q.empty()) {
				now = Q.front();
				Q.pop();
			}

			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (now[j][k] == 0) {
						r = j;
						c = k;
					}
				}
			}				

			for (int j = 0; j < 4; j++) {

				if (0 <= r + dr[i] && r + dr[i] <= 2) {
					if (0 <= c + dc[i] && c + dc[i] <= 2) {
						now[r][c] = now[r + dr[i]][c + dc[i]];
						now[r + dr[i]][c + dc[i]] = 0;
						cout << now[r][c] << endl;

						if (!visited[getOrder(now)]) {
							Q.push(now);
							visited[getOrder(now)] = true;

							printBoard(now);
						}

						now[r + dr[i]][c + dc[i]] = now[r][c];
						now[r][c] = 0;
					}
				}
			}

		}

	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = i * 3 + j + 1;
	board[2][2] = 0;

	if (!visited[getOrder(board)]) move = -1;

	cout << move;

	return 0;
}

/*
for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];
*/

/*
vector<int> permutation;
	for (int i = 0; i < 5; i++)
		permutation.push_back(i);

	do {
		for (int i = 0; i < permutation.size(); i++)
			cout << permutation[i] << " ";
		cout << endl;
	} while (next_permutation(permutation.begin(), permutation.end()));
*/

/*
int temp = 0;
vector<int> permutation;
for (int i = 0; i < 9; i++)
	permutation.push_back(i);

do {
	for (int i = 0; i < permutation.size(); i++)
		cout << permutation[i] << " ";
	cout << ++temp;
	cout << endl;
} while (next_permutation(permutation.begin(), permutation.end()));
*/

/*
int temp = 0;
	vector<int> permutation;
	for (int i = 0; i < 3; i++)
		permutation.push_back(i);
	do {
		for (int i = 0; i < permutation.size(); i++)
			cout << permutation[i] << " ";
		cout << endl;
		temp++;
	} while (next_permutation(permutation.begin(), permutation.end()));
	//cout << temp;
*/
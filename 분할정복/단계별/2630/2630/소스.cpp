#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> board;
int white;
int blue;

void DAC(int len, int r, int c) {
	if (len == 1) {
		if (board[r][c]) blue++;
		else white++;
		return;
	}
	
	int num = 0;

	for (int i = r; i < len + r; i++) {
		for (int j = c; j < len + c; j++) {
			if (board[i][j]) {
				num++;
			}
		}
	}

	if (num == 0 || num == len * len) {
		if (!num)
			white++;
		else
			blue++;
		return;
	}
	else {
		DAC(len / 2, r, c);
		DAC(len / 2, r + len / 2, c);
		DAC(len / 2, r, c + len / 2);
		DAC(len / 2, r + len / 2, c + len / 2);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	board.resize(N);
	for (int i = 0; i < N; i++)
		board[i].resize(N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	DAC(N, 0, 0);

	cout << white << '\n' << blue;

	return 0;
}
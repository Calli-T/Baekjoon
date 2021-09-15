#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
int N;
int ans[3] = { 0 };
bool oneColor;
int firstColor;

void DAC(int len, int r, int c) {
	if (len == 1) {
		ans[paper[r][c] + 1]++;
		return;
	}

	oneColor = true;
	firstColor = paper[r][c];

	for (int i = r; i < r + len; i++) {
		for (int j = c; j < c + len; j++) {
			if (paper[i][j] != firstColor)
				oneColor = false;
		}
	}
	
	if (oneColor) {
		ans[firstColor + 1]++;
		return;
	}
	else {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				DAC(len / 3, r + i * (len / 3), c + j * (len / 3));
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	paper.resize(N);
	for (int i = 0; i < N; i++)
		paper[i].resize(N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	DAC(N, 0, 0);
	cout << ans[0] << '\n';
	cout << ans[1] << '\n';
	cout << ans[2] << '\n';

	return 0;
}
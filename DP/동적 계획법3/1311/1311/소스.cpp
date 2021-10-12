#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> D;
vector<vector<int>> DP;

int DFS(int depth, int state) {
	int& now = DP[depth][state];

	if (state == (1 << N) - 1)return 0;
	if (now != -1) return now;

	int ans = 1e9;
	for (int i = 0; i < N; i++) {
		if (!(state & (1 << i))) {
			ans = min(ans, DFS(depth + 1, state | (1 << i)) + D[depth][i]);
		}
	}

	return now = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	D.resize(N);
	for (int i = 0; i < N; i++)
		D[i].resize(N);
	DP.resize(N + 1);
	for (int i = 0; i < N + 1; i++)
		DP[i].resize(1 << (N + 1), -1);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> D[i][j];

	cout << DFS(0, 0);

	return 0;
}

/*
cout << endl;
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < (1 << N); j++) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
*/
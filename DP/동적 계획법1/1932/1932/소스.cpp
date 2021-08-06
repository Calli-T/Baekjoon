#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<int> line(501, 0);
	vector<vector<int>> DP(501, line);
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> DP[i][j];
		}
	}

	for (int i = 2; i <= N; i++) {
		DP[i][1] += DP[i - 1][1];
		DP[i][i] += DP[i - 1][i - 1];

		for (int j = 2; j < i; j++) {
			DP[i][j] += DP[i - 1][j - 1] > DP[i - 1][j] ? DP[i - 1][j - 1] : DP[i - 1][j];
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (DP[N][i] > ans) ans = DP[N][i];
	}
	cout << ans;

	return 0;
}

/*
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
	*/
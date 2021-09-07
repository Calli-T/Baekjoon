#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> bamboo;
vector<vector<int>> DP;

int dr[] = { 0, 0,1 , -1 };
int dc[] = { 1, -1 ,0 , 0 };

int DFS(int r, int c) {
	if (DP[r][c]) {
		return DP[r][c];
	}
	DP[r][c] = 1;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (bamboo[nr][nc] > bamboo[r][c]) {
			DP[r][c] = max(DP[r][c], DFS(nr, nc) + 1);
		}
	}
	
	return DP[r][c];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int ans = 0;
	
	cin >> n;
	bamboo.resize(n + 2);
	for (int i = 0; i < n + 2; i++)
		bamboo[i].resize(n + 2, 0);
	DP.resize(n + 2);
	for (int i = 0; i < n + 2; i++)
		DP[i].resize(n + 2, 0);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> bamboo[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, DFS(i, j));
		}
	}

	cout << ans;

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct cod {
	int x;
	int y;
};

void BFS(vector<vector<int>>& field, int N, int M, int& min) {
	queue<cod> Q;
	cod start, now, next;
	start.x = N;
	start.y = M;
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,-1,1 };

	if (field[N][M] == 1) {
		Q.push(start);
		field[start.x][start.y] = min;

		while (!Q.empty()) {
			now = Q.front();
			Q.pop();

			for (int i = 0; i < 4; i++) {
				if (field[now.x + dx[i]][now.y + dy[i]] == 1) {
					field[now.x + dx[i]][now.y + dy[i]] = min;
					next.x = now.x + dx[i];
					next.y = now.y + dy[i];
					Q.push(next);
				}
			}
		}

		min++;
	}

}

int cabbageField(void) {
	int M, N, K;
	int temp1, temp2;
	vector<vector<int>> field;
	vector<int> column;
	int min = 2;

	cin >> M >> N >> K;
	column.resize(N + 2);
	field.resize(M + 2, column);

	for (int i = 0; i < K; i++) {
		cin >> temp1 >> temp2;
		field[temp1 + 1][temp2 + 1] = 1;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			BFS(field, i, j, min);
		}
	}

	return min - 2;
}

int main() {

	vector<int> ans;
	int T;

	cin >> T;
	while (T--) {
		ans.push_back(cabbageField());
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}
/*

	for (int i = 0; i < M + 2; i++) {
		for (int j = 0; j < N + 2; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
*/

/*
1
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
*/
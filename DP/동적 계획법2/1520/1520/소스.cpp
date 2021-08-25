#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> DP;
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int nx, ny;

int DFS(int x, int y) {
	if (x == N && y == M) return 1;
	if (DP[x][y] != -1) return DP[x][y];

	DP[x][y] = 0;

	for (int i = 0; i < 4; i++) {

		nx = x + dx[i];
		ny = y + dy[i];
		if (map[x][y] > map[nx][ny]) {
			DP[x][y] = DP[x][y] + DFS(nx, ny);
		}

	}
	return DP[x][y];
}

int main() {

	cin >> N >> M;
	map.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		map[i].resize(M + 2, 10001);
	DP.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		DP[i].resize(M + 2, -1);
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> map[i][j];
		}
	}

	cout << DFS(1, 1);

	return 0;
}

/*
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10
*/

/*
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct cod {
	int x;
	int y;
};

int main() {

	vector<vector<int>> map;
	vector<vector<int>> DP;
	vector<vector<int>> VSC;
	int N, M;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	stack<cod> ST;
	cod now, next;
	bool isEnd;
	int temp;

	cin >> N >> M;
	map.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		map[i].resize(M + 2, 10001);
	DP.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		DP[i].resize(M + 2, -1);
	VSC.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		VSC[i].resize(M + 2, 0);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> map[i][j];
		}
	}

	now.x = 1;
	now.y = 1;
	DP[N][M] = 1;
	ST.push(now);

	while (!ST.empty()) {
		now = ST.top();
		isEnd = true;

		//cout << ST.size() << endl;
		cout << now.x << " " << now.y << endl;

		for (int i = 0; i < 4; i++) {
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];

			if (map[now.x][now.y] > map[next.x][next.y] && VSC[next.x][next.y] == 0) {
				isEnd = false;
				DP[next.x][next.y] = 0;
				ST.push(next);
				VSC[next.x][next.y] = 1;
				break;

			}
		}

		if (isEnd)
			ST.pop();

	}

	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < M + 2; j++) {
			cout << DP[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;

}
*/

/*int DFS(int x, int y) {
	if (x == N && y == M) return 1;
	if (DP[x][y] != -1) return DP[x][y];
	
	DP[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		
		nx = x + dx[i];
		ny = y + dy[i];
		if (map[x][y] > map[nx][ny]) {
			DP[x][y] = DP[x][y] + DFS(nx, ny);
		}

	}
	return DP[x][y];
}

int main() {

	cin >> N >> M;
	map.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		map[i].resize(M + 2, 10001);
	DP.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		DP[i].resize(M + 2, -1);
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> map[i][j];
		}
	}

	cout << DFS(1, 1);

	return 0;
}*/

/*
for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < M + 2; j++) {
			cout << DP[i][j] << "\t";
		}
		cout << endl;
	}
*/

/*
	 for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (map[i - 1][j] > map[i][j])
				DP[i][j] += DP[i - 1][j];
			if (map[i][j - 1] > map[i][j])
				DP[i][j] += DP[i][j - 1];
			if (map[i + 1][j] > map[i][j])
				DP[i][j] += DP[i + 1][j];
			if (map[i][j + 1] > map[i][j])
				DP[i][j] += DP[i][j + 1];
		}
	}
	 */
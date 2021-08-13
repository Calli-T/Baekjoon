#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cod {
	int x;
	int y;
};

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int main() {
	vector<vector<int>> maze;
	int N, M;
	cod now, next;
	int ans = 0;
	int size;

	cin >> M >> N;
	maze.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		maze[i].resize(M + 2, 1);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
		}
	}

	queue<cod> Q;
	for (int i = 1; i < maze.size() - 1; i++) {
		for (int j = 1; j < maze[i].size() - 1; j++) {
			if (maze[i][j] == 1) {
				now.x = i;
				now.y = j;
				Q.push(now);
			}
		}
	}

	while (true) {

		size = Q.size();
		while (size--) {

			now = Q.front();
			Q.pop();

			for (int i = 0; i < 4; i++) {
				if (!maze[now.x + dx[i]][now.y + dy[i]]) {
					next.x = now.x + dx[i];
					next.y = now.y + dy[i];
					maze[next.x][next.y] = 1;
					Q.push(next);
				}
			}

		}
		
		if (Q.empty()) break;

		ans++;

	}

	for (int i = 1; i < maze.size() - 1; i++) {
		for (int j = 1; j < maze[i].size() - 1; j++) {
			if (!maze[i][j]) ans = -1;
		}
	}

	cout << ans;

	return 0;

}

/*
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[i].size(); j++) {
			cout << maze[i][j] << "\t";
		}
		cout << endl;
	}
*/

/*
	now.x = 1;
	now.y = 1;
	Q.push(now);
	maze[1][1] = 0;
	*/
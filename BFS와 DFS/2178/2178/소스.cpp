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
	vector<vector<bool>> maze;
	int N, M;
	string line;
	cod now, next;
	int ans = 0;
	int size;
	bool isEnd = false;

	cin >> N >> M;
	maze.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		maze[i].resize(M + 2);
	}
	
	for (int i = 1; i <= N; i++) {
		cin >> line;
		for (int j = 0; j < (int)line.size(); j++) {
			maze[i][j + 1] = line[j] == '1' ? true : false;
		}
	}

	queue<cod> Q;
	now.x = 1;
	now.y = 1;
	Q.push(now);
	maze[1][1] = 0;
	ans++;

	while (!Q.empty()) {
		size = Q.size();
		while (size--) {
			
			now = Q.front();
			Q.pop();

			if (now.x == N && now.y == M)
				isEnd = true;
			
			for (int i = 0; i < 4; i++) {
				if (maze[now.x + dx[i]][now.y + dy[i]]) {
					next.x = now.x + dx[i];
					next.y = now.y + dy[i];
					maze[next.x][next.y] = 0;
					Q.push(next);
				}
			}
		}

		if (isEnd) break;
		ans++;
	}

	cout << ans;

	return 0;
	
}

/*

	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[i].size(); j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
*/
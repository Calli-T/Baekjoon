#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cod {
	int x;
	int y;
};

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void BFS(int& group, vector<vector<int>>& board, int R, int C) {
	if (board[R][C] > 0) return;

	int nowColor = board[R][C];
	queue<cod> Q;
	cod now, next;
	
	group++;
	
	now.x = R;
	now.y = C;
	Q.push(now);
	board[R][C] = group;

	while (!Q.empty()) {
		now = Q.front();
		Q.pop();
		
		for (int i = 0; i < 4; i++) {
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if (board[next.x][next.y] == nowColor) {
				Q.push(next);
				board[next.x][next.y] = group;
			}
		}
	}
}

int main(void) {
	
	int N;
	vector<vector<int>> board;
	vector<vector<int>> copyBoard;
	string line;
	int group = 0;
	int ans1, ans2;
	//vector<vector<bool>> visited;

	cin >> N;
	board.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		board[i].resize(N + 2, 0);

	for (int i = 1; i <= N; i++) {
		cin >> line;
		for (int j = 1; j <= N; j++) {
			if (line[j - 1] == 'R')
				board[i][j] = -1;
			else if (line[j - 1] == 'G')
				board[i][j] = -2;
			else board[i][j] = -3;
		}
	}
	copyBoard = board;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (copyBoard[i][j] == -1)
				copyBoard[i][j] = -2;

	for(int i = 1; i<= N; i++)
		for(int j = 1; j<= N; j++)
			BFS(group, board, i, j);

	ans1 = group;
	group = 0;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			BFS(group, copyBoard, i, j);
	ans2 = group;

	cout << ans1 << " " << ans2 << endl;

	return 0;
}

//간단한 문제
//BFS로 구역수를 구한다음
//R과 B를 한쪽을 통일해서 다시 하면된다
//R은 1, G는 2, B는 3
//불가는 0

/*
for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
*/

/*
visited.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		visited[i].resize(N + 2, true);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = false;
		}
	}
*/
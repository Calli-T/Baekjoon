#include <iostream>
#include <vector>
#include <stack>

#define NOW [now.x][now.y]
#define NEXT [next.x][next.y]

using namespace std;

struct cod {
	int x;
	int y;
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int DFS(vector<vector<int>>& board, int x, int y) {
	int R = board.size() - 2;
	int C = board[0].size() - 2;
	stack<cod> ST;
	cod now, next;
	vector<vector<bool>> visited;
	vector<bool> alphabet(27, false);
	int ans = 0;
	bool isEnd;

	visited.resize(R + 2);
	for (int i = 0; i < visited.size(); i++)
		visited[i].resize(C + 2, false);

	
	now.x = x;
	now.y = y;
	ST.push(now);
	visited NOW = true;
	alphabet[board NOW] = true;

	while (!ST.empty()) {
		cout << "1" << endl;
		int size = ST.size();
		ans = max(ans, size);
		isEnd = true;
		now = ST.top();

		for (int i = 0; i < 4; i++) {
			cout << "2" << endl;
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if (!visited[next.x][next.y] && !alphabet[board NEXT] && board NEXT != 0) {
				ST.push(next);
				alphabet[board NEXT] = true;
				visited NEXT = true;
				isEnd = false;
				break;
			}
		}

		cout << "3" << endl;
		if (isEnd) {
			cout << "4" << endl;
			now = ST.top();
			alphabet[board NOW] = false;
			ST.pop();
		}
	}

	return ans;
}

int main(void) {
	
	int R, C;
	vector<vector<int>> board;
	string line;
	int ans = 0;
	
	cin >> R >> C;
	board.resize(R + 2);
	for (int i = 0; i < board.size(); i++)
		board[i].resize(C + 2, 0);

	for (int i = 1; i <= R; i++) {
		cin >> line;
		for (int j = 1; j <= C; j++)
			board[i][j] = (int)line[j - 1] - 64;
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			ans = max(ans, DFS(board, i, j));
		}
	}
	
	cout << ans;

	return 0;
}
// R행 C열의 2차원 배열
// visited가 필요하다
// 각 칸별로 싹 DFS를 적용할 필요가 있다
// visited로 했을 경우 한 칸에서 간곳을 다른칸에서 못가게 되므로
// 방문체크는 누적식이 아니라, 알파펫기준으로 해야한다
// 가만 생각해보니, 뺐던 곳으로 다시 들어가지 않도록 하기위해
// 방문체크(visited)는 필수이지만, 할 때마다 리셋해야한다
// 모든 알파벳이 중복이 없으므로, 스택의 최대 크기가 해당 칸에서의 최대 칸 수 이다
// 현재 스택에 있는 알파벳 중복체크는 27칸짜리 1차원배열로 해결한다

/*
char text = 'Z';
	cout << (int)text - 64;
*/

/*

	for (int i = 0; i < R + 2; i++) {
		for (int j = 0; j < C + 2; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
*/
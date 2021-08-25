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
// R�� C���� 2���� �迭
// visited�� �ʿ��ϴ�
// �� ĭ���� �� DFS�� ������ �ʿ䰡 �ִ�
// visited�� ���� ��� �� ĭ���� ������ �ٸ�ĭ���� ������ �ǹǷ�
// �湮üũ�� �������� �ƴ϶�, ������������� �ؾ��Ѵ�
// ���� �����غ���, ���� ������ �ٽ� ���� �ʵ��� �ϱ�����
// �湮üũ(visited)�� �ʼ�������, �� ������ �����ؾ��Ѵ�
// ��� ���ĺ��� �ߺ��� �����Ƿ�, ������ �ִ� ũ�Ⱑ �ش� ĭ������ �ִ� ĭ �� �̴�
// ���� ���ÿ� �ִ� ���ĺ� �ߺ�üũ�� 27ĭ¥�� 1�����迭�� �ذ��Ѵ�

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
#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

int r, c;
char board[MAX][MAX];
int alphabet[26] = { 0 };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, +1 };
int max_path = 0;

void dfs(int row, int col, int find_path) {

	max_path = max(find_path, max_path);

	for (int i = 0; i < 4; ++i) {
		int new_row = row + dx[i];
		int new_col = col + dy[i];

		if (0 <= new_row && new_row < r && 0 <= new_col && new_col < c) {
			if (!alphabet[((int)board[new_row][new_col]) - 65]) {

				alphabet[((int)board[new_row][new_col]) - 65]++;
				dfs(new_row, new_col, find_path + 1);
				alphabet[((int)board[new_row][new_col]) - 65]--;

			}
		}
	}
}

int main(void) {

	cin >> r >> c;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> board[i][j];
		}
	}

	alphabet[((int)board[0][0]) - 65]++;

	dfs(0, 0, 1);

	cout << max_path << endl;

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

/*
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
		int size = ST.size();
		ans = max(ans, size);
		isEnd = true;
		now = ST.top();
		printST(ST, board);

		for (int i = 0; i < 4; i++) {
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

		if (isEnd) {
			now = ST.top();
			alphabet[board NOW] = false;
			ST.pop();

			//cout << (char)(board NOW + 64);
		}
	}

	return ans;
*/

/*
void printST(stack<cod> ST, vector<vector<int>>& board) {
	vector<cod> temp;
	cod now;
	while (!ST.empty()) {
		now = ST.top();
		ST.pop();
		temp.push_back(now);
	}

	for (int i = temp.size() - 1; i > -1; i--) {
		now = temp[i];
		cout << (char)(board NOW + 64) << " ";
	}
	cout << endl;
}
*/

/*

	for (int i = 0; i < 4; i++) {
		next.x = R + dx[i];
		next.y = C + dy[i];
		cout << next.x << " " << next.y << endl;

		for (int i = 1; i <= N; i++) {
			if (board NEXT == path[i]) isPossible = false;
		}
		if (board NEXT == 64) isPossible = false;

		if (!isPossible) continue;
		else {
			//cout << (char)(board NEXT + 64) << " ";
			path[N + 1] = board NEXT;
			DFS(next.x, next.y, N + 1);
		}
	}
*/

/*
void printPath() {
	for(int i = 1; i<path.size(); i++){
		cout << (char)(path[i] + 64) << " ";
	}
	cout << endl;
}
*/

/*
20 20
AYXWVUTSRQPONMLKJIHG
YXWVUTSRQPONMLKJIHGF
XWVUTSRQPONMLKJIHGFE
WVUTSRQPONMLKJIHGFED
VUTSRQPONMLKJIHGFEDC
UTSRQPONMLKJIHGFEDCB
TSRQPONMLKJIHGFEDCBA
SRQPONMLKJIHGFEDCBAA
RQPONMLKJIHGFEDCBAAA
QPONMLKJIHGFEDCBAAAA
PONMLKJIHGFEDCBAAAAA
ONMLKJIHGFEDCBAAAAAA
NMLKJIHGFEDCBAAAAAAA
MLKJIHGFEDCBAAAAAAAA
LKJIHGFEDCBAAAAAAAAA
KJIHGFEDCBAAAAAAAAAA
JIHGFEDCBAAAAAAAAAAA
IHGFEDCBAAAAAAAAAAAA
HGFEDCBAAAAAAAAAAAAA
GFEDCBAAAAAAAAAAAAAA
*/

/*
10 10
PONMLKJIHG
ONMLKJIHGF
NMLKJIHGFE
MLKJIHGFED
LKJIHGFEDC
KJIHGFEDCB
JIHGFEDCBA
IHGFEDCBAA
HGFEDCBAAA
GFEDCBAAAA
*/
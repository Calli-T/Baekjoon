#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct state {
	int x;
	int y;
	bool isBroken;
};

int main(void) {
	vector<vector<int>> maze;
	vector<vector<bool>> visited;
	vector<vector<bool>> visited2;
	string line;
	queue<state> Q;
	int N, M;
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	state now, next;
	int ans = 0;
	int size;
	bool isEnd = false;

	cin >> N >> M;
	maze.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		maze[i].resize(M + 2, 2);
	visited.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		visited[i].resize(M + 2, false);
	visited2.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		visited2[i].resize(M + 2, false);

	for (int i = 1; i <= N; i++) {
		cin >> line;
		for (int j = 1; j <= M; j++)
			maze[i][j] = (line[j - 1] == '1' ? 1 : 0);
	}





	now.x = 1;
	now.y = 1;
	now.isBroken = false;
	Q.push(now);
	ans++;

	while (!Q.empty()) {
		size = Q.size();
		while (size--) {

			now = Q.front();
			Q.pop();

			if (now.x == N && now.y == M)
				isEnd = true;

			for (int i = 0; i < 4; i++) {
				next.x = now.x + dx[i];
				next.y = now.y + dy[i];
				//cout << next.x << " " << next.y << " " << endl;
				//�̹� ���� �μ����� �ִ� ���
				if (now.isBroken) {
					//���� �ν��� �� �������� �湮�� ���̾���, ���ΰ��
					if (!visited2[next.x][next.y] && maze[next.x][next.y] == 0) {
						next.isBroken = now.isBroken;
						visited2[next.x][next.y] = true;
						Q.push(next);
					}
				} // ���� �μ� ���̾��� ���
				else {
					//���� �μ��� �ʾ��� �� �������� �湮�� ���̾���, ���ΰ��
					if (!visited[next.x][next.y] && maze[next.x][next.y] == 0) {
						next.isBroken = now.isBroken;
						visited[next.x][next.y] = true;
						Q.push(next);
					} //���� �ν��� �� �������� �湮�� ���̾���, ���� �ƴѰ��
					else if (!visited2[next.x][next.y] && maze[next.x][next.y] == 1) {
						next.isBroken = true;
						visited2[next.x][next.y] = true;
						Q.push(next);
					}
				}
				
			}

		}
		if (isEnd) break;
		ans++;
	}

	if (!isEnd) ans = -1;
	cout << ans;

	return 0;
}

/*
//�湮���߰�, ���̶��
				if (!visited[next.x][next.y] && !visited2[next.x][next.y] && maze[next.x][next.y] == 0) {
					next.isBroken = now.isBroken;
					if (now.isBroken)
						visited2[next.x][next.y] = true;
					else
						visited[next.x][next.y] = true;
					Q.push(next);
				}//�湮���߰�, ���̰�, ���� �μ����̾��ٸ�
				else if (!visited[next.x][next.y] && !visited2[next.x][next.y] && maze[next.x][next.y] == 1 && now.isBroken == false) {
					next.isBroken = true;
					visited2[next.x][next.y] = true;
					Q.push(next);
				}
*/
/*
for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			cout << maze[i][j] << "\t";
		}
		cout << endl;
	}
*/
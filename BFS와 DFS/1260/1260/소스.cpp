#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& maze, vector<bool>& visited, int V);
void BFS(vector<vector<int>>& maze, vector<bool>& visited, int V);

int main(void) {

	int N, M, V;
	vector<vector<int>> maze;
	vector<bool> visited;
	int temp1, temp2;

	cin >> N >> M >> V;
	maze.resize(N + 1);
	visited.resize(N + 1, false);
	for (int i = 0; i < M; i++) {
		cin >> temp1 >> temp2;
		maze[temp1].push_back(temp2);
		maze[temp2].push_back(temp1);
	}

	for (int i = 0; i < maze.size(); i++) {
		sort(maze[i].begin(), maze[i].end());
	}	

	DFS(maze, visited, V);
	for (int i = 0; i < visited.size(); i++) {
		visited[i] = false;
	}
	cout << endl;
	BFS(maze, visited, V);

	return 0;
}

void DFS(vector<vector<int>>& maze, vector<bool>& visited, int V) {
	stack<int> ST;
	int now;
	bool hasChild;

	ST.push(V);
	visited[V] = true;
	cout << V << ' ';

	while(!ST.empty()) {
		now = ST.top();
		//cout << now << endl;
		hasChild = false;
		for (int j = 0; j < maze[now].size(); j++) {
			if (visited[maze[now][j]] == false) {
				visited[maze[now][j]] = true;
				ST.push(maze[now][j]);
				cout << maze[now][j] << ' ';
				hasChild = true;
				break;
			}
		}

		if (!hasChild) {
			ST.pop();
		}
	}

}

void BFS(vector<vector<int>>& maze, vector<bool>& visited, int V) {
	queue<int> Q;
	int now;

	Q.push(V);
	visited[V] = true;
	cout << V << " ";

	while (!Q.empty()) {
		now = Q.front();
		Q.pop();

		for (int i = 0; i < maze[now].size(); i++) {
			if (!visited[maze[now][i]]) {
				Q.push(maze[now][i]);
				visited[maze[now][i]] = true;
				cout << maze[now][i] << " ";
			}
		}
	}
}

// N: vertex, M: edge, V: starting point

/*
while (!ST.empty()) {

		now = ST.top();
		ST.pop();

		cout << now << endl;





		for (int i = 0; i < maze[now].size(); i++) {
			if (visited[maze[now][i]] == false) {
				visited[maze[now][i]] = true;
				ST.push(maze[now][i]);
			}
		}

	}
*/

/*
DFS
1. ���������� ����(���ÿ� �ְ�, �湮ǥ�ø� �ϰ�, ����Ѵ�)
2. ������ �� ������ Ž���Ѵ�(while�� ������ ������ �ݺ�)
3.	�������� ����صд�
	�̾��� ����� ����, Ȥ�� �̵�����(true�� �ƴ� ��带 ã�Ҵ����� bool��)�� �ʱ⼼���Ѵ�
	�ش� ������ �̾��� ������ �����Ϳ��� ū ������� �Ⱦ��

	�� �İ� ������ (false��)������ ã����, �ش� ������ stack�� �ְ�, ����ϰ�, break���Ǵ�
	break�� �ɸ� while�� ���������� ���ƿ���, ������ �ٲ� top�� ���� ������ ��������

	��� ����� ������ ã������ ���� visited�� true�ų�, �ƴϸ� ���°��
	count���� 0�̰ų� hasChild�� false�ε� �� ��� �� ĭ�ڷΰ���(stack.pop) �θ������ �ٽ�
	ã�ƺ���
*/
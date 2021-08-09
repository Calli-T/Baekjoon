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
1. 시작점으로 간다(스택에 넣고, 방문표시를 하고, 출력한다)
2. 스택이 빌 때까지 탐색한다(while문 이하의 내용을 반복)
3.	현재점을 기억해둔다
	이어진 노드의 개수, 혹은 이동가능(true가 아닌 노드를 찾았는지의 bool값)을 초기세팅한다
	해당 정점과 이어진 정점을 작은것에서 큰 순서대로 훑어보며

	더 파고 들어가야할 (false인)정점을 찾으면, 해당 정점을 stack에 넣고, 출력하고, break를건다
	break를 걸면 while의 시작점으로 돌아오고, 새로이 바뀐 top에 대한 세팅이 가해진다

	모든 연결된 정점을 찾았으나 전부 visited이 true거나, 아니면 없는경우
	count값이 0이거나 hasChild가 false인데 이 경우 한 칸뒤로가서(stack.pop) 부모노드부터 다시
	찾아본다
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define NOW [now.r][now.c]
#define NEXT [next.r][next.c]

struct loc {
	int r;
	int c;
};

int dr[] = { 0, 0 , 1, -1 };
int dc[] = { 1,  -1, 0, 0 };

int N, M, F; //�ʵ� ũ��, �մԼ�, ����
vector<vector<int>> field;
vector<vector<bool>> visited;
vector<int> row;
vector<vector<int>> ST; // start
vector<vector<int>> ED; // end
loc start;
loc nextDest;

void resetVisited() {
	visited.clear();
	//�湮üũ ����
	visited.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		visited[i].resize(N + 2, false);
}

void setField() {
	int r, c;

	cin >> N >> M >> F;
	row.resize(N + 2, 1);
	field.resize(N + 2, row);
	
	resetVisited();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> field[i][j]; // 0�� ����, 1����
		}
	}

	//����� ����
	cin >> start.r >> start.c;

	for (int i = 0; i < M; i++) {
		cin >> r >> c;
		field[r][c] = 2; // �����
		cin >> r >> c;
		field[r][c] = 3; // ������
	}
}

void printField() {
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < N +2; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

//�Ÿ� ��ȯ��
int BFS(loc& now, int pur) {
	queue<loc> Q;
	int size = 1;

	resetVisited();
	Q.push(now);
	visited NOW = true;
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			loc next;
			next.r = now.r + dr[i];
			next.c = now.c + dc[i];

			
		}
	}

	return 0;
}

int simulate() {
	loc now;
	now.r = start.r;
	now.c = start.c;

	cout << BFS(now, 2);

	return 0;
}

int main(void) {
	

	setField();
	printField();
	cout << simulate();

	return 0;
}
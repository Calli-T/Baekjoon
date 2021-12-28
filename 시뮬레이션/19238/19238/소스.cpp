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

int dr[] = { 1, -1 , 0, 0 };
int dc[] = { 0,  0, 1, -1 };

int N, M, F; //필드 크기, 손님수, 연료
vector<vector<int>> field;
vector<vector<bool>> visited;
vector<int> row;
vector<vector<int>> ST; // start
vector<vector<int>> ED; // end
loc start;
loc nextDest;

void resetVisited() {
	visited.clear();
	//방문체크 세팅
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
			cin >> field[i][j]; // 0은 공간, 1은벽
		}
	}

	//출발지 설정
	cin >> start.r >> start.c;

	for (int i = 0; i < M; i++) {
		cin >> r >> c;
		field[r][c] = 2; // 출발지
		cin >> r >> c;
		field[r][c] = 3; // 목적지
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

//거리 반환용
int BFS(loc& now, int pur) {
	queue<loc> Q;
	int size = 1;
	bool isEnd;

	resetVisited();
	Q.push(now);
	visited NOW = true;
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		cout << cur.r << " " << cur.c << '\n';

		isEnd = false;
		for (int i = 0; i < 4; i++) {
			loc next;
			next.r = now.r + dr[i];
			next.c = now.c + dc[i];

			cout << visited NEXT << " " << field NEXT << '\n';
			if (!visited[next.r][next.c] && field NEXT != 1) {
				visited NEXT = true;
				Q.push(next);

				if (field NEXT == pur) {
					isEnd = true;
				}
			}
		}

		if (isEnd) break;
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
	simulate();

	return 0;
}

/*
6 3 15
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 1 0 0
6 5
2 2 5 6
5 4 1 6
4 2 3 5

6 3 15
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 1 0 0
1 4
2 2 5 6
5 4 1 6
4 2 3 5
*/
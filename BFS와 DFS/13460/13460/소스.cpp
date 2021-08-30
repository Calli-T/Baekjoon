#include <iostream>
#include <vector>
#include <queue>

#define RED [R.r][R.c]
#define BLUE [B.r][B.c]
#define RB [now.R.r][now.R.c][now.B.r][now.B.c]
#define RBN [next.R.r][next.R.c][next.B.r][next.B.c]
#define TEMP [temp.r][temp.c]
#define MAZE vector<vector<int>>& maze

using namespace std;

//비어있음 / 북동남서
int dc[] = { 0, 0, 1, 0, -1 };
int dr[] = { 0 , -1, 0,  1, 0 };

struct cod {
	int r;
	int c;
};
struct status {
	cod R;
	cod B;
	int count;
};

void printNow(cod R, cod B, vector<vector<int>> maze) {
	maze RED = 3;
	maze BLUE = 4;
	int N = maze.size();
	int M = maze[0].size();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

// 이동을 담당, 출구판정은 status에 넣음
// 북동남서 = 1234
void operate(MAZE, status& now, int D);

int BFS(MAZE, status now) {
	int N = maze.size();
	int M = maze[0].size();
	status next;

	vector<bool> temp1(M, false);
	vector<vector<bool>> temp2(N, temp1);
	vector<vector<vector<bool>>> temp3(M, temp2);
	vector<vector<vector<vector<bool>>>> visited(N, temp3);
	//visited[i][j][k][l]은 Red(i, j)와 Blue(k, l)일 때 방문 기록이 있는지를 확인한다
	//cout << visited.size() << visited[0].size() << visited[0][0].size() << visited[0][0][0].size();

	queue<status> Q;
	Q.push(now);
	visited RB = true;

	while (!Q.empty()) {
		/*
		cout << now.R.r << " " << now.R.c << "\t";
		cout << now.B.r << " " << now.B.c << "\t";
		cout << now.count << endl;
		*/
		now = Q.front();
		Q.pop();
		
		for (int i = 0; i < 4; i++) {
			
			next.R.r = now.R.r;
			next.R.c = now.R.c;
			next.B.r = now.B.r;
			next.B.c = now.B.c;
			next.count = now.count + 1;
			operate(maze, next, i + 1);

			if (next.count > 10) return -1;
			
			if (next.B.r != -1) {
				if (next.R.r == -1) return next.count;
				else if(!visited RBN){
					Q.push(next);
					visited RBN = true;
				}
			}
		}
	}

	/*
	operate(maze, now, 1);
	operate(maze, now, 2);
	operate(maze, now, 3);
	operate(maze, now, 4);
	*/

	return -1;
}

int main(void) {
	vector<vector<int>> maze;
	string line;
	int N, M;
	cod R, B;
	status start;

	cin >> N >> M;
	maze.resize(N);
	for (int i = 0; i < N; i++)
		maze[i].resize(M);

	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < M; j++) {
			if (line[j] == '#')
				maze[i][j] = 1;
			else if (line[j] == '.')
				maze[i][j] = 0;
			else if (line[j] == 'R') {
				maze[i][j] = 0;
				R.r = i;
				R.c = j;
			}
			else if (line[j] == 'B') {
				maze[i][j] = 0;
				B.r = i;
				B.c = j;
			}
			else {
				maze[i][j] = 2;
			}
		}
	}
	start.R = R;
	start.B = B;
	start.count = 0;
	
	cout << BFS(maze, start);

	return 0;
}

void operate(MAZE, status& now, int D) {
	bool redFirst = false;
	cod temp;

	if (D % 2 == 1) {
		if (now.R.c != now.B.c) redFirst = true;
		else {
			if (now.R.r < now.B.r && D == 1) redFirst = true;
			else if (now.R.r > now.B.r && D == 3) redFirst = true;
		}
	}
	else {
		if (now.R.r != now.B.r) redFirst = true;
		else {
			if (D == 2 && now.R.c > now.B.c) redFirst = true;
			else if (D == 4 && now.R.c < now.B.c) redFirst = true;
		}
	}

	//cout << "1";
	temp = redFirst ? now.R : now.B;
	while (maze TEMP != 1 && maze TEMP != 2) {
		temp.r += dr[D];
		temp.c += dc[D];
	}
	//cout << "2";
	if (maze TEMP == 2) {
		if (redFirst) {
			now.R.c = -1;
			now.R.r = -1;
		}
		else {
			now.B.c = -1;
			now.B.r = -1;
		}
	}
	else {
		if (redFirst) {
			now.R.r = temp.r - dr[D];
			now.R.c = temp.c - dc[D];
		}
		else {
			now.B.r = temp.r - dr[D];
			now.B.c = temp.c - dc[D];
		}
	}
	//cout << "3";
	temp = redFirst ? now.B : now.R;
	while (maze TEMP != 1 && maze TEMP != 2 && (redFirst ? !(temp.r == now.R.r && temp.c == now.R.c) : !(temp.r == now.B.r && temp.c == now.B.c))) {
		temp.r += dr[D];
		temp.c += dc[D];
	}
	//cout << "4";
	if (maze TEMP == 2) {
		if (redFirst) {
			now.B.c = -1;
			now.B.r = -1;
		}
		else {
			now.R.c = -1;
			now.R.r = -1;
		}
	}
	else {
		if (redFirst) {
			now.B.r = temp.r - dr[D];
			now.B.c = temp.c - dc[D];
		}
		else {
			now.R.r = temp.r - dr[D];
			now.R.c = temp.c - dc[D];
		}
	}
	//cout << "5";

	//now.count++;
	/*
		cout << redFirst << endl;
		cout << now.R.r << " " << now.R.c << endl;
		cout << now.B.r << " " << now.B.c << endl;
	*/
}

//방향D는 북동남서 기준으로 1,2,3,4
//구슬의 이동순서는 같은행/열에 있을 때만 중요할듯?

/*
1. 방향을 보고 먼저 움직일 구슬을 정함(0,1로 구분)
2. 먼저움직이는 구슬은 움직이는 방향에서 가장 가까운 벽 또는 포탈을 찾음
3. 나중움직이는 구슬은 움직이는 방향에서 가장 가까운 벽 또는 포탈을 찾되 먼저 움직인 구슬도 벽판정
4. 포탈에 먼저들어가면 (-1, -1)로 그 외의 경우는 위치를 좌표에
5. 마지막으로 count를 ++;
*/

/*
5 5
#####
#..B#
#.#.#
#RO.#
#####
*/

/*
5 5
#####
#B.R#
#.#.#
#.O.#
#####
*/

/*
5 5
#####
#B..#
#.#.#
#RO.#
#####
*/
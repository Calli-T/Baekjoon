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

//������� / �ϵ�����
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

// �̵��� ���, �ⱸ������ status�� ����
// �ϵ����� = 1234
void operate(MAZE, status& now, int D);

int BFS(MAZE, status now) {
	int N = maze.size();
	int M = maze[0].size();
	status next;

	vector<bool> temp1(M, false);
	vector<vector<bool>> temp2(N, temp1);
	vector<vector<vector<bool>>> temp3(M, temp2);
	vector<vector<vector<vector<bool>>>> visited(N, temp3);
	//visited[i][j][k][l]�� Red(i, j)�� Blue(k, l)�� �� �湮 ����� �ִ����� Ȯ���Ѵ�
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

//����D�� �ϵ����� �������� 1,2,3,4
//������ �̵������� ������/���� ���� ���� �߿��ҵ�?

/*
1. ������ ���� ���� ������ ������ ����(0,1�� ����)
2. ���������̴� ������ �����̴� ���⿡�� ���� ����� �� �Ǵ� ��Ż�� ã��
3. ���߿����̴� ������ �����̴� ���⿡�� ���� ����� �� �Ǵ� ��Ż�� ã�� ���� ������ ������ ������
4. ��Ż�� �������� (-1, -1)�� �� ���� ���� ��ġ�� ��ǥ��
5. ���������� count�� ++;
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
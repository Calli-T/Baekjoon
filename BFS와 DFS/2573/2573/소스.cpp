#include <iostream>
#include <vector>
#include <queue>

#define NEXT [next.r][next.c]

using namespace std;

struct cod {
	int r;
	int c;
};
int R, C;
int dr[] = { 1, -1, 0 , 0 };
int dc[] = { 0, 0 , 1 , -1 };
vector<vector<int>> ocean;
vector<vector<int>> melting;
vector<vector<bool>> visited;
int ans = 0;
int glacierChain;
cod now;

int BFS(void) {
	queue<cod> Q;
	int firstChain = 0;
	cod next;

	visited.clear();
	visited.resize(R + 2);
	for (int i = 0; i <= R; i++)
		visited[i].resize(C + 2, 0);

	//cout << now.r << " "  <<  now.c << endl;

	if (!ocean[now.r][now.c]) return 0;

	Q.push(now);
	visited[now.r][now.c] = true;
	while (!Q.empty()) {
		now = Q.front();
		Q.pop();
		firstChain++;
		
		for (int i = 0; i < 4; i++) {
			next.r = now.r + dr[i];
			next.c = now.c + dc[i];
			
			if (!visited NEXT && ocean NEXT != 0) {
				Q.push(next);
				visited NEXT = true;
				//cout << next.r << " " << next.c << endl;
			}
		}

	}

	return firstChain;
}

void meltingGlacier() {
	melting.clear();
	melting.resize(R + 2);
	for (int i = 0; i <= R; i++)
		melting[i].resize(C + 2, 0);

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (ocean[i][j] != 0) {
				for (int k = 0; k < 4; k++) {
					if (ocean[i + dr[k]][j + dc[k]] == 0) {
						melting[i][j]++;
						//cout << "1";
					}
					//cout << "2";
				}
				//cout << "3";
			}
			//cout << "4";
		}
		//cout << "5";
	}

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			ocean[i][j] = ocean[i][j] >= melting[i][j] ? ocean[i][j] -= melting[i][j] : 0;

	glacierChain = 0;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (ocean[i][j]) glacierChain++;

	//now.r = 0;
	//now.c = 0;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (ocean[i][j]) {
				now.r = i;
				now.c = j;
				return;
			}
		}
	}
}

int main(void) {

	cin >> R >> C;

	ocean.resize(R + 2);
	for (int i = 0; i <= R; i++)
		ocean[i].resize(C + 2, 0 );

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> ocean[i][j];

	bool chk = false;
	while (true) {
		meltingGlacier();
		ans++;

		/*
		cout << "----------------------------------------" << endl;
		cout << endl;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++)
				cout << ocean[i][j] << " ";
			cout << endl;
		}
		*/
		

		//cout << BFS() << " " << glacierChain << endl;
		if (BFS() != glacierChain) {
			chk = true;
			break;
		}
		if (!ocean[now.r][now.c]) break;
	}

	if (!chk) ans = 0;
	cout << ans;

	return 0;
}

/*
meltingGlacier();
	meltingGlacier();
	cout << glacierChain << endl;


	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			cout << ocean[i][j] << " ";
		cout << endl;
	}
*/

/*
	cout << endl;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++)
				cout << ocean[i][j] << " ";
			cout << endl;
		}
*/

/*
5 5
0 0 0 0 0
0 2 2 2 0
0 2 2 2 0
0 2 2 2 0
0 0 0 0 0
*/
/*
5 5

0 0 0 0 0

0 2 2 2 0

0 2 2 2 0

0 2 2 2 0

0 0 0 0 0
*/

/*
40 20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
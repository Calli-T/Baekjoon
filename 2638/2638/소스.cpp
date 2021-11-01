#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define NOW [now.r][now.c]
#define NEXT [next.r][next.c]

int R, C;
vector<vector<int>> cheese;
vector<vector<int>> surface;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1 ,-1, 0, 0 };
struct cod {
	int r;
	int c;
};

void setCheese();
void showCheese();
void showSurface();
void checkSurface();
void meltCheese();
bool chectLeftCheese();

int main(void) {
	int ans = 0;

	setCheese();

	while (chectLeftCheese()) {
		checkSurface();
		meltCheese();
		ans++;
	}

	cout << ans << '\n';

	return 0;
}

void setCheese() {
	cin >> R >> C;
	cheese.resize(R);
	for (int i = 0; i < R; i++)
		cheese[i].resize(C);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> cheese[i][j];
}
void showCheese() {
	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << cheese[i][j] << " ";
		cout <<  endl;
	}
}
void showSurface() {
	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << surface[i][j] << " ";
		cout << endl;
	}
}
void checkSurface() {
	cod now, next;
	queue<cod> Q;
	vector<vector<bool>> visited;

	surface.clear();
	surface.resize(R);
	for (int i = 0; i < R; i++)
		surface[i].resize(C , 0);
	visited.resize(R);
	for (int i = 0; i < R; i++)
		visited[i].resize(C, false);
	
	now.r = 0;
	now.c = 0;
	Q.push(now);
	visited NOW = true;

	while (!Q.empty()) {
		now = Q.front();
		Q.pop();

		//���˸� ó��
		if (!(cheese NOW)) {
			for (int i = 0; i < 4; i++) {
				next.r = now.r + dr[i];
				next.c = now.c + dc[i];
				
				//���� ó��
				if (next.r == -1 || next.r == R) continue;
				if (next.c == -1 || next.c == C)continue;

				//ġ� ���⿡ �´����� Ƚ�� ī��Ʈ
				if (cheese NEXT) surface NEXT++;
			}
		}

		for (int i = 0; i < 4; i++) {
			next.r = now.r + dr[i];
			next.c = now.c + dc[i];

			//���� ó��
			if (next.r == -1 || next.r == R) continue;
			if (next.c == -1 || next.c == C)continue;

			// queue�� ����, �湮��Ͼ����Ͱ� ġ� �ƴҰ�
			if (!(visited NEXT) && !(cheese NEXT)) {
				Q.push(next);
				visited NEXT = true;
			}
		}
	}
}
void meltCheese() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (surface[i][j] >= 2)
				cheese[i][j] = 0;
}
bool chectLeftCheese() {
	bool ans = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			ans = cheese[i][j] ? true : ans;

	return ans;
}
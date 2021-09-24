#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define NOW [now.r][now.c]
#define NEXT [next.r][next.c]

struct cod {
	int r;
	int c;
};

int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

int main(void) {
	int R, C;
	vector<vector<bool>> map;
	vector<vector<bool>> visited;
	char block;
	int size;
	cod now, next;
	queue<cod> Q;
	int ans = 0;
	int depth = 0;

	cin >> R >> C;
	map.resize(R + 2);
	for (int i = 0; i <= R+1; i++)
		map[i].resize(C + 2, false);

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> block;
			if (block == 'L') map[i][j] = true;
		}
	}

	/*
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	*/
		
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			//방문 배열 리셋
			visited.clear();
			visited.resize(R + 2);
			for (int i = 0; i <= R + 1; i++)
				visited[i].resize(C + 2, false);

			//시작하려는 블럭이 땅블럭이라면
			if (map[i][j]) {
				now.r = i;
				now.c = j;
				depth = 0;

				Q.push(now);
				visited NOW = true;
				//size = 1;
				///* 해당 코드는 범위 오류가 있음
				while (!Q.empty()) {
					size = Q.size();

					for (int i = 0; i < size; i++) {
						now = Q.front();
						Q.pop();
						
						for (int i = 0; i < 4; i++) {
							next.r = now.r + dr[i];
							next.c = now.c + dc[i];

							//간적이없는 육지를 의미한다
							if (!(visited NEXT) && map NEXT) {
								Q.push(next);
								visited NEXT = true;
								//cout << next.r << " " << next.c << endl;
							}
						}
					}
					depth++;
					//cout << endl;
				}
				//*/
			}

			ans = max(ans, depth);

		}
	}

	cout << ans - 1;

	return 0;
}
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define NOW [now.r][now.c]
#define NEXT [next.r][next.c]

struct cod {
	int r;
	int c;
};
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };

int maze(void) {
	int R, C;
	vector<vector<bool>> labyrinth;
	vector<vector<bool>> labyrinth2;
	string line;
	stack<cod> ST;
	cod now, next;
	bool isEnd;

	cod theFarthest;
	int depth;

	cin >> C >> R;

	labyrinth.resize(R);
	for (int i = 0; i < R; i++)
		labyrinth[i].resize(C);

	labyrinth2.resize(R);
	for (int i = 0; i < R; i++)
		labyrinth2[i].resize(C);


	for (int i = 0; i < R; i++) {
		cin >> line;
		for (int j = 0; j < C; j++) {
			if (line[j] == '#') labyrinth[i][j] = true;
			else labyrinth[i][j] = false;
			
			labyrinth2[i][j] = labyrinth[i][j];
		}
	}

	now.r = -1;
	now.c = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!labyrinth[i][j]) {
				now.r = i;
				now.c = j;
				break;
			}
		}
	}
	theFarthest.r = now.r;
	theFarthest.c = now.c;
	if (now.r < 0 || now.c < 0) return 0;

	ST.push(now);
	labyrinth NOW = true;
	depth = 1;
	while (!ST.empty()) {
		now = ST.top();
		isEnd = true;

		for (int i = 0; i < 4; i++) {
			next.r = now.r + dr[i];
			next.c = now.c + dc[i];

			if (!labyrinth NEXT) {
				ST.push(next);
				labyrinth NEXT = true;
				isEnd = false;

				if (depth < ST.size()) {
					theFarthest.r = next.r;
					theFarthest.c = next.c;
					depth = ST.size();
				}
				
				break;
			}
		}

		if (isEnd) ST.pop();
	}

	now.r = theFarthest.r;
	now.c = theFarthest.c;
	ST.push(now);
	depth = 1;
	while (!ST.empty()) {
		now = ST.top();
		isEnd = true;

		for (int i = 0; i < 4; i++) {
			next.r = now.r + dr[i];
			next.c = now.c + dc[i];

			if (!labyrinth2 NEXT) {
				ST.push(next);
				labyrinth2 NEXT = true;
				isEnd = false;

				if (depth < ST.size()) {
					theFarthest.r = next.r;
					theFarthest.c = next.c;
					depth = ST.size();
				}

				break;
			}
		}

		if (isEnd) ST.pop();
	}

	return depth - 1;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> ans;

	cin >> N;
	while (N--) {
		ans.push_back(maze());
	}

	for (int i = 0; i < ans.size(); i++)
		cout << "Maximum rope length is " << ans[i] << "." << endl;
	
	return 0;
}

/*
2
3 3
###
#.#
###
7 6
#######
#.#.###
#.#.###
#.#.#.#
#.....#
#######
*/

/*
for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
		cout << labyrinth[i][j] << " ";
	}
	cout << endl;
}
*/
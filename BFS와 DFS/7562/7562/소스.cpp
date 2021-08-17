#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cod {
	int x;
	int y;
};

int checkmate() {
	int N;
	cod start, end;
	cod now, next;
	vector<vector<bool>> visited;
	int dx[] = { -2,-1,1,2,2,1,-1,-2 };
	int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

	int ans = 0;
	queue<cod> Q;
	bool isEnd = false;
	int size;

	cin >> N;
	cin >> start.x >> start.y;
	cin >> end.x >> end.y;
	
	visited.resize(N + 4);
	for (int i = 0; i < N + 4; i++) {
		visited[i].resize(N + 4, true);
	}
	for (int i = 2; i < N + 2; i++) {
		for (int j = 2; j < N + 2; j++) {
			visited[i][j] = false;
		}
	}


	now.x = start.x + 2;
	now.y = start.y + 2;
	Q.push(now);
	visited[now.x][now.y] = true;
	end.x += 2;
	end.y += 2;
	ans++;
	//cout << end.x << " " << end.y << endl;
	//cout << visited[end.x][end.y] << endl;
	while (!Q.empty()) {
		size = Q.size();
		while(size--){

			now = Q.front();
			Q.pop();

			for (int i = 0; i < 8; i++) {
				next.x = now.x + dx[i];
				next.y = now.y + dy[i];

				if (!visited[next.x][next.y]) {
					Q.push(next);
					visited[next.x][next.y] = true;

					//cout << next.x << " " << next.y << " " << endl;
					
				}
				if (visited[end.x][end.y]) break;
				//cout << "Queue size: " << Q.size() << endl;
			}
		}
		/*
		cout << '\n';
		for (int i = 2; i < N + 2; i++) {
			for (int j = 2; j < N + 2; j++) {
				cout << visited[i][j] << " ";
			}
			cout << endl;
		}*/

		if (visited[end.x][end.y]) break;
		ans++;
	}

	if (start.x + 2 == end.x && start.y + 2 == end.y) return 0;
	else return ans;
}

int main(void) {

	int T;
	vector<int> ans;

	cin >> T;
	while (T--){
		ans.push_back(checkmate());
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}

/*
1
8
0 0
7 0
*/

/*
1
100
0 0
30 50
*/

/*
1
4
0 0
3 3
*/

/*
1
6
0 0
5 5
*/

/*
1
5
0 0
4 4
*/

/*
for (int i = 0; i < N + 4; i++) {
		for (int j = 0; j < N + 4; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
*/
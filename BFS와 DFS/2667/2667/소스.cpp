#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


#define MAX 626
struct cod {
	int x;
	int y;
};

using namespace std;

int BFS(vector<vector<int>>& map, int N, int M, int &min);

int main()  {

	int N;
	string line;
	vector<vector<int>> map;
	int min = 2;
	vector<int> ans;
	int temp;

	cin >> N;
	map.resize(N + 2);
	for (int i = 0; i <= N + 1; i++) {
		map[i].resize(N + 2, 0);
	}

	for (int i = 1; i <= N; i++) {
		cin >> line;
		for (int j = 1; j <= N; j++) {
			map[i][j] = line[j - 1] == '0' ? 0 : 1;
		}
	}

	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			temp = BFS(map, i, j, min);
			if (temp > 0)
				ans.push_back(temp);
		}
	}

	sort(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	for (auto it = ans.begin(); it < ans.end(); it++) {
		cout << *it << "\n";
	}

	return 0;
}

int BFS(vector<vector<int>>& map, int N, int M, int &min) {
	queue<cod> Q;
	cod start, now, next;
	start.x = N;
	start.y = M;
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,-1,1 };
	int ans = 0;

	if (map[N][M] != 1) {
		return ans;
	}

	Q.push(start);
	map[start.x][start.y] = min;

	while (!Q.empty()) {
		now = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			if (map[now.x + dx[i]][now.y + dy[i]] == 1) {
				map[now.x + dx[i]][now.y + dy[i]] = min;
				next.x = now.x + dx[i];
				next.y = now.y + dy[i];
				Q.push(next);
				ans++;
			}
		}
	}

	min++;
	return ans + 1;
}


/*
for (int i = 0; i <= N + 1; i++) {
	for (int j = 0; j <= N + 1; j++) {
		cout << map[i][j] << "\t";
	}
	cout << endl;
}
*/

/*
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			cout << map[i][j] << "\t";
		}
		cout << endl;
	}
	*/

	//cout << endl<<BFS(map, 1, 2, min)<<endl;

/*
for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			cout << map[i][j] << "\t";
		}
		cout << endl;
	}
*/

/*
stack<coordinate> ST;
	coordinate start;
	coordinate now;
	coordinate next;
	int dx[] = { 1, -1, 0 ,0 };
	int dy[] = { 0, 0, -1, 1 };
	bool hasChild;
	int ans = 0;

	start.x = N;
	start.y = M;
	ST.push(start);

	visited[ST.top().x][ST.top().y] = true;

	while (!ST.empty()) {
		now = ST.top();
		ST.pop();
		hasChild = false;

		for (int i = 0; i < 4; i++) {
			if (!visited[now.x + dx[i]][now.y + dy[i]] && map[now.x + dx[i]][now.y + dy[i]] != 0) {
				hasChild = true;
				visited[now.x + dx[i]][now.y + dy[i]] = true;
				next.x = now.x + dx[i];
				next.y = now.y + dy[i];
				ST.push(next);
				ans++;
				break;
			}
		}

		if (!hasChild)
			ST.pop();
	}

	return ans;
*/
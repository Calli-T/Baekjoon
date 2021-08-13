#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cod {
	int x;
	int y;
	int z;
};

int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { -1,1,0,0,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

int main() {
	vector<vector<vector<int>>> box;
	vector<vector<int>> plate;
	int N, M, H;
	cod now, next;
	int ans = 0;
	int size;

	cin >> M >> N >> H;
	plate.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		plate[i].resize(M + 2, 1);
	}
	box.resize(H + 2, plate);

	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> box[k][i][j];
			}
		}
	}

	queue<cod> Q;
	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (box[k][i][j] == 1) {
					now.x = i;
					now.y = j;
					now.z = k;
					Q.push(now);
				}
			}
		}
	}

	while (true) {
		size = Q.size();
		while (size--) {
			now = Q.front();
			Q.pop();

			for (int i = 0; i < 6; i++) {
				if (!box[now.z + dz[i]][now.x + dx[i]][now.y + dy[i]]) {
					next.x = now.x + dx[i];
					next.y = now.y + dy[i];
					next.z = now.z + dz[i];
					box[next.z][next.x][next.y] = 1;
					Q.push(next);
				}
			}
		}

		if (Q.empty()) break;

		ans++;
	}

	for (int k = 1; k < box.size(); k++) {
		for (int i = 1; i < box[k].size(); i++) {
			for (int j = 1; j < box[k][i].size(); j++) {
				if (!box[k][i][j]) ans = -1;
			}
		}
	}

	cout << ans;

	return 0;
}

/*
for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << box[k][i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
*/
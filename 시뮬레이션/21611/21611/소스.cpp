#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cod {
	int r;
	int c;
};

int dr[] = { 0, 0, -1, 1 };
int dc[] = { 1, -1,  0, 0};
vector<int> line(8, -1);
vector<vector<int>> field(14, line);
vector<cod> group;

int ans = 0;

bool BFS(int r, int c) {
	cod now, next;
	queue<cod> Q;
	int color = field[r][c];
	vector<cod> location;

	now.r = r;
	now.c = c;
	Q.push(now);

	while (!Q.empty()) {
		now = Q.front();
		location.push_back(now);
		field[now.r][now.c] = 6;
		Q.pop();
		
		for (int i = 0; i < 4; i++) {
			next.r = now.r + dr[i];
			next.c = now.c + dc[i];

			if (field[next.r][next.c] == color) {
				Q.push(next);
			}
		}
	}

	if (location.size() >= 4) {
		for (int i = 0; i < location.size(); i++)
			group.push_back(location[i]);
		return true;
	}
	else {
		for (int i = 0; i < location.size(); i++) {
			field[location[i].r][location[i].c] = color;
		}
	}
		return false;
}
bool searchChain() {
	bool hasChain = false;

	for (int r = 1; r <= 12; r++) {
		for (int c = 1; c <= 6; c++) {
			if (field[r][c] >= 1 && field[r][c] <= 5)
				hasChain |= BFS(r, c);
		}
	}

	return hasChain;
}
void blowField() {
	for (int i = 0; i < group.size(); i++)
		field[group[i].r][group[i].c] = 0;
	group.clear();
}
void gravity() {
	int temp;
	for (int c = 1; c <= 6; c++) {
		for (int r = 12; r >= 1; r--) {
			temp = r;
			if (field[r][c]) continue;
			else {
				while (field[temp][c] == 0)
					temp--;

				if (field[temp][c] == -1) break;
				else {
					field[r][c] = field[temp][c];
					field[temp][c] = 0;
				}
			}
		}
	}
}

void printField() {
	for (int r = 1; r <= 12; r++) {
		for (int c = 1; c <= 6; c++) {
			cout << field[r][c] << " ";
		}
		cout << endl;
	}
}

void setField() {
	string temp;
	for (int r = 1; r <= 12; r++) {
		cin >> temp;
		for (int c = 1; c <= 6; c++) {
			if (temp[c - 1] == '.')
				field[r][c] = 0;
			else if (temp[c - 1] == 'R')
				field[r][c] = 1;
			else if (temp[c - 1] == 'G')
				field[r][c] = 2;
			else if (temp[c - 1] == 'B')
				field[r][c] = 3;
			else if (temp[c - 1] == 'P')
				field[r][c] = 4;
			else if (temp[c - 1] == 'Y')
				field[r][c] = 5;
		}
	}
}

int main(void) {
	setField();

	while (true) {
		if (!searchChain()) break;
		
		blowField();
		gravity();
		ans++;
		//printField();
	}

	cout << ans << '\n';

	return 0;
}
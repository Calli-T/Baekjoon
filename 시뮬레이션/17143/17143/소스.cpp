#include <iostream>
#include <vector>

using namespace std;

// d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.
int dr[] = { -1, 1, 0 , 0 };
int dc[] = { 0,0,1, -1 };

struct shark {
	int speed;
	int dir;
	int size;
};

struct loc {
	int r;
	int c;
};
vector<loc> list;
vector<vector<vector<shark>>> field;
int R, C;
int num;

void printShark() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (field[i][j].empty()) {
				cout << "0 0 0" << '\t';
			}
			else {
				cout << field[i][j][0].speed << " ";
				cout << field[i][j][0].dir << " ";
				cout << field[i][j][0].size << '\t';
			}
		}
		cout << '\n';
	}
}

void moveShark() {
	vector<loc> after;
	vector<shark> after2;
	loc temp;

	for (int l = 0; l = list.size(); l++) {
		int i = list[l].r;
		int j = list[l].c;

		int nowR = i, nowC = j, nextR, nextC;
		shark now = field[i][j][0];
		field[i][j].clear();

		nextR = nowR;// +dr[now.dir] * now.speed;
		nextC = nowC;// +dc[now.dir] * now.speed;

		if (now.dir == 0 || now.dir == 1) {
			for (int left = 0; left < now.speed % ((R - 1) * 2); left++) {
				if (nextR == 0 && now.dir == 0) {
					now.dir = 1;
				}
				else if (nextR == R - 1 && now.dir == 1) {
					now.dir = 0;
				}

				nextR += dr[now.dir];
			}
		}
		else {
			for (int left = 0; left < now.speed % ((C - 1) * 2); left++) {
				if (nextC == 0 && now.dir == 3) {
					now.dir = 2;
				}
				else if (nextC == C - 1 && now.dir == 2) {
					now.dir = 3;
				}

				nextC += dc[now.dir];
			}
		}

		temp.r = nextR; temp.c = nextC;
		after.push_back(temp);
		after2.push_back(now);
	}

	for (int i = 0; i < after.size(); i++) {
		field[after[i].r][after[i].c].push_back(after2[i]);
	}

	list.clear();
	for (int i = 0; i < after.size(); i++) {
		loc temp;
		temp.r = after[i].r;
		temp.c = after[i].c;
		list.push_back(temp);
	}

	//상어가 한 칸에 한 마리 보다 많이 있는경우
	for (int l = 0; l = list.size(); l++) {
		int i = list[l].r;
		int j = list[l].c;

		if (field[i][j].size() > 1) {
			shark now;
			int max = 0;
			int place = 0;

			for (int k = 0; i < field[i][j].size(); k++) {
				if (max < field[i][j][k].size) {
					max = field[i][j][k].size;
					place = k;
				}
			}

			now = field[i][j][place];
			field[i][j].clear();
			field[i][j].push_back(now);
		}
	}

}

int catchShark(int col) {
	int ans = 0;

	for (int i = 0; i < R; i++) {
		if (!field[i][col].empty()) {
			ans = field[i][col][0].size;
			field[i][col].clear();
			return ans;
		}
	}

	return ans;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<shark> SQ;
	shark temp;
	loc tempLoc;
	int r, c;

	cin >> R >> C >> num;
	field.resize(R);
	for (int i = 0; i < R; i++)
		field[i].resize(C, SQ);

	for (int i = 0; i < num; i++) {
		cin >> r >> c >> temp.speed >> temp.dir >> temp.size;
		temp.dir--;
		field[r - 1][c - 1].push_back(temp);
		tempLoc.r = r;
		tempLoc.c = c;
		list.push_back(tempLoc);
	}
	
	int ans = 0;
	for (int i = 0; i < C; i++) {
		ans += catchShark(i);
		moveShark();
	}
	cout << ans;

	return 0;
}
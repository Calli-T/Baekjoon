#include <iostream>
#include <vector>

using namespace std;

#define ORDER order[i] / 4][order[i] % 4

struct fish {
	int dir; // 방향 1부터 순서대로 ↑, ↖, ←, ↙, ↓, ↘, →, ↗
	int number; // 0(빈 칸) 1~16(고기) 17(상어)
};

vector<vector<fish>> ocean;
vector<bool> alive(17, true);

struct loc {
	int r;
	int c;
};

int dr[] = { -1 , -1, 0 , 1, 1, 1, 0, -1 };
int dc[] = { 0, -1, -1 , -1 , 0, 1, 1, 1 };

void drawOcean() {
	//char arrow[] = { '↑', '↖', '←', '↙', '↓', '↘','→', '↗' };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << ocean[i][j].number << ": ";// arrow[ocean[i][j].dir] << " ";
			cout << ocean[i][j].dir << "\t";
		}
		cout << endl;
	}

}

void moveFish() {
	//cout << endl;
	for (int i = 1; i <= 16; i++) {
		if (!alive[i]) continue;
		//cout << i << endl;
		//다음 순서 위치찾기, 위치배열로 개선가능?
		loc now;
		loc next;
		fish temp1, temp2;
		for (int j = 0; j < 16; j++) {
			if (ocean[j / 4][j % 4].number == i) {
				now.r = j / 4; now.c = j % 4;
				//cout << now.r << " " << now.c << endl;
				break;
			}
		}

		//방향개선
		temp1 = ocean[now.r][now.c];
		while (true) {
			next.r = now.r + dr[temp1.dir];
			next.c = now.c + dc[temp1.dir];
			if (next.r >= 0 && next.r <= 3 && next.c >= 0 && next.c <= 3) {
				
				temp2 = ocean[next.r][next.c];
				if (temp2.number != 17) break;
			}
			temp1.dir = (temp1.dir + 1) % 8;
		}

		//교체
		ocean[next.r][next.c] = temp1;
		ocean[now.r][now.c] = temp2;
		
		//if (i == 6)
			//break;
	}

	/*
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << ocean[i][j].number << " ";
		}
		cout << endl;
	}
	*/
}

int bite() {
	loc now;
	loc prev, next;
	fish shark;
	int fishNum = 0;

	//상어 찾기
	for (int i = 0; i < 16; i++) {
		if (ocean[i / 4][i % 4].number == 17) {
			now.r = i / 4; now.c = i % 4;
			//cout << now.r << " " << now.c << endl;
			break;
		}
	}
	shark = ocean[now.r][now.c];
	
	//cout << "무야호" << endl;
	//조타
	while (true) {
		next.r = now.r + dr[shark.dir];
		next.c = now.c + dc[shark.dir];

		if (next.r >= 0 && next.r <= 3 && next.c >= 0 && next.c <= 3) break;
		else {
			next.r -= dr[shark.dir];
			next.c -= dc[shark.dir];
			shark.dir = (shark.dir + 1) % 8;
		}
	}
	//cout << "방향은: " << shark.dir << endl;
	//무빙
	next.r = now.r; next.c = now.c;
	while(true){
		next.r += dr[shark.dir];
		next.c += dc[shark.dir];

		//cout << next.r << " " << next.c << endl;
		if (!(next.r >= 0 && next.r <= 3 && next.c >= 0 && next.c <= 3)) break;

		prev.r = next.r;
		prev.c = next.c;
	}
	//cout << "무야호" << endl;

	ocean[now.r][now.c].number = 0;
	//cout << prev.r << " " << prev.c << endl;
	fishNum = ocean[prev.r][prev.c].number;
	alive[fishNum] = false;
	//cout << "무야호" << endl;
	ocean[prev.r][prev.c].number = 17;

	//while (true) {
	

	//drawOcean();

	return fishNum;
}

int main(void) {
	fish temp;
	int ans = 0;

	ocean.resize(4);
	for (int i = 0; i < ocean.size(); i++)
		ocean[i].resize(4);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> temp.number >> temp.dir;
			temp.dir -= 1;
			ocean[i][j] = temp;
		}
	}

	//상어
	alive[ocean[0][0].number] = false;
	ocean[0][0].number = 17;

	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << ocean[i][j].number << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << ocean[i][j].dir << " ";
		}
		cout << endl;
	}*/
	while (true) {
		moveFish();
		cout << endl;
		drawOcean();
		int num = bite();
		cout << num << endl;
		cout << endl;
		drawOcean();
		if (num == 0) break;
		ans += num;
		
		cout << "-----------------------------------";
	}

	cout << ans;

	return 0;
}

/*
for (int count = 0; count < 7; count++) {
		movement = 0;
		next.r = now.r; next.c = now.c;
		while (next.r >= 0 && next.r<=3 && next.c >= 0 && next.c <= 3) {
			prev = next;
			next.r += dr[shark.dir];
			next.c += dc[shark.dir];
			movement++;

			//cout << movement << endl;
		}

		if (movement != 0) {
			fishNum = ocean[prev.r][prev.c].number;
			alive[fishNum] = false;
			ocean[prev.r][prev.c].number = 17;
			ocean[now.r][now.c].number = 0;
			break;
		}
		else
			shark.dir = (shark.dir + 1) % 8;
	}
*/
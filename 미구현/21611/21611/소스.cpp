#include <iostream>
#include <vector>

using namespace std;

int N, M;
int dir, dist; // 방향, 거리;
vector<vector<int>> numberBoard;
vector<int> realBoard;
vector<int> range; //피격범위
int dc[] = { 1, 0, -1 ,  0 };
int dr[] = { 0 , 1, 0, -1 };
int temp;
int r = 1; int c = 1;
int blastCount[3] = { 0 };

void printBoard() {
	/*
	cout << endl;
	for (int i = 1; i < realBoard.size(); i++)
		cout << realBoard[i] << " ";
	*/
}
void blizzard() {
	for (auto it = range.rbegin(); it != range.rend(); it++) {
		int iter = *it;
		realBoard.erase(realBoard.begin()+iter);
		realBoard.push_back(0);
	}

	printBoard();
}
void blast() {
	int index = 1;
	int continuity;
	int now;
	vector<int> memory;
	vector<int> count;

	while (true) {
		count.clear();
		memory.clear();
		index = 1;

		while (true) {
			now = realBoard[index];
			continuity = 1;

			while (now == realBoard[index + continuity] && index + continuity < N * N - 1) {
				continuity++;
			}

			if (index + continuity >= N * N - 1) break;

			if (continuity >= 4) {
				memory.push_back(index);
				count.push_back(continuity);
			}

			index += continuity;
		}
		if(!count.size()) break;
		for (int i = memory.size() - 1; i >= 0; i--) {
			blastCount[realBoard[memory[i]] - 1] += count[i];
			realBoard.erase(realBoard.begin() + memory[i], realBoard.begin() + memory[i] + count[i]);
			for (int j = 0; j < count[i]; j++)
				realBoard.push_back(0);
		}

	}

	printBoard();
}
void metamorphosis() {
	vector<int> memory;
	vector<int> count;
	int index = 1;
	int now;
	int continuity;

	//cout << endl;
	while (index<N*N - 1) {
		//cout << index << " ";
		now = realBoard[index];
		for(continuity = 0; (index+continuity) < N*N - 1; continuity++){
			if (now != realBoard[index + continuity]) break;	
		}
		count.push_back(continuity);
		memory.push_back(realBoard[index]);
		index += continuity;
	}

	realBoard.clear();
	for (int i = 0; i < count.size(); i++) {
		if (!memory[i]) continue;
		realBoard.push_back(count[i]);
		realBoard.push_back(memory[i]);
	}
	while (realBoard.size() < N * N) realBoard.push_back(0);

	printBoard();
}

int main(void) {
	
	cin >> N >> M;
	temp = N * N;
	numberBoard.resize(N + 2);
	for (int i = 0; i < numberBoard.size(); i++)
		numberBoard[i].resize(N + 2, -1);
	realBoard.resize(N * N);
	
	for (int i = N - 1; i >= -1; i -= 2 ) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < i; k++) {
				temp--;
				numberBoard[r][c] = temp;
				r = r + dr[j]; c = c + dc[j];
			}
		}
		r++;
		c++;
	}
	numberBoard[(N+1)/2][(N + 1) / 2] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			realBoard[numberBoard[i][j]] = temp;
		}
	}

	//시전
	for (int i = 0; i < M; i++) {
		//방향제어
		cin >> dir >> dist;

		dir = (dir == 1) ? 3 : (dir == 2) ? 1 : (dir == 3) ? 2 : 0;
		r = (N + 1) / 2; c = r;
		//조준, 사정거리
		range.clear();
		for (int i = 0; i < dist; i++) {
			r += dr[dir]; c += dc[dir];
			range.push_back(numberBoard[r][c]);
			//cout << numberBoard[r][c] << endl;
		}

		// 시전
		blizzard();
		// 폭발
		blast();
		// 변형
		metamorphosis();

	}

	cout << endl;
	cout << 1 * blastCount[0] + 2 * blastCount[1] + 3 * blastCount[2] << endl;

	return 0;
}

/*
for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << numberBoard[i][j] << '\t';
		}
		cout << endl;
	}
*/

/*
	for (int i = 1; i < N * N; i++)
		cout << realBoard[i] << " ";
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define NOW [now.r][now.c]
#define NEXT [next.r][next.c]

int dr[] = { 1, -1,  0 , 0 };
int dc[] = { 0, 0 , -1, 1 };

struct loc {
	int r;
	int c;

	bool operator()(loc a, loc b) {
		if (a.r == b.r)
			return a.c > b.c;
		else
			return a.r > b.r;
	}
};

int N;
vector<vector<int>> ocean;
vector<vector<bool>> visited;

int state = 2; //덩치
loc BS; //babyshark
int killCount = 0; //성장기록
int timer = 0; //이동거리&시간 통합기록



void resetVisited() {
	visited.clear();
	visited.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		visited[i].resize(N + 2, false);
}

vector<loc> getFish(void) {
	vector<loc> list;
	resetVisited();
	queue<loc> Q;

	loc next;
	int size = 0;
	int depth = 0;
	Q.push(BS);
	visited[BS.r][BS.c] = true;
	while (!Q.empty()) {
		for (int sz = 0; sz < size; sz++) {
			loc now = Q.front();
			Q.pop();

			for (int i = 0; i < 4; i++) {
				next.r = now.r + dr[i];
				next.c = now.c + dc[i];

				if (!(visited NEXT) && ocean NEXT <= state && ocean NEXT != -1) {
					visited NEXT = true;
					Q.push(next);

					if (ocean NEXT > 0 && ocean NEXT < state)
						list.push_back(next);
				}
			}
		}
		
		//아무것도 못찾았으면 크기 다시 잡고 반복, 아니면 정지후 반환
		if (list.empty()) {
			size = Q.size();
		}
		else {
			timer += depth;
			break;
		}

		depth++;
	}
	
	return list;
}

int main(void) {

	//reset
	cin >> N;
	ocean.resize(N + 2);
	for (int i = 0; i < N + 2; i++)
		ocean[i].resize(N + 2, -1);

	//set
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> ocean[i][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (ocean[i][j] == 9) {
				BS.r = i;
				BS.c = j;
				break;
			}
		}
		if (BS.r == i)  break;
	}
	
	
	/*vector<loc> temp= getFish();
	for (int i = 0; i < temp.size(); i++)
		cout << temp[i].r << " " << temp[i].c << endl;
	cout << timer;*/

	while (true) {
		loc target;
		vector<loc> list = getFish();
		if (list.empty()) break;
		
		if (list.size() > 1) {
			priority_queue<loc, vector<loc>, loc> sf;
			for (int i = 0; i < list.size(); i++)
				sf.push(list[i]);

			target = sf.top();
		}
		else
			target = list[0];

		// 식사
		ocean[target.r][target.c] = 9;
		ocean[BS.r][BS.c] = 0;
		BS.r = target.r;
		BS.c = target.c;
		killCount++;

		//성장
		if (killCount == state) {
			killCount = 0;
			state++;
		}
		//cout << sf.top().r << " " << sf.top().c << endl;
		/*cout << endl;
		cout << target.r << " " << target.c << " ";
		cout << timer << " " << state << " ";
		cout << killCount << endl;*/

		//break;
	}

	cout << timer;

	return 0;
}

// BFS를 응용하여 타겟팅 함수를 제작한다
// 타게팅은 1회에 한 마리를 고른다
// BFS를 돌릴 때 size를 활용하고
// 동일거리일 때 구분하기 위해, 1차원 배열에 넣어두고 구분한다
// BFS의 인자에는 아기상어 위치와 크기를 보냄

/*
4
4 3 3 1
0 3 0 2
0 0 9 0
1 2 3 4
*/
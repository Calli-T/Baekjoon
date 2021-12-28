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

int state = 2; //��ġ
loc BS; //babyshark
int killCount = 0; //������
int timer = 0; //�̵��Ÿ�&�ð� ���ձ��



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
		
		//�ƹ��͵� ��ã������ ũ�� �ٽ� ��� �ݺ�, �ƴϸ� ������ ��ȯ
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

		// �Ļ�
		ocean[target.r][target.c] = 9;
		ocean[BS.r][BS.c] = 0;
		BS.r = target.r;
		BS.c = target.c;
		killCount++;

		//����
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

// BFS�� �����Ͽ� Ÿ���� �Լ��� �����Ѵ�
// Ÿ������ 1ȸ�� �� ������ ����
// BFS�� ���� �� size�� Ȱ���ϰ�
// ���ϰŸ��� �� �����ϱ� ����, 1���� �迭�� �־�ΰ� �����Ѵ�
// BFS�� ���ڿ��� �Ʊ��� ��ġ�� ũ�⸦ ����

/*
4
4 3 3 1
0 3 0 2
0 0 9 0
1 2 3 4
*/
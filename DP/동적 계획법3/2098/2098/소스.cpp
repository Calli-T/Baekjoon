#include <iostream>
#include <vector>
#include <bitset>

#define INF 1e9

using namespace std;

int N;
vector<vector<int>> cost; //비용
vector<vector<int>> DP;

//DP[i][j]는 i번 도시에 도착했을 때 기준 방문도시가 j일 때 최소비용을 의미한다

//인자 2개는 각각 현재 있는 도시와 방문한 현황이다
int DFS(int cur, int state) {
	int& now = DP[cur][state];

	if (state == (1 << N) - 1) {
		if (cost[cur][0] == 0)return INF;
		else return cost[cur][0];
	}
	if (now != -1) return now;

	int ans = INF;
	for (int i = 0; i < N; i++) {
		if (!(state & (1 << i))) {
			if(cost[cur][i] == 0 ) continue;
			ans = min(ans, DFS(i, state | (1 << i)) + cost[cur][i]);
		}
	}
	return now = ans;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cost.resize(N);
	for (int i = 0; i < N; i++)
		cost[i].resize(N);
	DP.resize(N + 1);
	for (int i = 0; i <= N; i++)
		DP[i].resize(1 << N, -1);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> cost[i][j];

	cout << DFS(0, 1);

	return 0;
}

/*
	cout << endl;
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < (1 << N); j++) {
			if (DP[i][j] == INF)
				cout << "INF" << " ";
			else
				cout <<DP[i][j] << " ";
		}
		cout << endl;
	}
*/
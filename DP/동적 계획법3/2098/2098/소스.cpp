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

	//모든 도시를 방문했을 경우
	if (state == (1 << N) - 1) {
		//원래 도시로 돌아가는 길이없다면 INF값을 return하여
		//ans가 줄어드는 일이 없도로갛ㄴ다
		if (cost[cur][0] == 0)return INF;
		else return cost[cur][0]; // 길이 있다면 원래의 도시로 돌아온다
	}
	//DP의 초기화를 -1로 했으므로 기존에 계산했으면 -1이 아니게된다. 이를 return
	if (now != -1) return now;

	//무한에서 부터 줄여나간다
	int ans = INF;
	//각 도시들에 대해
	for (int i = 0; i < N; i++) {
		//해당 비트마스크 자리가 0이라면, 즉 방문한 적이 없다면
		if (!(state & (1 << i))) {
			// 만약 길이없다면 무시
			if(cost[cur][i] == 0 ) continue;
			ans = min(ans, DFS(i, state | (1 << i)) + cost[cur][i]);
			//그렇지 않을경우 최소값을 계산 ans의 비교대상은
			//현재 도시에서 해당도시로 가는비용에 해당 도시에서 남은 순회를 도는 비용
		}
	}

	//최소화된 ans를 return
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
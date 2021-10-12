#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	vector<int> memory;
	vector<int> cost;
	int temp;
	int ans = 0;

	vector<vector<int>> DP;

	cin >> N >> M;
	memory.push_back(0);
	cost.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		memory.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		cost.push_back(temp);
	}
	
	temp = 0;
	for (int i = 1; i <= N; i++)
		temp += cost[i];

	DP.resize(N + 1);
	for (int i = 0; i <= N; i++)
		DP[i].resize(temp + 1, 0);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= temp; j++) {
			if(j - cost[i]>=0)
				DP[i][j] = max(DP[i - 1][j], DP[i-1][j-cost[i]] + memory[i]);
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}

	for (int i = 1; i <= temp; i++) {
		for (int j = 1; j <= N; j++) {
			ans = max(ans, DP[j][i]);
		}
		if (ans >= M) {
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}

// 메모리가 10^7이므로 메모리를 훑어볼 수는 없다
// 무게가 100까지, N이 100까지이므로 표크기는 최대 101*101개이며
// 따라서 여전히 무게를 이용한 DP를 적용함이 옳다


// 냅색이란, 물건의 무게와 가치를 정해놓고
// 정해진 무게를 넘지않는선에서
// 최대한의 가치를 챙기는일

// 역으로 정해진 가치보다 높은 선에서
// 최소한의 무게를 가져가는 방법이 있는가?

// 냅색을 할 때는 2차원 벡터로
// row는 무게별 가치를, column은 물건을 의미했다
// 해당 행에서는 물건을 집을지 말지를 고민했다

// 역으로, 모든 물건(7579에서는 메모리)을 다 들고있는곳에서 부터 시작해서
// 해당 물건을 뺄지말지를 역으로 고민해야한다

// 그러하다면 DP[0][0]은 모든 무게를 합산한 결과에서부터 시작한다

/*
for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= temp; j++) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
*/
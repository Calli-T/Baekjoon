#include <vector>
#include <iostream>

#define INF 1000001

using namespace std;

int main(void) {
	vector<vector<int>> cost;
	vector<int> house(3);
	vector<vector<int>> DP;
	int N;
	int ans = INF;


	cin >> N;
	cost.resize(N, house);
	DP.resize(N, house);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];

	for (int color = 0; color < 3; color++) {
		//해당하는 색을 제외하고 INF로 하게 하여, 색을 고정하는 작업
		for (int i = 0; i < 3; i++) {
			if (color == i) DP[0][i] = cost[0][i];
			else DP[0][i] = INF;
		}
		
		//첫 색이 고정되어있을 때 색을 갱신하는 작업
		for (int i = 1; i < N; i++) {
			DP[i][0] = cost[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
			DP[i][1] = cost[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
			DP[i][2] = cost[i][2] + min(DP[i - 1][1], DP[i - 1][0]);
		}

		//3가지의 결과중 끝색이 첫 색과 같지 않은 선에서 최솟값을 구하는작업
		for (int i = 0; i < 3; i++) {
			if (i == color) continue;
			ans = min(ans, DP[N - 1][i]);
		}
	}

	cout << ans << '\n';

	return 0;
}

/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}
*/

/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cout << DP[i][j] << "\t";
		}
		cout << endl;
	}
*/
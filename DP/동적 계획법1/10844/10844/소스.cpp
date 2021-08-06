#include <vector>
#include <iostream>

using namespace std;

int main(void) {

	int N;
	vector<vector<long long>> DP;
	vector<long long> line;
	
	cin >> N;
	line.resize(N, 0);
	DP.resize(10, line);
	for (int i = 1; i < 10; i++) {
		DP[i][0] = 1;
	}
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < 10; i++) {
			if (i == 0) {
				//for (int j = 0; j < N - 1; j++) {
				DP[i + 1][j + 1] += DP[i][j];
				DP[i + 1][j + 1] %= 1000000000;
				//}
			}
			else if (i >= 1 && i <= 8) {
				//for (int j = 0; j < N - 1; j++) {
					//cout << DP[i][j] << " ";
				DP[i + 1][j + 1] += DP[i][j];
				DP[i - 1][j + 1] += DP[i][j];

				DP[i + 1][j + 1] %= 1000000000;
				DP[i - 1][j + 1] %= 1000000000;
				//}
				//cout << endl;
			}
			else {
				//for (int j = 0; j < N - 1; j++) {
				DP[i - 1][j + 1] += DP[i][j];
				DP[i - 1][j + 1] %= 1000000000;
				//}
			}
		}
	}
	//cout << endl;
	
	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < N; j++) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}*/
	
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += DP[i][N - 1];
	}
	
	cout << ans % 1000000000;

	return 0;
}

// 아이디어: 계단수가의 정의에서, 인접한 모든 자리수의 차리가 1이라면 다음 단계로
// 넘어갈 때 하나 더하거나, 하나 더해질것이다
// 해당 자리에 해당 수를 넣는 계단수의 개수를 넣고, 맨 끝열을 합산하자
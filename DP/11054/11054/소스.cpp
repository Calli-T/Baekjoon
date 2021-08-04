#include <vector>
#include <iostream>

using namespace std;

int main() {
	int N;
	int temp;
	vector<int> SEQ;
	vector<int> DP;
	vector<int> DP_R;
	int ans = 1;

	cin >> N;
	DP.resize(N, 1);
	DP_R.resize(N, 1);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		SEQ.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (SEQ[i] > SEQ[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (SEQ[i] > SEQ[j]) {
				DP_R[i] = max(DP_R[i], DP_R[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		ans = max(ans, DP[i] + DP_R[i] - 1);
	}
	cout << ans;

	return 0;
}

/*
for (int i = 0; i < N; i++) {
		cout << SEQ[i] << " ";
	}
	cout << endl;
*/

/*

	for (int i = 0; i < N; i++) {
		cout << DP[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		cout << DP_R[i] << " ";
	}
	cout << endl;

*/

/*
7
1 2 4 3 2 4 1
*/

/*
4
10, 20, 30, 40
*/

//틀린이유
// 역방향 LIS를 구할 때 i>0으로 해놨는데
// 실제로는  i >= 0;로해야함
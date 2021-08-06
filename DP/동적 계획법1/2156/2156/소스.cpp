#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	vector<int> wine;
	vector<vector<int>> DP;
	int n;
	int temp;
	int ans = 0;

	cin >> n;
	wine.resize(n, 0);
	DP.resize(2, wine); //DP[0][i]는 i+1번째 위치에서 연속 1개일때의 최대, DP[1][i]는 i+1번째 위치에서 연속 2개일때의 최대
	for (int i = 0; i < n; i++) {
		cin >> temp;
		wine[i] = temp;
	}

	if (n == 1) {
		cout << wine[0];
	}
	else if (n == 2) {
		cout << wine[0] + wine[1];
	}
	else if (n == 3) {
		cout << max(max(wine[0] + wine[1], wine[0] + wine[2]), wine[1] + wine[2]);
	}
	else {
		DP[0][0] = wine[0]; // 1칸뛰기 초기
		DP[0][1] = wine[1]; // 2칸뛰기 초기
		DP[0][2] = wine[0] + wine[2]; // 연속 1개 마심, 문제는 실제로 시작위치에서는 3칸뛰기 불가
		DP[1][1] = wine[0] + wine[1]; // 연속 2개 마심, 1칸뛰기로만
		DP[1][2] = wine[1] + wine[2]; // 연속 2개 마심, 2칸뛰기 + 1칸뛰기

		for (int i = 3; i < n; i++) {
			// 2칸 뛰기, 3칸 뛰기를 통해서만 연속횟수를 1로 리셋가능, 이전의 최대값에서 해당위치 포도주를 더함
			DP[0][i] = max(max(max(DP[0][i - 3], DP[0][i - 2]), DP[1][i - 2]), DP[1][i - 3]) + wine[i];
			DP[1][i] = DP[0][i - 1] + wine[i]; // 1개연속인 상태의 포도주 최대치 + 해당위치 포도주
		}

		for (int i = 0; i < n; i++) {
			ans = max(ans, max(DP[0][i], DP[1][i]));
		}

		cout << ans;

	}	

	return 0;
}

/*
for (int i = 0; i < n; i++) {
		cout << wine[i] << endl;
	}
*/

/*
for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
*/

// 계단과 비슷한가?
// 살짝 다른게, 계단은 최대 2칸뛰기만 가능하고 여긴 그런게 없다
// 3칸뛰기는 유효한가? 사이 2개를 놓쳐도 더 마실 수 있다면 유효하다.
// 4칸뛰기는 유효한가? 사이 3개를 놓친다면, 반드시 3개중 가운데 포도주를 시음하는것이, 더 많이 마실 수 있는 길이다. 유효하지않다
// 따라서 1, 2, 3칸을 한 번에 오를 수 있는 계단 문제와 같다
// 3칸 뛰기는 시작할 때 한 칸을 남기는것은 불가능하다

/*6
100
400
2
1
4
200
*/

/*
3
10
3
10
*/
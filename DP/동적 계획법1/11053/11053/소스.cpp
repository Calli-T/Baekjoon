#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<int> DP;
	vector<int> SEQ; //Seqeunce
	int N;
	int temp;
	int ans = 1;

	cin >> N;
	DP.resize(N + 1, 1);
	SEQ.resize(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		SEQ[i] = temp;
	}

	for (int i = 1; i <= N; i++) {
		//if (ans >= N - i + 1) break;

		for (int j = 1; j <= i; j++) {
			if (SEQ[i] > SEQ[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}

		ans = max(DP[i], ans);
	}

	cout << ans;

	return 0;
}

// 아이디어 dp[i] = i번째 원소를 마지막으로 하는 LIS, 마지막 원소가 필연적으로 제일크다
// 1~i-1의 값에서, 해당 SEQ의 값이 SEQ[i]보다 작다면, i번째 원소가 가장 큰(마지막인) 증가하는 부분 수열 제작가능
// 따라서 dp[i]는 dp[j](1<= j <= i-1) + 1 중에서 제일 큰 값


/*
for (int i = 1; i <= N; i++) {
		cout << SEQ[i] << " ";
	}
	cout << endl;
*/

/*
20

322 831 212 232 545 698 260 265 324 215 701 75 156 605 851 993 425 887 691 593
*/
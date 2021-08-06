#include <vector>
#include <iostream>

using namespace std;

int main(void) {

	int N, K;
	vector<int> DP;
	vector<int> w;//weight;
	vector<int> v;//value;
	int temp1, temp2;

	cin >> N >> K;
	DP.resize(K + 1, 0);
	w.push_back(0);
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		w.push_back(temp1);
		v.push_back(temp2);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= 1; j--) {
			if (w[i] <= j) {
				DP[j] = max(DP[j], DP[j - w[i]] + v[i]);
			}
		}
	}

	cout << DP[K];
	
	return 0;
}

/*
#include <vector>
#include <iostream>

using namespace std;

int main(void) {

	int N, K;
	vector<vector<int>> DP;
	vector<int> w;//weight;
	vector<int> v;//value;
	int temp1, temp2;

	cin >> N >> K;
	DP.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		DP[i].resize(K + 1, 0);
	}
	w.push_back(0);
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		w.push_back(temp1);
		v.push_back(temp2);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - w[i] >= 0) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << DP[N][K];
	
	return 0;
}
*/

/*
for (int i = 0; i <= N; i++) {
	for (int j = 0; j <= K; j++) {
		cout << DP[i][j] << " ";
	}
	cout << endl;
}
*/

// 물품의 수 N, 무게 K면
// N+1행, K+1열의 배열을 만들고
// 무게가 0일 때나, 0번째 물품을 고려할 때는 전부0으로 처리한뒤(계산편의상)
// dp[i][j]의 정의는 처음부터 i번째까지의 물품을 보고
// 배낭의 용량이 j여쓸 때 배낭에 들어간 물건의 
// 가치합의 최대값
// 각 칸에는 i-1번째 물품을 봤을 까지의 최대 가치합과
// i-1물품 기준 현재 최대 무게 - 이번 보석의 무게
// 일 때의 최대 가치합+이번보석의 가치 중 더 큰
// 값이 저장될 것이다

// 보석을 하나씩 살펴보면서
// 해당 보석이 들어갈 무게가 되는지
// 배낭 용량이 무게보다 크다면
// (기존의 배낭 용량 - 지금 보석무게)인 배낭의 가치 + 지금 보석의 가치와
// 기존의 배낭의 가치를 비교해서 더 큰쪽으로 넣어준다

// 최적화된 알고리즘에서는 기존의 2차원 배열을 사용하지 않고
// 무게가 무거운쪽의 배낭부터 채워보는데, 채울 때
// 아까 생각했던 더가벼운배낭+지금보석가치와 비교해보는
// 과정을 거치면된다
// 이 때 실수로 보석무게를 빼느라 음수로 가선 안된다

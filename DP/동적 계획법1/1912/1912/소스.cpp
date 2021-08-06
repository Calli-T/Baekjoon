#include <vector>
#include <iostream>

using namespace std;

int main(void){

	int N;
	vector<int> DP;
	vector<int> number;
	int ans =  -100000001;

	cin >> N;
	DP.resize(N + 1, 0);
	number.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> number[i];
	}

	for (int i = 1; i <= N; i++) {
	
		if (DP[i - 1] + number[i] > number[i]) {
			DP[i] = DP[i - 1] + number[i];
		}
		else {
			
			DP[i] = number[i];
		}
		ans = max(ans, DP[i]);

	}
	
	cout << ans;

	return 0;
}

// 해당값과 이전까지의 합을 더해
// 해당값보다만 크면넘긴다
// 아니면 해당값으로 리셋
// 그 때 그 때의 최고값은 어차피 DP안에 기록되어있다
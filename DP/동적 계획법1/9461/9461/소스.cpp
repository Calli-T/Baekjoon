#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<long long> DP(101, 1);
	vector<int> N;
	int T;
	int temp;

	DP[4] = 2;
	DP[5] = 2;

	for (int i = 6; i <= 100; i++) {
		DP[i] = DP[i - 1] + DP[i - 5];
	}
	cin >> T;
	while (T--) {
		cin >> temp;
		N.push_back(temp);
	}
	for (int i = 0; i < N.size(); i++) {
		cout << DP[N[i]] << "\n";
	}

	return 0;
}
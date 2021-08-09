#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

	int N;
	int ans = 0;
	vector<int> withdrawal;
	int temp;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		withdrawal.push_back(temp);
	}

	sort(withdrawal.begin(), withdrawal.end());

	for (int i = 0; i < N; i++) {
		ans += (N - i) * withdrawal[i];
	}

	cout << ans;

	return 0;
}
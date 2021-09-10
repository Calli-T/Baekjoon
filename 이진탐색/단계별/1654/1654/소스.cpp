#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int K, N;
	int temp;
	vector<int> lan;
	long long low, high, mid;
	long long ans = 0;

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		lan.push_back(temp);
	}
	//sort(lan.begin(), lan.end());
	
	low = 1;
	high = 2147483647;
	while (low <= high) {
		mid = (low + high) / 2;
		temp = 0;

		for (int i = 0; i < K; i++)
			temp += lan[i] / mid;
		
		if (temp <  N) {
			high = mid - 1;
		}
		else {
			ans = max(ans, mid);
			low = mid + 1;
		}
	}

	cout << ans << endl;

	return 0;
}

#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	long long low, high, mid;
	long long temp;
	vector<int> tree;
	int ans = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		tree.push_back(temp);
	}

	low = 0;
	high = 1000000000;
	while (low <= high) {
		mid = (low + high) / 2;
		temp = 0;

		for (int i = N - 1; i >= 0; i--)
			temp += tree[i] - mid > 0 ? tree[i] - mid : 0;

		if (temp < M)
			high = mid - 1;
		else {
			if (mid > ans) ans = mid;
			low = mid + 1;
		}

	}

	cout << ans;

	return 0;
}
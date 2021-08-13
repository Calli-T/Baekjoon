#include <iostream>
#include <vector>

#define INF 1000000001

using namespace std;

int main() {

	int N;
	vector<vector<long long>> city;
	vector<long long> value(2, 0);
	long long ans = 0;
	long long MIN = INF;

	cin >> N;
	city.resize(N, value);
	for (int i = 0; i < N - 1; i++) {
		cin >> city[i][0];
	}
	for (int i = 0; i < N; i++) {
		cin >> city[i][1];
	}

	for (int i = 0; i < city.size(); i++) {
		MIN = min(MIN, city[i][1]);
		ans += MIN * city[i][0];
	}

	cout << ans;

	return 0;
}
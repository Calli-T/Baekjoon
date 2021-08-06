#include <vector>
#include <iostream>

using namespace std;

int main() {

	int N;
	int K;
	vector<int> v;//value;
	int temp;
	int ans = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = v.size()- 1; K > 0; ) {
		if (v[i] <= K) {
			K -= v[i];
			ans++;
		}
		else {
			i--;
		}
	}

	cout << ans;
	return 0;
}
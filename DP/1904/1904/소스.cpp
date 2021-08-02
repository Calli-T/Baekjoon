#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	vector<int> ans(1000001, -1);

	cin >> N;
	
	ans[1] = 1;
	ans[2] = 2;
	if (N > 2) {
		for (int i = 3; i <= N; i++) {
			ans[i] = ans[i - 1] + ans[i - 2];
			ans[i] %= 15746;
		}
	}
	
	cout << ans[N];

	return 0;
}

//return할 때마다 오버플로우를 생각해야한다
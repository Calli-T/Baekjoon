#include <iostream>
#include <vector>

#define INF 1000001

using namespace std;

int main(void) {
	int N;
	vector<int> DP;
	
	cin >> N;
	DP.resize(N + 1, INF);
	DP[N] = 0;

	while (N > 1) {
		if (N % 3 == 0) {

			if (DP[N / 3] > (DP[N] + 1)) {
				DP[N / 3] = DP[N] + 1;

			}
		}
		if (N % 2 == 0) {
			if (DP[N / 2] > (DP[N] + 1)) {
				DP[N / 2] = (DP[N] + 1);

			}
		}
		if (N > 1) {
			if (DP[N - 1] > DP[N] + 1) {
				DP[N - 1] = DP[N] + 1;
			}
		}

		N--;
	}
	cout << DP[1];

	return 0;
}
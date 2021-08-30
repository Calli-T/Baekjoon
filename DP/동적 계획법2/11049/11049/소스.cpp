#include <iostream>
#include <vector>

#define INF 2147483647

using namespace std;

struct matrix {
	int r;
	int c;
};

int main(void) {
	int N;
	int temp1, temp2;
	matrix temp3;
	temp3.r = 0;
	temp3.c = 0;
	vector<matrix> arr;
	vector<vector<int>> DP;

	cin >> N;
	arr.push_back(temp3);
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		temp3.r = temp1;
		temp3.c = temp2;
		arr.push_back(temp3);
	}

	DP.resize(N + 1);
	for (int i = 0; i < N + 1; i++)
		DP[i].resize(N + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			DP[j][i + j] = INF;

			for (int k = j; k < i + j; k++) {
				DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + arr[j].r * arr[k].c * arr[i + j].c);
			}
		}
	}

	cout << DP[1][N];

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

#define INF 2100000000

vector<int> cost;
vector<vector<int>> DP;

int Dynamic(int start, int end) {
	if (DP[start][end] != -1) return DP[start][end];
	
	//?
	if (start == end) return 0;

	//??
	int sum = 0;
	for (int i = start; i <= end; i++) {
		sum += cost[i];
	}
	int ans = -1;
}

int merge() {

	int chap;
	int temp;

	cin >> chap;
	cost.clear();
	for (int i = 0; i < chap; i++) {
		cin >> temp;
		cost.push_back(temp);
	}
	DP.resize(chap);
	for (int i = 0; i < DP.size(); i++)
		DP[i].resize(chap, -1);
	
	return 0;
}

int main(void) {

	vector<int> ans;
	int T;

	cin >> T;
	while (T--) {
		ans.push_back(merge());
	}


	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}

/*
1
4
40 30 30 50
*/

/*

1
15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
*/

/*
2
4
40 30 30 50
15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
*/

/*
if (prefixSum[start][end] != 0) return prefixSum[start][end];

	int ans = INF;
	for (int i = start; i < end; i++) {

		prefixSum[start][i] = DP(start, i);
		prefixSum[i + 1][end] = DP(i + 1, end);

		cout << start << "부터" << end << "까지의 최솟값은: ";
		cout << prefixSum[start][i] + prefixSum[i + 1][end] << endl;

		ans = min(ans, prefixSum[start][i] + prefixSum[i + 1][end]);
	}
	return ans;
*/

/*

	for (int i = 0; i < prefixSum.size(); i++) {
		for (int j = 0; j < prefixSum[i].size(); j++) {
			cout << prefixSum[i][j] << "\t";
		}
		cout << endl;
	}
*/
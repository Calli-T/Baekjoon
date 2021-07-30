#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> testCase;
	vector<int> cost(3, 0);
	vector<vector<int>> minCost;
	vector<int> RGB;
	int N;

	cin >> N;
	RGB.resize(N + 1, 0);
	minCost.resize(3, RGB);

	for (int i = 0; i < N; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		testCase.push_back(cost);
	}
	
	minCost[0][1] = testCase[0][0];
	minCost[1][1] = testCase[0][1];
	minCost[2][1] = testCase[0][2];
	
	/*
	cout << minCost[0][1] << endl;
	cout << minCost[0][1] << " ";
	cout << minCost[1][1] << " ";
	cout << minCost[2][1] << " ";
	*/

	return 0;
}
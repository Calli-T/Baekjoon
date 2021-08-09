#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {

	int N, M;
	int temp1, temp2;
	vector<vector<int>> network;
	stack<int> ST;
	vector<bool> visited;
	int current;
	bool hasChild;
	int ans = 0;

	cin >> N >> M;
	network.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		cin >> temp1 >> temp2;
		network[temp1].push_back(temp2);
		network[temp2].push_back(temp1);
	}

	ST.push(1);
	visited[1] = true;

	while (!ST.empty()) {
		current = ST.top();
		hasChild = false;
		
		for (int i = 0; i < network[current].size(); i++) {
			if (!visited[network[current][i]]) {
				visited[network[current][i]] = true;
				ST.push(network[current][i]);
				hasChild = true;
				break;
			}
		}

		if (!hasChild)
			ST.pop();
	}

	for (int i = 0; i < visited.size(); i++) {
		if (visited[i])
			ans++;
	}

	cout << ans - 1;

	return 0;
}
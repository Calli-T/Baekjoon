#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int DFS(vector<vector<int>>& tree, int root, int ban) {
	if (root == ban) return 0;

	int leef = 0;

	bool isEnd;
	stack<int> ST;
	vector<bool> visited(tree.size(), false);

	ST.push(root);
	visited[root] = true;
	//cout << root << " ";
	while (!ST.empty()) {
		int now = ST.top();
		isEnd = true;
		if (tree[now].size() == 0)leef++;
		else if (tree[now].size() == 1 && ban == tree[now][0])leef++;

		for (int i = 0; i < tree[now].size(); i++) {
			if (!visited[tree[now][i]] && tree[now][i] != ban) {
				isEnd = false;
				visited[tree[now][i]] = true;
				ST.push(tree[now][i]);
				//cout << tree[now][i] << " ";

				break;
			}
		}

		if (isEnd) ST.pop();
	}


	return leef;
}

int main(void) {
	vector<vector<int>> tree;
	int N, temp, root = 0;
	int ans;

	cin >> N;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		else
			tree[temp].push_back(i);
	}

	cin >> temp;

	cout << DFS(tree, root, temp);
	

	return 0;
}
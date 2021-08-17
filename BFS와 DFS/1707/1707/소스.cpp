#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool bipartiteGraph() {
	
	int V; //vertex
	int E; //edge
	vector<vector<int>> graph;
	int temp1, temp2;
	//stack<int> ST;
	vector<int> visited;
	//bool isBipartiteGraph = true;

	cin >> V >> E;
	graph.resize(V + 1);
	visited.resize(V + 1, 0);
	for (int i = 0; i < E; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}
	
	for (int i = 1; i < visited.size(); i++) {
		stack<int> ST;
		bool isChecked;

		if (visited[i] == 0) {
			ST.push(i);
			visited[i] = 1;

			while (!ST.empty()) {
				int now = ST.top();
				isChecked = true;
				
				for (int j = 0; j < graph[now].size(); j++) {
					
					if (visited[graph[now][j]] == visited[now]) {
						return false;
					}
					else if (visited[graph[now][j]] == 0) {
						
						visited[graph[now][j]] = -visited[now];
						ST.push(graph[now][j]);
						isChecked = false;
						
						break;
					}
					
				}				
			
				if (isChecked) ST.pop();

			}

		}
	}

	return true;
}

int main(void) {
	int T;
	vector<bool> ans;

	cin >> T;
	while (T--) {
		ans.push_back(bipartiteGraph());
	}

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i])
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}
	
	return 0;
}

/*
1
3 2
1 3
2 3
*/

/*
1
4 4
1 2
2 3
3 4
4 2
*/
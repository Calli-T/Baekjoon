#include <iostream>
#include <queue>
#include <vector>

#define INF 3000001

using namespace std;

struct path {
	int DT; //destination
	int WT; //weight
	bool operator < (path a) {
		return this->DT < a.DT;
	}
};

vector<int> dist; //°Å¸®
vector<vector<path>> graph;
priority_queue<int> Q;
int V, E, K; //vertex, Edge, starting point

using namespace std;

int main(void) {
	int st, dt, wt;
	path temp;

	cin >> V >> E >> K;
	graph.resize(V + 1);
	dist.resize(V + 1, INF);

	for (int i = 0; i < E; i++) {
		cin >> st >> dt >> wt;
		temp.DT = dt;
		temp.WT = wt;
		graph[st].push_back(temp);
	}

	for (int i = 0; i < graph.size(); i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	cout << endl;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			cout << i << " " << graph[i][j].DT << " " << graph[i][j].WT << endl;
		}
	}


	return 0;
}
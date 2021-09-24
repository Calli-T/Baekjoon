#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> adj_matrix;
vector<int> NEXT;
vector<int> edge_num;
int N;

int main(void) {
	cin >> N;
	adj_matrix.resize(N);
	for (int i = 0; i < N; i++)
		adj_matrix[i].resize(N);
	NEXT.resize(N, 0);
	edge_num.resize(N, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj_matrix[i][j];
			edge_num[i] += adj_matrix[i][j];
		}			
	}

	for (int i = 0; i < N; i++) {
		if (edge_num[i] % 2 == 1) {
			cout << -1 << endl;
			return 0;
		}
	}
		

	return 0;
}
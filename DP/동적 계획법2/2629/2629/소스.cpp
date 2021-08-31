#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int temp;
vector<int> weight;
vector<int> marble;
vector<bool> isMeasurable;
vector<vector<bool>> measured;

void solution(int now, int total) {
	if (now > N) return;
	if (measured[now][total]) return;

	isMeasurable[total] = true;
	measured[now][total] = true;

	solution(now + 1, total);
	solution(now + 1, total + weight[now]);
	solution(now + 1, abs(total - weight[now]));
}

int main(void) {
	cin >> N;
	weight.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		weight[i] = temp;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		marble.push_back(temp);
	}

	measured.resize(N + 1);
	for (int i = 0; i < N + 1; i++)
		measured[i].resize(15001, false);
	isMeasurable.resize(15001, false);

	solution(0, 0);

	for (int i = 0; i < marble.size(); i++) {

		if (marble[i] > 15000) {
			cout << "N ";
			continue;
		}

		if (isMeasurable[marble[i]]) cout << "Y ";
		else cout << "N ";

	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;


int N, M; //추와 구슬의 개수
int temp;
vector<int> weight;
vector<int> marble;
vector<bool> isMeasurable;

void solution(int now, int total) {

	total = total < 0 ? -total : total;
	isMeasurable[total] = true;

	if (now <= weight.size() - 1) {
		solution(now + 1, total);
		solution(now + 1, total + weight[now]);
		solution(now + 1, total - weight[now]);
	}
}

int main(void) {

	weight.push_back(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		weight.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		marble.push_back(temp);
	}

	temp = 0;
	for (int i = 1; i < weight.size(); i++)
		temp += weight[i];
	isMeasurable.resize(temp + 1, false);

	solution(1, 0);


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
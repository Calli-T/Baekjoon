#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	vector<int> card;
	vector<int> list;
	vector<int> ans;
	int temp;
	int mid, left, right;

	cin >> N;
	card.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		card[i] = temp;
	}
	cin >> M;
	list.resize(M);
	ans.resize(M, 0);
	for (int i = 0; i < M; i++) {
		cin >> temp;
		list[i] = temp;
	}

	sort(card.begin(), card.end());

	for (int i = 0; i < M; i++) {
		left = 0;
		right = N - 1;

		while (left <= right) {
			mid = (left + right) / 2;
			if (card[mid] == list[i]) {
				temp = 0;
				while (card[mid] == list[i] && mid < N - 1) {
					temp++;
					mid++;
				}
				ans[i] = temp;

				break;
			}
			else if (card[mid] > list[i]) right = mid - 1;
			else left = mid + 1;
		}
	}

	for (int i = 0; i < M; i++)
		cout << ans[i] << " ";
	
	return 0;
}
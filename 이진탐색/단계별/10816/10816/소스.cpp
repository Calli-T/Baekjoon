#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int N, M;
	vector<int> card;
	vector<int> list;
	vector<int> ans;
	int temp;
	int mid, low, high;
	int LB, HB;

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
		low = 0;
		high = N;
		while (low < high) {
			mid = low + (high - low) / 2;
			if (list[i] <= card[mid])
				high = mid;
			else
				low = mid + 1;
		}
		LB = low;

		low = 0;
		high = N;
		while (low < high) {
			mid = low + (high - low) / 2;
			if (list[i] >= card[mid])
				low = mid + 1;
			else
				high = mid;
		}
		HB = high;
	
		ans[i] = HB - LB;
	}

	for (int i = 0; i < M; i++)
		cout << ans[i] << " ";
	
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> arr;
	int N, M;
	int lft, rht, mid;
	vector<int> list;
	vector <bool> ans;
	int temp;

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	sort(arr.begin(), arr.end());
	
	cin >> M;
	list.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> temp;
		list[i] = temp;
	}

	ans.resize(M, false);
	for (int i = 0; i < M; i++) {
		lft = 0;
		rht = N - 1;

		while (lft <= rht) {
			mid = (lft + rht) / 2;
			if (arr[mid] == list[i]) {
				ans[i] = true;
				break;
			}
			else if (arr[mid] > list[i])  rht = mid - 1;
			else lft = mid + 1;
		}
	}

	for (int i = 0; i < M; i++)
		cout << ans[i] << '\n';

	return 0;
}
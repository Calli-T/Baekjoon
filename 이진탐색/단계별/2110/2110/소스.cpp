#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, C;
	vector<int> house;
	int temp;
	int low, mid, high;
	
	int ans = 0;
	int count;
	int prev_house;

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		house.push_back(temp);
	}
	sort(house.begin(), house.end());

	low = 0;
	high = house[N - 1];
	temp = 0;

	//탐색하는 값은 거리의 최대값이고,
	//또한 거리의 최대값안에 공유기와 공유기로
	//연결가능한곳에 집이 있는지 확인하고 그렇지 않으면
	//또다시 이분탐색으로 집어넣는다
	while (low <= high) {
		mid = (low + high) / 2;

		count = 1;
		prev_house = house[0];
		for (int i = 1; i < N; i++) {
			if (house[i] - prev_house >= mid) {
				count++;
				prev_house = house[i];
			}
		}

		if (count >= C) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else high = mid - 1;
		
	}

	cout << ans;


	return 0;
}

/*
	for (int i = 0; i < N; i++) {
		cout << house[i] << " ";
	}
	cout << endl;
*/
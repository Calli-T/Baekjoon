#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N;
	int ans = 1;
	vector<vector<int>> wire;
	vector<int> cable(2,0);
	vector<int> DP;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cable[0] >> cable[1];
		wire.push_back(cable);
	}
	sort(wire.begin(), wire.end());
	DP.resize(wire.size(), 1);

	for (int i = 0; i < DP.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (wire[i][1] > wire[j][1]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		ans = max(DP[i], ans);
	}

	cout << N - ans;

	return 0;
}

/*
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			cout << wire[i][j] << " ";
		}
		cout << endl;
	}
	*/

/*
시작 위치를 A라 할 때,
A1~A10의 값은 B1~10에 있고, 해당 값이
점점 커짐으로 써 LIS를 이루어야 가능하다

빈 공간은 어떤식의 배열로 처리할 것인가?
INF값을 설정하고 그 값으로 두면 알아서 넘어갈 것이다
더 좋은 방법은?
아예 빈 공간이 없는 배열로, 크기 순서로 정렬하는것이
좋을것이다
*/
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
���� ��ġ�� A�� �� ��,
A1~A10�� ���� B1~10�� �ְ�, �ش� ����
���� Ŀ������ �� LIS�� �̷��� �����ϴ�

�� ������ ����� �迭�� ó���� ���ΰ�?
INF���� �����ϰ� �� ������ �θ� �˾Ƽ� �Ѿ ���̴�
�� ���� �����?
�ƿ� �� ������ ���� �迭��, ũ�� ������ �����ϴ°���
�������̴�
*/
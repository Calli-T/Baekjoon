#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	vector<int> wine;
	vector<vector<int>> DP;
	int n;
	int temp;
	int ans = 0;

	cin >> n;
	wine.resize(n, 0);
	DP.resize(2, wine); //DP[0][i]�� i+1��° ��ġ���� ���� 1���϶��� �ִ�, DP[1][i]�� i+1��° ��ġ���� ���� 2���϶��� �ִ�
	for (int i = 0; i < n; i++) {
		cin >> temp;
		wine[i] = temp;
	}

	if (n == 1) {
		cout << wine[0];
	}
	else if (n == 2) {
		cout << wine[0] + wine[1];
	}
	else if (n == 3) {
		cout << max(max(wine[0] + wine[1], wine[0] + wine[2]), wine[1] + wine[2]);
	}
	else {
		DP[0][0] = wine[0]; // 1ĭ�ٱ� �ʱ�
		DP[0][1] = wine[1]; // 2ĭ�ٱ� �ʱ�
		DP[0][2] = wine[0] + wine[2]; // ���� 1�� ����, ������ ������ ������ġ������ 3ĭ�ٱ� �Ұ�
		DP[1][1] = wine[0] + wine[1]; // ���� 2�� ����, 1ĭ�ٱ�θ�
		DP[1][2] = wine[1] + wine[2]; // ���� 2�� ����, 2ĭ�ٱ� + 1ĭ�ٱ�

		for (int i = 3; i < n; i++) {
			// 2ĭ �ٱ�, 3ĭ �ٱ⸦ ���ؼ��� ����Ƚ���� 1�� ���°���, ������ �ִ밪���� �ش���ġ �����ָ� ����
			DP[0][i] = max(max(max(DP[0][i - 3], DP[0][i - 2]), DP[1][i - 2]), DP[1][i - 3]) + wine[i];
			DP[1][i] = DP[0][i - 1] + wine[i]; // 1�������� ������ ������ �ִ�ġ + �ش���ġ ������
		}

		for (int i = 0; i < n; i++) {
			ans = max(ans, max(DP[0][i], DP[1][i]));
		}

		cout << ans;

	}	

	return 0;
}

/*
for (int i = 0; i < n; i++) {
		cout << wine[i] << endl;
	}
*/

/*
for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
*/

// ��ܰ� ����Ѱ�?
// ��¦ �ٸ���, ����� �ִ� 2ĭ�ٱ⸸ �����ϰ� ���� �׷��� ����
// 3ĭ�ٱ�� ��ȿ�Ѱ�? ���� 2���� ���ĵ� �� ���� �� �ִٸ� ��ȿ�ϴ�.
// 4ĭ�ٱ�� ��ȿ�Ѱ�? ���� 3���� ��ģ�ٸ�, �ݵ�� 3���� ��� �����ָ� �����ϴ°���, �� ���� ���� �� �ִ� ���̴�. ��ȿ�����ʴ�
// ���� 1, 2, 3ĭ�� �� ���� ���� �� �ִ� ��� ������ ����
// 3ĭ �ٱ�� ������ �� �� ĭ�� ����°��� �Ұ����ϴ�

/*6
100
400
2
1
4
200
*/

/*
3
10
3
10
*/
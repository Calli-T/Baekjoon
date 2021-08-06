#include <vector>
#include <iostream>

using namespace std;

int main(void) {

	int N;
	vector<vector<long long>> DP;
	vector<long long> line;
	
	cin >> N;
	line.resize(N, 0);
	DP.resize(10, line);
	for (int i = 1; i < 10; i++) {
		DP[i][0] = 1;
	}
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < 10; i++) {
			if (i == 0) {
				//for (int j = 0; j < N - 1; j++) {
				DP[i + 1][j + 1] += DP[i][j];
				DP[i + 1][j + 1] %= 1000000000;
				//}
			}
			else if (i >= 1 && i <= 8) {
				//for (int j = 0; j < N - 1; j++) {
					//cout << DP[i][j] << " ";
				DP[i + 1][j + 1] += DP[i][j];
				DP[i - 1][j + 1] += DP[i][j];

				DP[i + 1][j + 1] %= 1000000000;
				DP[i - 1][j + 1] %= 1000000000;
				//}
				//cout << endl;
			}
			else {
				//for (int j = 0; j < N - 1; j++) {
				DP[i - 1][j + 1] += DP[i][j];
				DP[i - 1][j + 1] %= 1000000000;
				//}
			}
		}
	}
	//cout << endl;
	
	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < N; j++) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}*/
	
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += DP[i][N - 1];
	}
	
	cout << ans % 1000000000;

	return 0;
}

// ���̵��: ��ܼ����� ���ǿ���, ������ ��� �ڸ����� ������ 1�̶�� ���� �ܰ��
// �Ѿ �� �ϳ� ���ϰų�, �ϳ� ���������̴�
// �ش� �ڸ��� �ش� ���� �ִ� ��ܼ��� ������ �ְ�, �� ������ �ջ�����
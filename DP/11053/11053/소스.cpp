#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<int> DP;
	vector<int> SEQ; //Seqeunce
	int N;
	int temp;
	int ans = 1;

	cin >> N;
	DP.resize(N + 1, 1);
	SEQ.resize(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		SEQ[i] = temp;
	}

	for (int i = 1; i <= N; i++) {
		//if (ans >= N - i + 1) break;

		for (int j = 1; j <= i; j++) {
			if (SEQ[i] > SEQ[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}

		ans = max(DP[i], ans);
	}

	cout << ans;

	return 0;
}

// ���̵�� dp[i] = i��° ���Ҹ� ���������� �ϴ� LIS, ������ ���Ұ� �ʿ������� ����ũ��
// 1~i-1�� ������, �ش� SEQ�� ���� SEQ[i]���� �۴ٸ�, i��° ���Ұ� ���� ū(��������) �����ϴ� �κ� ���� ���۰���
// ���� dp[i]�� dp[j](1<= j <= i-1) + 1 �߿��� ���� ū ��


/*
for (int i = 1; i <= N; i++) {
		cout << SEQ[i] << " ";
	}
	cout << endl;
*/

/*
20

322 831 212 232 545 698 260 265 324 215 701 75 156 605 851 993 425 887 691 593
*/
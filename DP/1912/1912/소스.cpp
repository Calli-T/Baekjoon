#include <vector>
#include <iostream>

using namespace std;

int main(void){

	int N;
	vector<int> DP;
	vector<int> number;
	int ans =  -100000001;

	cin >> N;
	DP.resize(N + 1, 0);
	number.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> number[i];
	}

	for (int i = 1; i <= N; i++) {
	
		if (DP[i - 1] + number[i] > number[i]) {
			DP[i] = DP[i - 1] + number[i];
		}
		else {
			
			DP[i] = number[i];
		}
		ans = max(ans, DP[i]);

	}
	
	cout << ans;

	return 0;
}

// �ش簪�� ���������� ���� ����
// �ش簪���ٸ� ũ��ѱ��
// �ƴϸ� �ش簪���� ����
// �� �� �� ���� �ְ��� ������ DP�ȿ� ��ϵǾ��ִ�
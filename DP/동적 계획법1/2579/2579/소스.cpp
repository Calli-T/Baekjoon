#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	int temp;
	vector<int> stair(1, 0);
	vector<vector<int>> DP;
	vector<int> status;

	cin >> N;
	status.push_back(0); 
	status.push_back(0); 
	status.push_back(0); 
	DP.resize(N + 1, status);

	for (int i = 0; i < N; i++) {
		cin >> temp;
		stair.push_back(temp);
	}

	DP[1][1] = stair[1];
	if(N >=2){
		DP[2][1] = stair[2];
		DP[2][2] = stair[1] + stair[2];
	}
	
	
	if (N >= 3) {
		for (int i = 3; i <= N; i++) {
			/*// 1ĭ�ٱ��� ���, 0�����ӻ��¿���
			DP[i][1] = (DP[i - 1][0] != 0) ? (DP[i - 1][0] + stair[i]) : 0;*/
			// 1ĭ�ٱ��� ���, 1�����ӻ��¿���
			DP[i][2] = DP[i - 1][1] + stair[i];
			// 2ĭ�ٱ��� ���, ���� ū ������
			temp = max(max(DP[i - 2][0], DP[i - 2][1]), DP[i - 2][2]);
			//cout << "Mu" << temp << "YaHo" << endl;
			DP[i][1] = temp + stair[i];
		}
	}

	int ans = max(DP[N][1], DP[N][2]);
	cout << ans;
	//����ū�ɱ��Ѵ�

	return 0;
}

/*
	for (int i = 0; i <= N; i++) {
		cout << i << "��° ���(" << stair[i];
		cout << "):	";
		cout << DP[i][0] << "	";
		cout << DP[i][1] << "	";
		cout << DP[i][2] << endl;

	}*/


/*
for (int i = 0; i <= N; i++) {
	cout << i << "��° ���(" << stair[i];
	cout << "):	";
	cout << DP[i][0] << "	";
	cout << DP[i][1] << "	";
	cout << DP[i][2] << endl;

}*/

/*
for (int i = 0; i < stair.size(); i++)
		cout << stair[i] << endl;
*/

// ���̵�� 1: �� ���Ǻ���/������ Ƚ�� ���� ������ ���� ������?
// DP[N][M] N�� �����ġ, M�� ������ ������ �� �ش� ���� ����
// 2�ܰ� �����ٸ�, ���Ӱ���� 1�̵� 2�� 1�� ����
// �迭�� ũ�⸦ �����Ұ�
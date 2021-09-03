#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	int temp;
	vector<int> value;
	vector<int> DP;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		value.push_back(temp);
	}

	DP.resize(M + 1);
	
	DP[0] = 1; // 0��
	for (int i = 0; i < N; i++) { //������ ������ ����
		for (int j = value[i]; j <= M; j++) { //������ ���ݺ��� �������� ����
			DP[j] += DP[j - value[i]];  //������ ������ ���ο� ������ �߰����� �� ������ ����� �ο���
			//���ΰ���ŭ �ѰͿ��ٰ� �ش� ������ ���ϸ� �ش� ���� �ǹǷ� 
		}
	}

	cout << DP[M] << endl;
	
	return 0;
}

//DP[i] = 
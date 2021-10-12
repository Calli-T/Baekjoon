#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	vector<int> memory;
	vector<int> cost;
	int temp;
	int ans = 0;

	vector<vector<int>> DP;

	cin >> N >> M;
	memory.push_back(0);
	cost.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		memory.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		cost.push_back(temp);
	}
	
	temp = 0;
	for (int i = 1; i <= N; i++)
		temp += cost[i];

	DP.resize(N + 1);
	for (int i = 0; i <= N; i++)
		DP[i].resize(temp + 1, 0);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= temp; j++) {
			if(j - cost[i]>=0)
				DP[i][j] = max(DP[i - 1][j], DP[i-1][j-cost[i]] + memory[i]);
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}

	for (int i = 1; i <= temp; i++) {
		for (int j = 1; j <= N; j++) {
			ans = max(ans, DP[j][i]);
		}
		if (ans >= M) {
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}

// �޸𸮰� 10^7�̹Ƿ� �޸𸮸� �Ⱦ ���� ����
// ���԰� 100����, N�� 100�����̹Ƿ� ǥũ��� �ִ� 101*101���̸�
// ���� ������ ���Ը� �̿��� DP�� �������� �Ǵ�


// �����̶�, ������ ���Կ� ��ġ�� ���س���
// ������ ���Ը� �����ʴ¼�����
// �ִ����� ��ġ�� ì�����

// ������ ������ ��ġ���� ���� ������
// �ּ����� ���Ը� �������� ����� �ִ°�?

// ������ �� ���� 2���� ���ͷ�
// row�� ���Ժ� ��ġ��, column�� ������ �ǹ��ߴ�
// �ش� �࿡���� ������ ������ ������ ����ߴ�

// ������, ��� ����(7579������ �޸�)�� �� ����ִ°����� ���� �����ؼ�
// �ش� ������ ���������� ������ ����ؾ��Ѵ�

// �׷��ϴٸ� DP[0][0]�� ��� ���Ը� �ջ��� ����������� �����Ѵ�

/*
for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= temp; j++) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
*/
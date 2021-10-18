#include <iostream>
#include <vector>
#include <bitset>

#define INF 1e9

using namespace std;

int N;
vector<vector<int>> cost; //���
vector<vector<int>> DP;

//DP[i][j]�� i�� ���ÿ� �������� �� ���� �湮���ð� j�� �� �ּҺ���� �ǹ��Ѵ�

//���� 2���� ���� ���� �ִ� ���ÿ� �湮�� ��Ȳ�̴�
int DFS(int cur, int state) {
	int& now = DP[cur][state];

	//��� ���ø� �湮���� ���
	if (state == (1 << N) - 1) {
		//���� ���÷� ���ư��� ���̾��ٸ� INF���� return�Ͽ�
		//ans�� �پ��� ���� �����ΰ�����
		if (cost[cur][0] == 0)return INF;
		else return cost[cur][0]; // ���� �ִٸ� ������ ���÷� ���ƿ´�
	}
	//DP�� �ʱ�ȭ�� -1�� �����Ƿ� ������ ��������� -1�� �ƴϰԵȴ�. �̸� return
	if (now != -1) return now;

	//���ѿ��� ���� �ٿ�������
	int ans = INF;
	//�� ���õ鿡 ����
	for (int i = 0; i < N; i++) {
		//�ش� ��Ʈ����ũ �ڸ��� 0�̶��, �� �湮�� ���� ���ٸ�
		if (!(state & (1 << i))) {
			// ���� ���̾��ٸ� ����
			if(cost[cur][i] == 0 ) continue;
			ans = min(ans, DFS(i, state | (1 << i)) + cost[cur][i]);
			//�׷��� ������� �ּҰ��� ��� ans�� �񱳴����
			//���� ���ÿ��� �ش絵�÷� ���º�뿡 �ش� ���ÿ��� ���� ��ȸ�� ���� ���
		}
	}

	//�ּ�ȭ�� ans�� return
	return now = ans;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cost.resize(N);
	for (int i = 0; i < N; i++)
		cost[i].resize(N);
	DP.resize(N + 1);
	for (int i = 0; i <= N; i++)
		DP[i].resize(1 << N, -1);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> cost[i][j];

	cout << DFS(0, 1);

	return 0;
}

/*
	cout << endl;
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < (1 << N); j++) {
			if (DP[i][j] == INF)
				cout << "INF" << " ";
			else
				cout <<DP[i][j] << " ";
		}
		cout << endl;
	}
*/
#include <vector>
#include <iostream>

using namespace std;

int main(void) {

	int N, K;
	vector<int> DP;
	vector<int> w;//weight;
	vector<int> v;//value;
	int temp1, temp2;

	cin >> N >> K;
	DP.resize(K + 1, 0);
	w.push_back(0);
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		w.push_back(temp1);
		v.push_back(temp2);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= 1; j--) {
			if (w[i] <= j) {
				DP[j] = max(DP[j], DP[j - w[i]] + v[i]);
			}
		}
	}

	cout << DP[K];
	
	return 0;
}

/*
#include <vector>
#include <iostream>

using namespace std;

int main(void) {

	int N, K;
	vector<vector<int>> DP;
	vector<int> w;//weight;
	vector<int> v;//value;
	int temp1, temp2;

	cin >> N >> K;
	DP.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		DP[i].resize(K + 1, 0);
	}
	w.push_back(0);
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		w.push_back(temp1);
		v.push_back(temp2);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - w[i] >= 0) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << DP[N][K];
	
	return 0;
}
*/

/*
for (int i = 0; i <= N; i++) {
	for (int j = 0; j <= K; j++) {
		cout << DP[i][j] << " ";
	}
	cout << endl;
}
*/

// ��ǰ�� �� N, ���� K��
// N+1��, K+1���� �迭�� �����
// ���԰� 0�� ����, 0��° ��ǰ�� ����� ���� ����0���� ó���ѵ�(������ǻ�)
// dp[i][j]�� ���Ǵ� ó������ i��°������ ��ǰ�� ����
// �賶�� �뷮�� j���� �� �賶�� �� ������ 
// ��ġ���� �ִ밪
// �� ĭ���� i-1��° ��ǰ�� ���� ������ �ִ� ��ġ�հ�
// i-1��ǰ ���� ���� �ִ� ���� - �̹� ������ ����
// �� ���� �ִ� ��ġ��+�̹������� ��ġ �� �� ū
// ���� ����� ���̴�

// ������ �ϳ��� ���캸�鼭
// �ش� ������ �� ���԰� �Ǵ���
// �賶 �뷮�� ���Ժ��� ũ�ٸ�
// (������ �賶 �뷮 - ���� ��������)�� �賶�� ��ġ + ���� ������ ��ġ��
// ������ �賶�� ��ġ�� ���ؼ� �� ū������ �־��ش�

// ����ȭ�� �˰��򿡼��� ������ 2���� �迭�� ������� �ʰ�
// ���԰� ���ſ����� �賶���� ä�����µ�, ä�� ��
// �Ʊ� �����ߴ� ��������賶+���ݺ�����ġ�� ���غ���
// ������ ��ġ��ȴ�
// �� �� �Ǽ��� �������Ը� ������ ������ ���� �ȵȴ�

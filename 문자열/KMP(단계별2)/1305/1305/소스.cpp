#include <iostream>
#include <vector>

using namespace std;

vector<int> getPi(string &p) {
	int j = 0;
	int len = p.size();
	vector<int> pi(len, 0);

	for (int i = 1; i < len; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];

		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}

	return pi;
}

int main(void) {
	int L;
	string panel;
	vector<int> pi;

	cin >> L >> panel;
	
	pi = getPi(panel);
	cout << L - pi[L - 1];

	return 0;
}

// pi�迭�� �����
// bcdabcda�� ���ϰ��
// �����Լ��� ����
// 0 0 0 0 1 2 3 4�̴�
// ���� �Լ��� ���� ū ������ �߶� �ڿ����� ������ ���̸�?

//�����Լ��� ��� Ȱ���� ���ΰ�
//ó�� ���ڿ���
// ���� + �޲ǹ��̷� �������ִٰ� �����Ѵ�
//abcdabc���� ��� pi[6]���� 3�̰�
//4ĭ ������ d�� ©���ִ�
//���� 4���� ����� ����� �� �ִ�
//abaaab�� ��� abaa�� ����� ����� �� �ִ�
//�ٽ� abaa�� �ڸ���? pi[4]�� 1�̰� ba�� ���´�?

//abababa���� ��� pi[6]���� 5�̰�
//���� ab�� ���� ����Ѵ�

//aaaaa���� 
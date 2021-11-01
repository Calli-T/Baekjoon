#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPi(string p) {
	int j = 0;
	int len = p.size();
	vector<int> pi(len, 0);

	for (int i = 1; i < len; i++) {
		//1�̽�, p�� pi�� �����Ұ�
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		
		if (p[i] == p[j])
			pi[i] = ++j;
	}

	return pi;
}

vector<int> KMP(string T, string P) {
	vector<int> ans;
	vector<int> pi;
	int t_len = T.size();
	int p_len = P.size();
	int j = 0;

	pi = getPi(P);

	for (int i = 0; i < t_len; i++) {
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];

		if (T[i] == P[j]) {
			if (j == p_len - 1) {
				ans.push_back(i - j); // ������ ������
				j = pi[j];//�� ��� �ϴ���
			}
			else j++;
		}
	}

	return ans;
}

int main(void) {
	string T, P;
	
	getline(cin, T);
	getline(cin, P);

	vector<int> ans = KMP(T, P);

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << " ";
	cout << '\n';

	return 0;
}
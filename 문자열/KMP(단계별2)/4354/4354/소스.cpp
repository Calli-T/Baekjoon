#include <iostream>
#include <vector>

using namespace std;

vector<int> getPi(string& p) {
	vector<int> pi(p.size(), 0);
	int j = 0;

	for (int i = 1; i < p.size(); i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];

		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}

	return pi;
}

int getExp(string& t) {
	auto pi = getPi(t);
	int len = pi[t.size() - 1];
	int ans = t.size() - len;

	if (t.size() % ans != 0)
		return 1;
	else
		return t.size() / ans;
}

int main(void) {
	vector<string> T;
	string temp;
	vector<int> ans;

	while (true) {
		cin >> temp;
		if (temp == ".") break;
		T.push_back(temp);
	}

	ans.resize(T.size(), 0);
	for (int i = 0; i < ans.size(); i++) {
		ans[i] = getExp(T[i]);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';

	return 0;
}

//맞는 코드

//전체 길이 - 실패 함수의 마지막 값=반복되는 문자열의 최소길이
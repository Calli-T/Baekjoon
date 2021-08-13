#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	string exp;
	string sub;
	string subsub;
	vector<int> paren;
	vector<int> plus;

	int ans = 0;
	int subtotal;
	
	cin >> exp;

	paren.push_back(0);
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == '-') {
			paren.push_back(i);
		}
	}
	paren.push_back(exp.size());

	for (int i = 0; i < paren.size() - 1; i++) {
		sub = exp.substr(paren[i] + (i != 0 ? 1 : 0), paren[i + 1] - paren[i] - (i != 0 ? 1 : 0));
		//cout << sub << endl;
		
		plus.clear();
		plus.push_back(0);
		for (int j = 0; j < sub.size(); j++) {
			if (sub[j] == '+') {
				plus.push_back(j);
			}
		}
		plus.push_back(sub.size());

		//cout << endl;
		subtotal = 0;
		for (int j = 0; j < plus.size() - 1; j++) {
			subsub = sub.substr(plus[j] + (j != 0 ? 1 : 0), plus[j + 1] - plus[j] - (j != 0 ? 1 : 0));
			//cout << subsub << endl;
			subtotal += stoi(subsub);
			//cout << plus[j];
		}
		//cout << subtotal << endl;
		//cout << endl;

		if (i) ans -= subtotal;
		else ans += subtotal;
		
	}

	cout << ans;

	return 0;
}
/*
* for (int j = 0; j < sub.size(); j++) {
			if (sub[j] == '+') {
				plus.push_back(j);
			}
		}
		plus.push_back(sub.size());

		for (int j = 0; j < plus.size(); j++) {
			subsub=sub.substr(plus[i])
		}
*/
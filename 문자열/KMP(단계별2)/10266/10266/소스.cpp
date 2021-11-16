#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> getPi(vector<int>& gap) {
	int j = 0;
	int len = gap.size();
	vector<int> pi(len, 0);

	for (int i = 1; i < len; i++) {
		while (j > 0 && gap[i] != gap[j])
			j = pi[j - 1];

		if (gap[i] == gap[j])
			pi[i] = ++j;
	}

	/*
	for (int i = 0; i < len; i++)
		cout << pi[i] << " ";
	cout << endl;
	*/

	return pi;
}

bool KMP(vector<int>& gap1, vector<int>& gap2, int n) {
	vector<int> pi = getPi(gap1);
	int j = 0;
	vector<int> location;

	for (int i = 0; i < 2 * n; i++) {
		while (j > 0 && gap2[i] != gap1[j])
			j = pi[j - 1];

		if (gap2[i] == gap1[j]) {
			if (j == n - 1) {
				location.push_back(i - j);
				j = pi[j];
			}
			else
				j++;
		}
	}

	return !location.empty();
}

int main() {
	int n = 0;
	vector<int> clock1;
	vector<int> clock2;
	vector<int> gap1;
	vector<int> gap2;
	int temp = 0;

	cin >> n;
	clock1.resize(n, 0);
	clock2.resize(n, 0);
	gap1.resize(n, 0);
	gap2.resize(n, 0);

	for (int i = 0; i < n; i++)
		cin >> clock1[i];
	for (int i = 0; i < n; i++)
		cin >> clock2[i];
	sort(clock1.begin(), clock1.end());
	sort(clock2.begin(), clock2.end());
	
	for (int i = 0; i < n - 1; i++) {
		gap1[i] = clock1[i + 1] - clock1[i];
		gap2[i] = clock2[i + 1] - clock2[i];
	}
	gap1[n - 1] = 360000 - clock1[n - 1] + clock1[0];
	gap2[n - 1] = 360000 - clock2[n - 1] + clock2[0];

	for (int i = 0; i < n; i++)
		gap2.push_back(gap2[i]);

	if (KMP(gap1, gap2, n))
		cout << "possible" << '\n';
	else
		cout << "impossible" << '\n';

	return 0;
}
/*
for (int i = 0; i < n; i++)
		cout << gap1[i] << " ";
	cout << endl;
	for (int i = 0; i <2 * n; i++)
		cout << gap2[i] << " ";
	cout << endl;
*/
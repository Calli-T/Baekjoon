#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	int coe[26] = { 0 };
	int dec;
	string line;
	int place[10] = { 0 };
	int temp = 0;
	int now;
	int ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> line;
		dec = 1;

		for (int j = line.size() - 1; j >= 0; j--) {
			coe[(int)line[j] - 65] += dec;
			dec *= 10;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (coe[i]) {
			place[temp] = coe[i];
			temp++;
		}
	}

	vector<int> test(temp, 0);
	vector<int> copyBest;
	for (int i = 0; i < temp; i++)
		test[i] = 9 - i;

	do {
		now = 0;
		for (int i = 0; i < temp; i++) {
			now += test[i] * place[i];
		}
		ans = max(ans, now);
	} while (next_permutation(test.rbegin(), test.rend()));

	cout << ans;

	return 0;
}

/*
for (int i = 0; i < 26; i++) {
			cout << coe[i] << " ";
	}
	cout << '\n';
*/

/*
vector<int> test(4, 0);
	for (int i = 0; i < 4; i++)
		test[i] = i + 1;

	do {
		for (int i = 0; i < 4; i++)
			cout << test[i] << " ";
		cout << endl;
	} while (next_permutation(test.begin(), test.end()));
*/

/*
for (int j = 0; j < 26; j++) {
		for (int i = 0; i < 8; i++) {
			cout << temp[i][j] << " ";
		}
		cout << '\n';
	}
*/
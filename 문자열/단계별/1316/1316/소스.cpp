#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<bool> alpha;
	int N;
	string temp;
	int ans;

	cin >> N;
	ans = N;
	while (N--) {
		cin >> temp;

		alpha.clear();
		alpha.resize(26, false);

		for (int i = 0; i < temp.size(); i++) {
			if (!alpha[temp[i] - 97]) {
				alpha[temp[i] - 97] = true;
				int skip = 0;
				while (temp[i] == temp[i + skip])skip++;
				i = i + skip - 1;
			}
			else {
				ans--;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}
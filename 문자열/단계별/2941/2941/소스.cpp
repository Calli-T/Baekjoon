#include <iostream>

using namespace std;

int main(void) {
	string temp;
	int ans;
	
	cin >> temp;
	ans = temp.size();

	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == 'c') {
			if (temp[i + 1] == '=' || temp[i + 1] == '-') {
				ans--;
				i++;
				continue;
			}
		}
		else if (temp[i] == 'd') {
			if (temp[i + 1] == 'z' && temp[i + 2] == '=') {
				ans -= 2;
				i += 2;
				continue;
			}
			else if (temp[i + 1] == '-') {
				ans--;
				i++;
				continue;
			}
		}
		else if (temp[i] == 'l' || temp[i] == 'n') {
			if (temp[i + 1] == 'j') {
				ans--;
				i++;
				continue;
			}
		}
		else if (temp[i] == 's' || temp[i] == 'z') {
			if (temp[i + 1] == '=') {
				ans--;
				i++;
				continue;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
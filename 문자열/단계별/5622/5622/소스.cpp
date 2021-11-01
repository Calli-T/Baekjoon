#include <iostream>

using namespace std;

int main(void) {
	string temp;
	int ans = 0;

	cin >> temp;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] < 80)
			ans += (((int)temp[i] - 65) / 3 + 2) + 1;
		else if (temp[i] >= 80 && temp[i] <= 83)
			ans += 8;
		else if (temp[i] >= 84 && temp[i] <= 86)
			ans += 9;
		else
			ans += 10;
	}
	
	cout << ans;

	return 0;
}
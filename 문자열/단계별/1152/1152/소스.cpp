#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string temp;
	int ans = 0;
	
	getline(cin, temp);

	for (int i = 0; i < temp.size(); i++) {
		if (i != 0 && i != temp.size() - 1)
			if (temp[i] == ' ') ans++;
	}

	if (temp.size() == 1 && temp[0] == ' ') cout << 0;
	else cout << ++ans << '\n';

	return 0;
}
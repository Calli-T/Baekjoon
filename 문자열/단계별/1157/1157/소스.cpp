#include <iostream>

using namespace std;

int main(void) {
	int alphabet[26] = { 0 };
	string temp;
	int num = 0;
	int loc = 0;

	cin >> temp;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] >= 97)
			alphabet[temp[i] - 97]++;
		else
			alphabet[temp[i] - 65]++;
	}

	for (int i = 0; i < 26; i++)
		if (alphabet[i] > alphabet[loc]) loc = i;

	for (int i = 0; i < 26; i++)
		if (alphabet[i] == alphabet[loc]) num++;

	if (num > 1) cout << "?";
	else cout << (char)(loc + 65) << '\n';

	return 0;
}
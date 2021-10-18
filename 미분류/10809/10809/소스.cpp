#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	string S;
	vector<int> alphabet(26, -1);

	cin >> S;
	
	for (int i = 0; i < S.size(); i++) {
		if (alphabet[(int)S[i] - 97] == -1)
			alphabet[(int)S[i] - 97] = i;
	}

	for (int i = 0; i < alphabet.size(); i++)
		cout << alphabet[i] << " ";

	return 0;
}
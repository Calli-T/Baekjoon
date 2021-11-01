#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int T;
	int count;
	string temp;

	cin >> T;
	while (T--) {
		cin >> count;
		cin >> temp;
		
		for (int i = 0; i < temp.size(); i++) {
			for (int j = 0; j < count; j++) {
				cout << temp[i];
			}
		}
		cout << '\n';
	}

	return 0;
}
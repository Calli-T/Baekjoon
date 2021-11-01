#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string temp1, temp2;

	cin >> temp1 >> temp2;
	reverse(temp1.begin(), temp1.end());
	reverse(temp2.begin(), temp2.end());

	if (stoi(temp1) > stoi(temp2)) cout << temp1;
	else cout << temp2;

	return 0;
}
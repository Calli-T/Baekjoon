#include <iostream>

using namespace std;

int main(void) {
	int N;
	char Num;
	int sum = 0;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> Num;
		sum+=Num - '0';
	}
	cout << sum << endl;

	return 0;
}
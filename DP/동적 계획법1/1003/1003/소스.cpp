#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	
	int T;
	int temp;
	int max=0;
	vector<int> callZero(43, 0);
	vector<int> callOne(43, 0);
	vector<int> testCase;

	callZero[0] = 1;
	callZero[1] = 0;
	callOne[0] = 0;
	callOne[1] = 1;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		testCase.push_back(temp);
		if (temp > max)
			max = temp;
	}
	
	for (int i = 2; i <= max; i++) {
		callZero[i] = callZero[i - 1] +callZero[i - 2];
		callOne[i] = callOne[i-1]  + callOne[i-2];
	}
	
	for (int i = 0; i < T; i++) {
		cout << callZero[testCase[i]] << " " << callOne[testCase[i]] << "\n";
	}

	return 0;
}
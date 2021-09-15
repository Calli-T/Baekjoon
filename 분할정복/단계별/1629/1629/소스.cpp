#include <iostream>
#include <vector>

using namespace std;
int A, B, C;

long long pow(long long frac, int expo) {
	if (expo == 1) return frac % C;
	long long temp = pow(frac, expo / 2);
	return expo % 2 == 1 ? ((temp * temp % C) * frac) % C : (temp * temp % C);
}

int main(void) {
	cin >> A >> B >> C;
	cout << pow((long long)A, B);

	return 0;
}
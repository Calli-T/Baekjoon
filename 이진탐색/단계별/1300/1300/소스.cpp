#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	int K;
	int low, high, mid;
	int count;

	cin >> N >> K;

	//K������ �ִ�� ��´�
	//1�� �ּҷ���´�
	int low = 1;
	int high = K;

	while (low <= high) {
		mid = (low + high) / 2;
		count = 0;

		for (int i = 1; i <= N; i++)
			count += min(mid / i, N);
		

	}

	return 0;
}
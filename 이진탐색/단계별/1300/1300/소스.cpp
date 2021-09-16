#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	int K;
	int low, high, mid;
	int count;
	int ans = -1;

	cin >> N >> K;

	low = 1;
	high = K;

	while (low <= high) {
		mid = (low + high) / 2;
		count = 0;

		for (int i = 1; i <= N; i++) {
			count += min(mid / i, N);
		}

		if (count < K) {
			low = mid + 1;
		}
		else {
			ans = mid;
			high = mid - 1;
		}
		
	}

	cout << ans;

	return 0;
}

//https://jaimemin.tistory.com/988

//mid�� ���� count�� K�� �Ѿ ����� ��ӵȴ�
//B[K]�� ���� ���� ���߾, �ߺ��� ������ ������ �ֱ� ������ ��Ӱ���Ѵ�
// low > high�� ��, ������ ���Ѱ��� ��Ȯ�ϰ� ������ �ð���...��?
//���� �Ϻ��ϰԴ� �������� ���ߴ�.

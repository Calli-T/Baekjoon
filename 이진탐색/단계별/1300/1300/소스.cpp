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

//mid로 구한 count가 K를 넘어도 계산은 계속된다
//B[K]와 같은 값을 구했어도, 중복된 숫자의 구간이 있기 때문에 계속계산한다
// low > high일 때, 직전에 구한값이 정확하게 구간의 시간인...가?
//아직 완벽하게는 이해하지 못했다.

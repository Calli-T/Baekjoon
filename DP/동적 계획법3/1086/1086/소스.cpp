#include <vector>
#include <iostream>
#include <string>

using namespace std;

typedef long long LL;


int N, K;
vector<string> arr;
vector<int> remain; //기존 배열의 K모듈러값
vector<int> ten;//10의 i승의 K모둘려값
vector<vector<LL>> DP;

LL gcd(LL x, LL y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main(void) {
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> K;
	DP.resize(1<<N);
	for (int i = 0; i <= N; i++)
		DP[i].resize(K+1, -1);
	
	//전처리, 모듈러 연산으로 나머지 구해놓기
	remain.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			remain[i] = remain[i] * 10 + arr[i][j] - '0';
			remain[i] %= K;
		}
	}
	//10의 i승도 모듈러 연산
	ten.resize(51);
	ten[0] = 1;
	for (int i = 1; i <= 50; i++) {
		ten[i] = ten[i - 1] * 10;
		ten[i] %= K;
	}

	DP[0][0] = 1;
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < K; j++) {

			for (int l = 0; l < N; l++) {

				if ((i & (1 << l)) == 0 ) {
					int next = j * ten[arr[l].size()];
					next %= K;
					next += remain[l];
					DP[i | (1 << l)][next] += DP[i][j];
				}

			}

		}
	}
	LL t1 = DP[(1 << N) - 1][0];
	LL t2 = 1;
	for (LL i = 2; i <= N; i++) t2 *= i;
	LL g = gcd(t1, t2);
	t1 /= g;
	t2 /= g;
	cout << t1 << '/' << t2 << '\n';

	return 0;
}

//DP[i][j]란? 상태가 i일 때 K로 나누어 나머지가 j인 순열의 개수

//
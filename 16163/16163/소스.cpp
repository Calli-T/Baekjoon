#include <iostream>
#include <vector>

using namespace std;



int main(void) {
	string S, temp;
	vector<int> A;
	int r = 0, p = 0;
	long long ans = 0;

	S.push_back('#');
	cin >> temp;
	for (int i = 0; i < temp.size(); i++) {
		S.push_back(temp[i]);
		S.push_back('#');
	}

	//r = p + A[p]
	//A[2 * p - i]파트가 잘 기억안남
	//p중심에서 i까지 거리 i - p를 p에서 빼면
	//2p - i
	A.resize(S.size(), 0);
	for (int i = 1; i < A.size(); i++) {
		if (i > r) A[i] = 0;
		else A[i] = min(r - i, A[2 * p - i]);

		while (	i - (A[i] + 1) >= 0 && i - (A[i] + 1) < A.size() && S[i - (A[i] + 1)] == S[i + A[i] + 1]) {
			A[i]++;
		}

		//r = i + A[i]로 해야한다
		//실수로 r < A[i]로 뒀다
		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}

	}

	for (int i = 0; i < A.size(); i++) {
			cout << A[i] << " ";
	}
		

	cout << ans;

	return 0;
}

//https://devlibrary00108.tistory.com/269
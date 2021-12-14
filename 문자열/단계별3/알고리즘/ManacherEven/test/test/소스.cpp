#include <iostream>
#include <vector>

using namespace std;

int main() {
	string S;
	string temp;
	vector<int> odd_A;
	vector<int> even_A;
	int ans = 0;
	int r = 0, p = 0;

	cin >> S;

	odd_A.resize(S.size(), 0);
	for (int i = 1; i < odd_A.size(); i++) {
		if (i > r) odd_A[i] = 0;
		else odd_A[i] = min(r - i, odd_A[2 * p - i]);


		while (i - (odd_A[i] + 1) >= 0 && i + (odd_A[i] + 1) < odd_A.size()
			&& // 위는 배열 범위를 넘어가지 않을 조건, 아래는 팰린드롬의 길이를 늘일 조건
			S[i - (odd_A[i] + 1)] == S[i + (odd_A[i] + 1)]) {
			odd_A[i]++;
		}

		if (r < i + odd_A[i])
		{
			r = i + odd_A[i];
			p = i;
		}

		ans = max(ans, odd_A[i]);
	}

	cout << ans * 2 + 1;

	even_A.resize(S.size(), 0);
	//대칭의 중심을 2개로 잡고, i + 1을 기준으로 잡으므로 odd_A.size()에서 하나를 빼준다
	for (int i = 2; i < odd_A.size() - 1; i++) {
		if ((i + 1) > r)even_A[i] = 0; //i번과 i + 1번을 모두 고려해야하는데 i + 1번을 기준으로 하면 i번은 자동으로 따라오는걸로 취급
		else even_A[i] = min(r- (i + 1), even_A[2 * p - (i + 1)]);

		while ((i + 1) - (even_A[i + 1] + 1) >= 0 && i + (even_A[i] + 1) < even_A.size()
			&& // 위는 배열 범위를 넘어가지 않을 조건, 아래는 팰린드롬의 길이를 늘일 조건
			S[i - (even_A[i] + 1)] == S[i + (even_A[i] + 1)]) {
			even_A[i]++;
		}

		//if (i > r) odd_A[i] = 0;
		//else odd_A[i] = min(r - i, odd_A[2 * p - i]);


		//while (i - (odd_A[i] + 1) >= 0 && i + (odd_A[i] + 1) < odd_A.size()
		//	&& // 위는 배열 범위를 넘어가지 않을 조건, 아래는 팰린드롬의 길이를 늘일 조건
		//	S[i - (odd_A[i] + 1)] == S[i + (odd_A[i] + 1)]) {
		//	odd_A[i]++;
		//}

		//if (r < i + odd_A[i])
		//{
		//	r = i + odd_A[i];
		//	p = i;
		//}

		//ans = max(ans, odd_A[i]);
	}

	return 0;
}

/*
//글자수 홀수로 변경, #삽입법
	cin >> S;
	//if (S.size() %2 == 0) {
	temp = S;

	S.clear();
	S.push_back('#');

	for (int i = 0; i < temp.size(); i++) {
		S.push_back(temp[i]);
		S.push_back('#');
	}
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> getPi(string &p) {
	int j = 0;
	int len = p.size();
	vector<int> pi(len, 0);

	for (int i = 1; i < len; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];

		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}

	return pi;
}

int main(void) {
	int L;
	string panel;
	vector<int> pi;

	cin >> L >> panel;
	
	pi = getPi(panel);
	cout << L - pi[L - 1];

	return 0;
}

// pi배열을 만든다
// bcdabcda가 보일경우
// 실패함수는 각각
// 0 0 0 0 1 2 3 4이다
// 실패 함수중 가장 큰 값까지 잘라서 뒤엣값을 앞으로 붙이면?

//실패함수를 어떻게 활용할 것인가
//처음 문자열을
// 광고 + 뒷꽁무늬로 정해져있다고 가정한다
//abcdabc같은 경우 pi[6]값은 3이고
//4칸 광고에서 d가 짤려있다
//앞의 4개를 광고로 취급할 수 있다
//abaaab의 경우 abaa를 광고로 취급할 수 있다
//다시 abaa를 자르면? pi[4]는 1이고 ba가 남는다?

//abababa같은 경우 pi[6]값은 5이고
//앞의 ab를 광고 취급한다

//aaaaa값은 
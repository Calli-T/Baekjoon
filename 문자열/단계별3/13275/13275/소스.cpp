#include <iostream>
#include <vector>

using namespace std;

int main() {
	string S;
	string temp;
	vector<int> A;
	int ans = 0;
	int r = 0, p = 0;

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
	
	A.resize(S.size(), 0);
	for (int i = 1; i < A.size(); i++) {
		if (i > r) A[i] = 0;
		else A[i] = min(r - i, A[2 * p - i]);
		
					
		while (i - (A[i] + 1) >= 0 && i + (A[i] + 1) < A.size()
			&& // 위는 배열 범위를 넘어가지 않을 조건, 아래는 팰린드롬의 길이를 늘일 조건
			S[i - (A[i] + 1)]  == S[i + (A[i] + 1)]) {
			A[i]++;
		}

		if (r < i + A[i])
		{
			r = i + A[i];
			p = i;
		}

		ans = max(ans, A[i]);
	}
	cout << ans;

	return 0;
}
//자기 이전까지 회문범위 젤큰거 잡고
//그 범위안에 검사하는 위치가 있으면
//중심부 p에 대해 자기 위치의 정반대가 있을거고
//정반대 위치 회문좌우길이 = 검사하는 위치에서회문 좌우길이
//를 이용하되 혹시나 일치할 수있는 최대길이를 넘어가지 않도록
//r - 1과 min으로 제한하고 A[i]초기값구함
//초기값 구하면 무난히 펠린드롬 구하면됨


//+ 홀수개수 펠린드롬만 구할 수 있어서
//문자와 문자사이 #과 문자열 바깥에 #넣으면
//개꿀임, AA가 젤길면 실제론 #A#A#구함

/*
int r = 0;
		int p = 0;
		for (int j = 0; j < i; j++) {
			if (j + A[j] > r) {
				r = j + A[j];
				p = j;
			}
		}

		if (i > r) A[i] = 0;
		else {
			if (2 * p - i > 0)
				A[i] = min(r - i, A[2 * p - i]);
			else A[i] = r - i;
		}

		while (true) {
			if (A[i] + 1 + i > S.size() || i - A[i] - 1 < 0) break;
			if (S[i - A[i]] == S[i + A[i]]) break;
			A[i]++;
		}

		ans = max(ans, A[i]);
*/

// << '\0';
	//맞왜틀?

	/*
	cout << endl;
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	*/

	//}
			//cout << S;
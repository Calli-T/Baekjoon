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
	//A[2 * p - i]��Ʈ�� �� ���ȳ�
	//p�߽ɿ��� i���� �Ÿ� i - p�� p���� ����
	//2p - i
	A.resize(S.size(), 0);
	for (int i = 1; i < A.size(); i++) {
		if (i > r) A[i] = 0;
		else A[i] = min(r - i, A[2 * p - i]);

		while (	i - (A[i] + 1) >= 0 && i - (A[i] + 1) < A.size() && S[i - (A[i] + 1)] == S[i + A[i] + 1]) {
			A[i]++;
		}

		//r = i + A[i]�� �ؾ��Ѵ�
		//�Ǽ��� r < A[i]�� �״�
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
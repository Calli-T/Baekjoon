#include <iostream>
#include <vector>

using namespace std;

struct Q { //Question
	int S; //Start
	int E; //End
};

void setTest(int& N, int& M, vector<int> &number, vector<Q> &list) {
	Q temp;

	cin >> N;
	number.resize(2 * N + 1, -1);//(N);
	for (int i = 0; i < N; i++)
		cin >> number[2 * i + 1];
	cin >> M;
	list.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> temp.S >> temp.E;
		list[i] = temp;
	}

	/*for (int i = 0; i < 2 * N + 1; i++) {
		cout << number[i] << " ";
	}
	cout << endl;*/
}

void setArray(vector<int>& number, vector<int>& A) {
	int r, p;

	r = 0; p = 0;
	A.resize(number.size());
	for (int i = 0; i < A.size(); i++) {
		if (i > r) A[i] = 0;
		else A[i] = min(r - i, A[2 * p - i]);

		while (i - (A[i] + 1) >= 0 && i + (A[i] + 1) < A.size() && number[i - (A[i] + 1)] == number[i + (A[i] + 1)]) {
			A[i]++;
		}

		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	vector<int> number;
	vector<Q> list;
	vector<int> A;
	vector<bool> ans;
	int size;
	int loc;
	int temp;
	
	setTest(N, M, number, list);
	setArray(number, A);
	
	/*for (int i = 0; i < A.size(); i++)
		cout << number[i] << "\t";
	cout << endl;
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << "\t";
	cout << endl;
	for (int i = 0; i < A.size(); i++)
		cout << i << "\t";
	cout << endl;*/


	//ans.resize(list.size(), false);
	for (int i = 0; i < list.size(); i++) {
		size = list[i].E - list[i].S + 1; //문자길이
		loc = list[i].E + list[i].S - 1;
		//loc = (size % 2 == 1) ? list[i].E + list[i].S - 1 : (list[i].E + list[i].S) / 2 * 2;// +1;
		temp = (size % 2 == 1) ? A[loc] + 1 : A[loc];
		
		/*cout << "size: " << size << " ";
		cout << "temp: " << temp << " ";*/
		//cout << "loc: " << loc << endl;
		if (temp >= size) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	//cout << endl;

	//for (int i = 0; i < ans.size(); i++)
		//cout << ans[i] << '\n';

	return 0;
}

//int main() {
//	string S;
//	string temp;
//	vector<int> A;
//	int ans = 0;
//	int r = 0, p = 0;
//
//	//글자수 홀수로 변경, #삽입법
//	cin >> S;
//	//if (S.size() %2 == 0) {
//	temp = S;
//
//	S.clear();
//	S.push_back('#');
//
//	for (int i = 0; i < temp.size(); i++) {
//		S.push_back(temp[i]);
//		S.push_back('#');
//	}
//
//	A.resize(S.size(), 0);
//	for (int i = 1; i < A.size(); i++) {
//		if (i > r) A[i] = 0;
//		else A[i] = min(r - i, A[2 * p - i]);
//
//
//		while (i - (A[i] + 1) >= 0 && i + (A[i] + 1) < A.size()
//			&& // 위는 배열 범위를 넘어가지 않을 조건, 아래는 팰린드롬의 길이를 늘일 조건
//			S[i - (A[i] + 1)] == S[i + (A[i] + 1)]) {
//			A[i]++;
//		}
//
//		if (r < i + A[i])
//		{
//			r = i + A[i];
//			p = i;
//		}
//
//		ans = max(ans, A[i]);
//	}
//	cout << ans;
//
//	return 0;
//}

//for (int i = 0; i < A.size(); i++)
//	cout << A[i] << " ";
//cout << endl;

	//cout << A[loc] << " ";
			//문자열 길이 짝수일 경우와 아닐경우
//if (size % 2 == 0) {
//	if (size <= A[loc] * 2)
//		ans[i] = true;
//}
//else {
//	if (size - 1 <= A[loc] * 2)
//		ans[i] = true;
//}
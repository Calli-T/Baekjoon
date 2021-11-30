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
			&& // ���� �迭 ������ �Ѿ�� ���� ����, �Ʒ��� �Ӹ������ ���̸� ���� ����
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
	//��Ī�� �߽��� 2���� ���, i + 1�� �������� �����Ƿ� odd_A.size()���� �ϳ��� ���ش�
	for (int i = 2; i < odd_A.size() - 1; i++) {
		if ((i + 1) > r)even_A[i] = 0; //i���� i + 1���� ��� ����ؾ��ϴµ� i + 1���� �������� �ϸ� i���� �ڵ����� ������°ɷ� ���
		else even_A[i] = min(r- (i + 1), even_A[2 * p - (i + 1)]);

		while ((i + 1) - (even_A[i + 1] + 1) >= 0 && i + (even_A[i] + 1) < even_A.size()
			&& // ���� �迭 ������ �Ѿ�� ���� ����, �Ʒ��� �Ӹ������ ���̸� ���� ����
			S[i - (even_A[i] + 1)] == S[i + (even_A[i] + 1)]) {
			even_A[i]++;
		}

		//if (i > r) odd_A[i] = 0;
		//else odd_A[i] = min(r - i, odd_A[2 * p - i]);


		//while (i - (odd_A[i] + 1) >= 0 && i + (odd_A[i] + 1) < odd_A.size()
		//	&& // ���� �迭 ������ �Ѿ�� ���� ����, �Ʒ��� �Ӹ������ ���̸� ���� ����
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
//���ڼ� Ȧ���� ����, #���Թ�
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
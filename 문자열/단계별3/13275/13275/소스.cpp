#include <iostream>
#include <vector>

using namespace std;

int main() {
	string S;
	string temp;
	vector<int> A;
	int ans = 0;
	int r = 0, p = 0;

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
	
	A.resize(S.size(), 0);
	for (int i = 1; i < A.size(); i++) {
		if (i > r) A[i] = 0;
		else A[i] = min(r - i, A[2 * p - i]);
		
					
		while (i - (A[i] + 1) >= 0 && i + (A[i] + 1) < A.size()
			&& // ���� �迭 ������ �Ѿ�� ���� ����, �Ʒ��� �Ӹ������ ���̸� ���� ����
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
//�ڱ� �������� ȸ������ ��ū�� ���
//�� �����ȿ� �˻��ϴ� ��ġ�� ������
//�߽ɺ� p�� ���� �ڱ� ��ġ�� ���ݴ밡 �����Ű�
//���ݴ� ��ġ ȸ���¿���� = �˻��ϴ� ��ġ����ȸ�� �¿����
//�� �̿��ϵ� Ȥ�ó� ��ġ�� ���ִ� �ִ���̸� �Ѿ�� �ʵ���
//r - 1�� min���� �����ϰ� A[i]�ʱⰪ����
//�ʱⰪ ���ϸ� ������ �縰��� ���ϸ��


//+ Ȧ������ �縰��Ҹ� ���� �� �־
//���ڿ� ���ڻ��� #�� ���ڿ� �ٱ��� #������
//������, AA�� ����� ������ #A#A#����

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
	//�¿�Ʋ?

	/*
	cout << endl;
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	*/

	//}
			//cout << S;
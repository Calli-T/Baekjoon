#include <iostream>

using namespace std;

struct Trie {
	Trie* ch[26];
	bool end;

	Trie() {
		end = false;
		for (int i = 0; i < 26; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}

	void insert(const char* s) {
		if (!*s) {
			this->end = true;
			return;
		}
		int now = *s - 'A';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}

	bool find(const char* s) {
		if (!*s) {
			if (end) return true;
			return false;
		}
		int now = *s - 'A';
		if (!ch[now]) return false;
		return ch[now]->find(s + 1);
	}
};

int main(void) {
	string s;
	Trie* root = new Trie;
	
	
	cin >> s;
	root->insert(s.c_str());

	string tmp = "AAA";
	if (root->find(tmp.c_str())) cout << "Find!";
	else cout << "No";

	delete root;
	

	return 0;
}



/*
https://rebro.kr/86
*/

//����ü�� �ڽĳ�� ��ŭ�� Trie������ �迭��
//������ �ƴ����� Ȯ���ϴ� bool ������ �ϳ� �ʿ���

//�����ڴ� end�� false��, �ڽĳ�� �迭�� NULL�� �ʱ�ȭ
//�Ҹ��ڴ� �ڽĳ�� �迭�� �� delete

//���Խ�, '\0'�̸� �ش� ��带 true�� ����� return
//���ڿ��� ���̾ƴѰ�� now�� �ش� ���ڸ� ���
//�ش����� �ڽĳ�忡 ���ο� Trie����
//�� �������ڸ� �ش� ��忡 ����

//�˻���, '\0'�� ��츦 ���� Ȯ��
//���� ���, end�� �´����� Ȯ��, ������ true, �ƴϸ� false return
//�ƴҰ��, ���ڴ� ��Ī�Ǵ� ���� now������
//�ڽĳ���� now�� �ش��ϴ� Trie�� �����ϴ��� NULL���� �ƴ��� �˻�,
//������ false return, ������ �ش� �ڽĳ�� �迭��ġ�� s+1�� ���ΰ˻�

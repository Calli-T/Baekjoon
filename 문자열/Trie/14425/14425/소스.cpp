#include <iostream>
#include <vector>
#include <algorithm>

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
		int now = *s - 'a';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}

	bool find(const char* s) {
		if (!*s) {
			if (end) return true;
			return false;
		}
		int now = *s - 'a';
		if (!ch[now]) return false;
		return ch[now]->find(s + 1);
	}
};

int main(void) {
	string temp;
	Trie* root = new Trie;
	int N, M;
	int ans = 0;
	vector<string> arr;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		root->insert(temp.c_str());
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (root->find(temp.c_str()))
			ans++;
	}

	delete root;

	cout << ans;

	return 0;
}

//Ʈ���� 2���� ������ dfs������ ã�ƾ�...�ϳ�?
//���ո���, �־��� ���⵵ Ʈ���̷� ����ٸ� �����Ұ��̴�
//���� Ʈ���� dfs�� ��ȸ�ϸ鼭 ���� ã�Ƴ���, �װŶ�
//���� Ʈ���� dfs�� ���ÿ� ��ȸ�ϸ鼭 ��ġ���� �ʴ� ������ ������ �ڸ���ȴ�

//Ʈ���̸� DFS�� Ž���� ��, ã�ƾ��� ����Ʈ���� �Ұ��ΰ�, ���ڿ� ���̸� �Ұ��ΰ�
//���ڿ���� ������ Ʈ���� ����ٸ�, �ð����⵵�� ���ؾ� O(m)�̹Ƿ� �ð� ���⵵�� ��������
//Ʈ���̷� ������ �����̹Ƿ� ���� S�� ���Ұ��� N�� ���ڿ��� ���� M�� �ִ밪�� ����, ������ �ִ��� �����Ƿ� �������⵵�� ������

//DFS�� �� �� ���ڿ����� Ʈ������ �����Ѵٸ�
//����Ʈ���� ������ �湮Ȯ�ο� �������� ��밡������ ������
//����Ʈ���� ���� ��ȸ�ϸ�
//

/*
	arr.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < M; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	*/
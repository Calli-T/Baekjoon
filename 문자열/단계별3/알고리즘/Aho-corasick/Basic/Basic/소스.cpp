#include <iostream>
#include <queue>

using namespace std;

struct Trie {
	Trie* ch[26];
	Trie* fail;
	bool isEnd;

	Trie() {
		for (int i = 0; i < 26; i++)ch[i] = NULL;
		fail = NULL;
		isEnd = false;
	}
	~Trie() {for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i]; }

	void insert(const char* key) {
		if (*key == '\0') {
			isEnd = true;
			return;
		}
		int next = *key - 'a';
		if (!ch[next]) ch[next] = new Trie;
		ch[next]->insert(key + 1);
	}

};

void makeFail(Trie* root) {
	queue<Trie*> Q;
	root->fail = root;

	Q.push(root);
	while (!Q.empty()) {
		Trie* cur = Q.front();
		Q.pop();

		for (int i = 0; i < 26; i++) {
			Trie* next = cur->ch[i];
			if (!next) continue;
			
			if (cur == root) next->fail = root;
			else {
				Trie* dest = cur->fail;
				//root�� �ƴҶ�, �׸��� dest�� ���ڰ� �������� ���� ��(���Ʋ���°��) �۵�
				while (dest != root && !dest->ch[i])
					dest = dest->fail;
				if (dest->ch[i]) dest = dest->ch[i];
				next->fail = dest;
			}
			//output, Ȥ��isEnd��
			//output��忡 ���� ���� �� �ű� ���� ���ڿ����� ������ �����Ѵٴ� ���� Ȯ��
			//she�� ���и�ũ�� he�� ���°�, he�� ������ �ܾ��� �ݵ�� s'he'�� he�� true�ΰ�
			if (next->fail->isEnd) next->isEnd = true;

			Q.push(next);
		}
	}
}

void search(Trie *root) {
	Trie* cur = root;
	char str[10001];
	cin >> str;
	bool result = false;

	for (int i = 0; str[i]; i++) {
		int next = str[i] - 'a';
		
		while (cur != root && !cur->ch[next])
			cur = cur->fail;
		if (cur->ch[next]) cur = cur->ch[next];

		if (cur->isEnd) {
			result = true;
			break;
		}
	}

	if (result) cout << "YES"; else cout << "NO"; cout << '\n';
}

int main(void) {
	int N, M;
	char str[10001];
	Trie* root = new Trie;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		root->insert(str);
	}

	makeFail(root);

	cin >> M;
	for (int i = 0; i < M; i++) {
		search(root);
		/*cin >> str;
		Trie* cur = root;
		bool result = false;

		for (int c = 0; str[c]; c++) {
			int next = str[c] - 'a';
			//��ġ�� ������, Ȥ�� �ƹ��͵� ���� ������ failź��
			while (cur != root && !cur->ch[next])
				cur = cur->fail;
			//��ġ�ϸ� ������ũ Ÿ�� ��������
			if (cur->ch[next]) cur = cur->ch[next];

			if (cur->isEnd) {
				result = true;
				break;
			}
		}
		if (result) cout << "YES";
		else cout << "NO";
		cout << '\n';*/
	}

	delete root;

	return 0;
}


/*
�˻��Լ�
1. ���� ��ġ, �˻��� ������ġ�� ����
2. ��ġ�ϰų� root�� ������ failź��
3. ��ġ�ϸ� ������ũ ź��
4. output�̸� break�ɰ� ������
*/
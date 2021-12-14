#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Trie {
	Trie* go[26];
	Trie* fail;
	bool output;

	Trie() {
		for (int i = 0; i < 26; i++) go[i] = NULL;
		fail = NULL;
		output = false;
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (go[i]) delete go[i];
	}
	void insert(const char* key) {
		if (*key == '\0') {
			output = true;
			return;
		}
		int next = *key - 'a';
		if (!go[next]) {
			go[next] = new Trie;
		}
		go[next]->insert(key + 1);
	}
};

// ��ó��, �����Լ� ���� 
void makeFail(Trie* root) {
	queue<Trie*> Q;
	root->fail = root;
	Q.push(root);
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		//�ش� ����� ��� �ڽĳ�忡 ����
		for (int i = 0; i < 26; i++) {
			Trie* next = cur->go[i];
			if (!next) continue;

			//��Ʈ�� fail�� root
			if (cur == root) next->fail = root;
			else {
				//��ǥ�� ���ؾ��ϴµ�
				//�θ��� fail�� ó������ �����ؼ�
				Trie* dest = cur->fail;
				// root�� �ƴҶ����� �����Լ��� ���󰡸�, ���ÿ� ���� ����� �ڽĳ�尡 �ش� ��ġ���� ������Ѵ�
				//���� ��� root->s->h, root->h���  ������ s���� �����Լ��� root�� ���� �ش� ����� �ڽĿ� h�� �����ϹǷ� �����
				while (dest != root && !dest->go[i])
					dest = dest->fail;
				//�ش� ��ġ���� ���� �ڽĳ�忡 �ش��ϴ� go�� �����ϰų�, Ȥ�� root�̸�, next->fail�� dest��
				if (dest->go[i]) dest = dest->go[i];
				next->fail = dest;
			}

			// fail(x) = y�� ��, output(y) �� output(x)
			if (next->fail->output) next->output = true;

			//BFS���̾���
			Q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	char str[10001];
	Trie* root = new Trie;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		root->insert(str);
	}

	//fail �Լ� �ۼ�
	makeFail(root);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> str;
		Trie* cur = root;
		bool result = false;

		for (int c = 0; str[c]; c++) {
			int next = str[c] - 'a';
			while (cur != root && !cur->go[next])
				cur = cur->fail;
			if (cur->go[next])
				cur = cur->go[next];

			if (cur->output) {
				result = true;
				break;
			}
		}

		if (result) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}

	delete root;

	return 0;
}
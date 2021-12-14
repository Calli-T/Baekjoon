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

// 전처리, 실패함수 제작 
void makeFail(Trie* root) {
	queue<Trie*> Q;
	root->fail = root;
	Q.push(root);
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		//해당 노드의 모든 자식노드에 대해
		for (int i = 0; i < 26; i++) {
			Trie* next = cur->go[i];
			if (!next) continue;

			//루트의 fail은 root
			if (cur == root) next->fail = root;
			else {
				//목표를 정해야하는데
				//부모의 fail를 처음으로 시작해서
				Trie* dest = cur->fail;
				// root가 아닐때까지 실패함수를 따라가며, 동시에 현재 노드의 자식노드가 해당 위치에서 없어야한다
				//예를 들어 root->s->h, root->h라면  현재노드 s에서 실패함수인 root로 가서 해당 노드의 자식에 h가 존재하므로 멈춘다
				while (dest != root && !dest->go[i])
					dest = dest->fail;
				//해당 위치에서 현재 자식노드에 해당하는 go가 존재하거나, 혹은 root이면, next->fail은 dest다
				if (dest->go[i]) dest = dest->go[i];
				next->fail = dest;
			}

			// fail(x) = y일 때, output(y) ⊂ output(x)
			if (next->fail->output) next->output = true;

			//BFS식이었다
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

	//fail 함수 작성
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
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
	
	/*for (int i = 0; i < M; i++) {
		cin >> temp;
		if (root->find(temp.c_str()))
			ans++;
	}*/
	arr.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < M; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	delete root;
	//트라이 2개를 가지고 dfs식으로 찾아야...하나?

	cout << ans;

	return 0;
}
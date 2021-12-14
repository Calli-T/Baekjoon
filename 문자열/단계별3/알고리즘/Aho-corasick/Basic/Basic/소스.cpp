#include <iostream>
#include <queue>

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
		auto cur = Q.front();
		Q.pop();

		for(int i = 0;  i< 26;)
	}

}


using namespace std;

int main(void) {

	return 0;
}
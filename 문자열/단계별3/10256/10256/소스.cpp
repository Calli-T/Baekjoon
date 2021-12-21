#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct Trie {
	Trie* ch[26];
	Trie* fail;
	bool isEnd;

	Trie() {
		for (int i = 0; i < 26; i++) ch[i] = NULL;
		fail = NULL;
		isEnd = false;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			isEnd = true;
			return;
		}
		int next = *key - 'A';
		if (!ch[next]) ch[next] = new Trie;
		ch[next]->insert(key + 1);
	}
};

void getFail(Trie* root) {
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
				while (dest != root && !dest->ch[i])
					dest = dest->fail;
				if (dest->ch[i])
					dest = dest->ch[i];
				next->fail = dest;
			}
			if (next->fail->isEnd) next->isEnd = true;
			Q.push(next);
		}
	}

}

int makeUsWhole() {
	int N, M;
	string DNA;
	string blackMarker;
	//string temp;
	string mutant;
	//vector<string> redMarker;
	Trie* redMarker = new Trie; // root;
	int ans = 0;

	cin >> N >> M;
	cin >> DNA;
	cin >> blackMarker;

	//돌연변이를 포함한 마커 Trie제작
	for (int i = 2; i < N; i++) {
		for (int j = 0; i + j < N - 1; j++) {
			//temp = blackMarker.substr(j, i);
			//reverse(temp.begin(), temp.end());
			//cout << temp << " ";
			mutant = blackMarker;
			reverse(mutant.begin() + j, mutant.begin() + j + i);
			//cout << mutant << " ";
			redMarker->insert(mutant.c_str());
		}
		//cout << endl;
	}
	getFail(redMarker);

	//------------------------------------search-----------
	Trie* cur = redMarker;

	for (int i = 0; i < N; i++) {
		cout << "무야호" << endl;
		int next = blackMarker[i] - 'A';

		while (cur != redMarker && !cur->ch[next])
			cur = cur->fail;
		if (cur->ch[next])cur = cur->ch[next];
		if (cur->isEnd) {
			ans++;
			//break;
		}
	}

	//-----------------------------------------------------

	delete redMarker;

	return ans;
}

int main(void) {
	vector<int> ans;
	int T;

	cin >> T;
	for(int i = 0; i < T; i++) {
		ans.push_back(makeUsWhole());
	}

	for (int i = 0; i < T; i++) cout << ans[i] << '\n';

	return 0;
}

/*
1
6 4
ATGGAT
AGGT
*/

//하나를 발견하면 발견한 위치 다음에서 그대로 다시 찾는것이 중요하다
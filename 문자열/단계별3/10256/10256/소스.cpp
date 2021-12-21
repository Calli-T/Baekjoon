#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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

int search(Trie* root, string &DNA, int start, int M) {
	Trie* cur = root;
	//const char* str = DNA.c_str();
	bool result = false;
	int i;
	
	for (i = start; i < DNA.size(); i++) {
		int next = DNA[i] - 'A';

		while (cur != root && !cur->ch[next])
			cur = cur->fail;
		if (cur->ch[next]) cur = cur->ch[next];

		if (cur->isEnd) {
			result = true;
			break;
		}
	}
	if (result) {
		return i - M + 2;
	}
	return -1;
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

	redMarker->insert(blackMarker.c_str());
	//�������̸� ������ ��Ŀ Trie����
	for (int i = 2; i <= M; i++) { //������ ����
		for (int j = 0;  j + (i - 1) < M; j++) { // ������ġ�������� ������ ������ ���ڼ��� �Ѿ���� �ȵ�
			//temp = blackMarker.substr(j, i);
			//reverse(temp.begin(), temp.end());
			//cout << temp << " ";
			mutant = blackMarker;
			reverse(mutant.begin() + j, mutant.begin() + j + i);
			redMarker->insert(mutant.c_str());
			//cout << mutant << " ";
		}
		//cout << endl;
	}
	getFail(redMarker);

	//------------------------------------search-----------
	int st = 0;
	while (true) {
		st = search(redMarker, DNA, st, M);
		if (st == -1) break;
		ans++;
	}
	//cout << search(redMarker, DNA, 0) << '\n';
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
6 2
ATGGAT
AG

2
6 4
ATGGAT
AGGT
6 4
ATGGAT
AGCT

1
6 4
ATGGAT
AGGT
*/
//
//�ϳ��� �߰��ϸ� �߰��� ��ġ �������� �״�� �ٽ� ã�°��� �߿��ϴ�
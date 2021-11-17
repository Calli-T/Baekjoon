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

//트라이 2개를 가지고 dfs식으로 찾아야...하나?
//집합말고, 주어진 보기도 트라이로 만든다면 가능할것이다
//기존 트리를 dfs로 순회하면서 답을 찾아내고, 그거랑
//보기 트리를 dfs에 동시에 순회하면서 일치하지 않는 라인은 모조리 자르면된다

//트라이를 DFS로 탐색할 때, 찾아야할 집합트리를 할것인가, 문자열 더미를 할것인가
//문자열들로 새로이 트리를 만든다면, 시간복잡도는 끽해야 O(m)이므로 시간 복잡도는 걱정없다
//트라이로 가능한 문제이므로 집합 S의 원소개수 N과 문자열의 개수 M는 최대값이 같고, 길이의 최댓값이 같으므로 공간복잡도도 괜찮다

//DFS를 할 때 문자열들의 트리에서 시행한다면
//원본트리를 일종의 방문확인용 집합으로 사용가능하지 않을까
//원본트리도 같이 순회하며
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
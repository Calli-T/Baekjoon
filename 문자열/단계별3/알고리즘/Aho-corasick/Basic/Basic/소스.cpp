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
				//root가 아닐때, 그리고 dest의 문자가 존재하지 않을 때(계속틀리는경우) 작동
				while (dest != root && !dest->ch[i])
					dest = dest->fail;
				if (dest->ch[i]) dest = dest->ch[i];
				next->fail = dest;
			}
			//output, 혹은isEnd는
			//output노드에 도달 했을 때 거기 적힌 문자열들이 원문에 등장한다는 것이 확정
			//she의 실패링크로 he를 보냈고, he가 완전한 단어라면 반드시 s'he'의 he도 true인것
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

void advancedSearch(Trie* root) {
	Trie* cur = root;
	char str[10001];
	cin >> str;
	bool result = false;
	int i;
	int length = 0;

	for (i = 0; str[i]; i++) {
		int next = str[i] - 'a';

		while (cur != root && !cur->ch[next]) {
			cur = cur->fail;
		}
		if (cur->ch[next]) {
			cur = cur->ch[next];
			length++;
		}
		else
			length = 0;

		if (cur->isEnd) {
			result = true;
			break;
		}
	}

	if (result) {
		cout << "YES";
		cout << " 위치: " << i - length + 1; // i;
		cout << ", 길이: " << length;
		
		cout << ", 단어: ";
		for (int st = 0; st < length; st++) {
			cout << str[i - length + 1 + st];
		}
	}
	else
		cout << "NO";

	cout << '\n';
	
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
		//search(root);
		advancedSearch(root);
	}

	delete root;

	return 0;
}


/*
검색함수
1. 현재 위치, 검사할 패턴위치를 제작
2. 일치하거나 root갈 때까지 fail탄다
3. 일치하면 성공링크 탄다
4. output이면 break걸고 존재함
*/

/*
검색함수
문자열 작성 및 전체 순회
cur는 부모의 fail을 미리 쭉탐(일치하는거 맞춤)
root가 아니고, cur->ch[next]가 존재하지 않을 때까지 즉 접두어에서 다음 글자가, 현재 글자가 나오는 때까지 가야함
cur->ch[next]존재하면 따라 내려가고, 거기서 output이면 존재한다는 뜻이니 멈추고 cout

*/

/*
3
www
woo
jun
3
myungwoo
hongjun
dooho

4
www
woo
jun
ooh
3
myungwoo
hongjun
dooho

3
www
woo
jun
3
myuwongwoo
hongjun
dooho

3
www
woo
jun
3
myuwwoo
hongjun
dooho

3
www
woo
jun
3
myuwoogwoo
hongjun
dooho
*/
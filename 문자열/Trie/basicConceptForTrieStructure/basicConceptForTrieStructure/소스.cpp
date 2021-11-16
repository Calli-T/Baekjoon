#include <iostream>

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
		int now = *s - 'A';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}

	bool find(const char* s) {
		if (!*s) {
			if (end) return true;
			return false;
		}
		int now = *s - 'A';
		if (!ch[now]) return false;
		return ch[now]->find(s + 1);
	}
};

int main(void) {
	string s;
	Trie* root = new Trie;
	
	
	cin >> s;
	root->insert(s.c_str());

	string tmp = "AAA";
	if (root->find(tmp.c_str())) cout << "Find!";
	else cout << "No";

	delete root;
	

	return 0;
}



/*
https://rebro.kr/86
*/

//구조체는 자식노드 만큼의 Trie포인터 배열과
//끝인지 아닌지를 확인하는 bool 변수가 하나 필요함

//생성자는 end를 false로, 자식노드 배열을 NULL로 초기화
//소멸자는 자식노드 배열을 싹 delete

//삽입시, '\0'이면 해당 노드를 true로 만들고 return
//문자열의 끝이아닌경우 now로 해당 문자를 잡고
//해당노드의 자식노드에 새로운 Trie생성
//후 다음문자를 해당 노드에 삽입

//검색시, '\0'일 경우를 먼저 확인
//맞을 경우, end가 맞는지를 확인, 맞으면 true, 아니면 false return
//아닐경우, 문자는 매칭되는 숫자 now로잡음
//자식노드의 now에 해당하는 Trie가 존재하는지 NULL인지 아닌지 검색,
//없으면 false return, 있으면 해당 자식노드 배열위치로 s+1을 새로검색

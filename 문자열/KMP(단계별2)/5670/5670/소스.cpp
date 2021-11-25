#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Trie {
	Trie* ch[26];
	bool end;

	Trie() {
		for (int i = 0; i < 26; i++) ch[i] = NULL;
		end = false;
	}

	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}

	void insert(const char* s) {
		if (!*s) {
			end = true;
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
	
	bool hasOnlyLetter() {
		bool hasOne = false;
		for (int i = 0; i < 26; i++) {
			if (ch[i]) {
				if (!hasOne) hasOne = true;
				else return false;
			}
		}
		return hasOne;
	}

	int getOnlyLetter() {
		int onlyLetter = -1;
		for (int i = 0; i < 26; i++) {
			if (ch[i]) {
				if (onlyLetter < 0) onlyLetter = i;
				else return -1;
			}
		}
		return onlyLetter;
	}



	//--------------------------------이 사이로 작성해보자---------------------------------------------------------

	//한 함수에서 모두 처리하는게 가능한지 시도해볼것
	//꽤 답에 근접했지만
	//getOnlyLetter로 찾는다고 해도
	//해당 깊이에서만 같고 접두어가 다른 단어의 개수를 모두 셀 수 없다
	//예를 들어, hello과 hello와 heaven에서
	//h는 첫글자니까 +1, e는 공통이므로 +0
	//l을 입력해야하므로 +1
	// l은 공통이라 +0
	//그러나 접미어 o가 붙을지 안붙을지는 알 수 없다
	//그러므로 o는 +1이라 hello는 3번인데,
	//기존 함수에 걸려 2번으로 처리된다

	int getInputs(const char* s) {
		int next = *s - 'a';
		int unique;
		Trie* cur = this->ch[next];
		int count = 1; //무조건 1글자는 타이핑
		for (s++; *s; s++) {
			unique = cur->getOnlyLetter();
			if (unique == -1) {
				count++;
			}
			else {
				//거의 다 만들었고, 평균내는걸 만들자
				if (cur->end) count++;
			}

			next = *s - 'a';
			cur = cur->ch[next];

			//cout << next << endl;
		}
		//cout << count << endl;
		//cout << cur->getOnlyLatter() << endl;
		return count;
	}









	//--------------------------------이 사이로 작성해보자---------------------------------------------------------

};

int N;
vector<string> dictionary;
Trie* root;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double sum;

	while (true) {
		//사전 초기화
		dictionary.clear();
		
		cin >> N;

		if (cin.eof() == true)break;
		
		dictionary.resize(N);
		for (int i = 0; i < N; i++)
			cin >> dictionary[i];

		//루트노드생성
		root = new Trie;
		//트라이 구성
		for (int i = 0; i < N; i++)
			root->insert(dictionary[i].c_str());
		
		sum = 0;
		for (int i = 0; i < N; i++) {
			sum += root->getInputs(dictionary[i].c_str());
		}
		sum /= N;
		//반올림 나중에 구현할것
		sum = round(sum * 100) / 100;
		cout << fixed;
		cout.precision(2);

		cout << sum << '\n';
		
		//루트노드 삭제
		delete root;
	}

	/*
	* cout << fixed;
		cout.precision(2);
	*/

	return 0;
}

/*
for (int i = 0; i < N; i++) {
			Trie* temp = root->ch[dictionary[i][0]];
			string substr = dictionary[i].substr(1);
			//cout << "substr: " << substr << '\n';
			cout <<temp->countInput(substr.c_str()) << endl;
		}
*/

//간단히말해서, 입력을 뭐라도 하면
//그걸 접두사로 하는 단어들이 그 다음이 모두 겹칠경우
//그걸 생략하고 자동입력해주는 모듈이다
// hello, hello
// h를 친시점에서 e가, l을 친 시점에서 l이 자동으로 튀어나온다

// 일단 무지성 트라이 자료구조부터 만들고 생각하자

//테스트
//cout << root->ch[7]->getOnlyLatter() << endl;

//해당함수는 해당 노드에 자식노드가 1개임을 확인한다
//0개나 2개이상은 얄짤없이 false
//cout << root->hasOnlyLatter() << endl;


//입력횟수는 find 함수 개조
//일단 단어가 없을 일이 없음, if(!*s)의 false반환 필요x
/*재귀식으로 합을 내서 반환, 1에서 시작
0. 1에서 시작하려면, root에서 시작하는게 아니고
시작위치를'root->해당 첫글자'로 둘 필요가 있다
1. 글자의 끝, 즉 '\0'문자라면 0을 반환
2. 끝이 아니라면 해당 문자의 자식노드 개수가 1개인지 살펴봄
3. 자식노드의 개수가 1개가 아니라면,
for문으로 노드를 싹 훑은걸 리턴해서 반환
자식 노드의 개수가 1개라면, 해당 노드를 매개변수로 재귀
*/


/* 오답 1
int countInput(const char *s) {
		if (!*s) {
			return 0;
		}
		int onlyLetter = getOnlyLatter();
		if (onlyLetter == - 1) {
			return countInput(s + 1);
		} else
			return 1 + countInput(s + 1);
	}
*/

/*
int countInput(const char* s) {
		if (!*s) {
			return 0;
		}
		int now = *s - 'a';
		if (!hasOnlyLatter()) {
			return 1+ ch[now]->countInput(s + 1);
		}
		else {
			return ch[now]->countInput(s + 1);
		}
	}
*/
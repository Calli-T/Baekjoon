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



	//--------------------------------�� ���̷� �ۼ��غ���---------------------------------------------------------

	//�� �Լ����� ��� ó���ϴ°� �������� �õ��غ���
	//�� �信 ����������
	//getOnlyLetter�� ã�´ٰ� �ص�
	//�ش� ���̿����� ���� ���ξ �ٸ� �ܾ��� ������ ��� �� �� ����
	//���� ���, hello�� hello�� heaven����
	//h�� ù���ڴϱ� +1, e�� �����̹Ƿ� +0
	//l�� �Է��ؾ��ϹǷ� +1
	// l�� �����̶� +0
	//�׷��� ���̾� o�� ������ �Ⱥ������� �� �� ����
	//�׷��Ƿ� o�� +1�̶� hello�� 3���ε�,
	//���� �Լ��� �ɷ� 2������ ó���ȴ�

	int getInputs(const char* s) {
		int next = *s - 'a';
		int unique;
		Trie* cur = this->ch[next];
		int count = 1; //������ 1���ڴ� Ÿ����
		for (s++; *s; s++) {
			unique = cur->getOnlyLetter();
			if (unique == -1) {
				count++;
			}
			else {
				//���� �� �������, ��ճ��°� ������
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









	//--------------------------------�� ���̷� �ۼ��غ���---------------------------------------------------------

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
		//���� �ʱ�ȭ
		dictionary.clear();
		
		cin >> N;

		if (cin.eof() == true)break;
		
		dictionary.resize(N);
		for (int i = 0; i < N; i++)
			cin >> dictionary[i];

		//��Ʈ������
		root = new Trie;
		//Ʈ���� ����
		for (int i = 0; i < N; i++)
			root->insert(dictionary[i].c_str());
		
		sum = 0;
		for (int i = 0; i < N; i++) {
			sum += root->getInputs(dictionary[i].c_str());
		}
		sum /= N;
		//�ݿø� ���߿� �����Ұ�
		sum = round(sum * 100) / 100;
		cout << fixed;
		cout.precision(2);

		cout << sum << '\n';
		
		//��Ʈ��� ����
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

//���������ؼ�, �Է��� ���� �ϸ�
//�װ� ���λ�� �ϴ� �ܾ���� �� ������ ��� ��ĥ���
//�װ� �����ϰ� �ڵ��Է����ִ� ����̴�
// hello, hello
// h�� ģ�������� e��, l�� ģ �������� l�� �ڵ����� Ƣ��´�

// �ϴ� ������ Ʈ���� �ڷᱸ������ ����� ��������

//�׽�Ʈ
//cout << root->ch[7]->getOnlyLatter() << endl;

//�ش��Լ��� �ش� ��忡 �ڽĳ�尡 1������ Ȯ���Ѵ�
//0���� 2���̻��� ��©���� false
//cout << root->hasOnlyLatter() << endl;


//�Է�Ƚ���� find �Լ� ����
//�ϴ� �ܾ ���� ���� ����, if(!*s)�� false��ȯ �ʿ�x
/*��ͽ����� ���� ���� ��ȯ, 1���� ����
0. 1���� �����Ϸ���, root���� �����ϴ°� �ƴϰ�
������ġ��'root->�ش� ù����'�� �� �ʿ䰡 �ִ�
1. ������ ��, �� '\0'���ڶ�� 0�� ��ȯ
2. ���� �ƴ϶�� �ش� ������ �ڽĳ�� ������ 1������ ���캽
3. �ڽĳ���� ������ 1���� �ƴ϶��,
for������ ��带 �� ������ �����ؼ� ��ȯ
�ڽ� ����� ������ 1�����, �ش� ��带 �Ű������� ���
*/


/* ���� 1
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
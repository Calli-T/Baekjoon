#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>

using namespace std;

vector<vector<string>> underground;
set<string> food;
map<string, int> matchFood;
map<int, string> matchNumber;
int N;

struct Trie {
	vector<Trie*> ch;
	//Trie* ch[15000];
	bool end;

	Trie() {
		end = false;
		ch.resize(matchFood.size());
		for (int i = 0; i < matchFood.size(); i++)
			ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < matchFood.size(); i++)
			if (ch[i])delete ch[i];
	}

	void insert(int line, int cur) {
		if (cur == underground[line].size()) {
			this->end = true;
			return;
		}
		int now = matchFood.find(underground[line][cur])->second;
		if(!ch[now]) ch[now] = new Trie;
		ch[now]->insert(line, cur + 1);
	}

};
Trie* root;

void setUnderground() {
	int number = 0;
	string temp;
	int j;

	cin >> N;
	underground.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> j;

		while (j--) {
			cin >> temp;
			underground[i].push_back(temp);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < underground[i].size(); j++)
			food.insert(underground[i][j]);
	}

	for (auto it = food.begin(); it != food.end(); it++) {
		matchFood.insert({ *it, number++ });
		matchNumber.insert({ number, *it });
	}

}

void prtAllNode(Trie* now, int depth) {
	for (int i = 0; i < matchFood.size(); i++) {
		if (now->ch[i] != NULL) {
			for (int i = 0; i < depth; i++)
				cout << "--";
			cout << matchNumber.find(i+1)->second << '\n';

			prtAllNode(now->ch[i], depth + 1);
		}
	}
}

int main(void) {

	
	setUnderground();
	root = new Trie();
	
	for (int i = 0; i < N; i++) {
		root->insert(i, 0);
	}
	//cout << matchNumber.find(4)->second;
	prtAllNode(root, 0);
	

	return 0;
}

/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < floor[i].size(); j++)
			cout << floor[i][j] << " ";
		cout << '\n';
	}*/

	/*for (auto it = food.begin(); it != food.end(); it++)
			cout << *it << " ";
		cout << '\n';*/

		/*for (auto it = matchFood.begin(); it != matchFood.end(); it++)
				cout << it->first << " " << it->second<< '\n';
			cout << '\n';*/
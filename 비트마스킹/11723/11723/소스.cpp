#include <iostream>
#include <string>
#include <vector>

using namespace std;

int M, num, BIT;
string input;
vector<int> answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;
	while (M--) {
		input.clear();
		cin >> input;

		if (input == "add") {
			cin >> num;
			BIT |= (1 << num);
		}
		else if (input == "remove") {
			cin >> num;
			BIT &= ~(1 << num);
		}
		else if (input == "check") {
			cin >> num;
			if (BIT & (1 << num)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(input == "toggle"){
			cin >> num;
			BIT ^= (1 << num);
		}
		else if (input == "all") {
			BIT = (1 << 21) - 1;
		}
		else if (input == "empty") {
			BIT = 0;
		}
	}

	return 0;
}

/*
#include <iostream>
#include <bitset>
#include <vector>
#include <sstream>

using namespace std;

bitset<20> binNum(0);
bitset<20> bitOne(1);

void addBit(int x);
void removeBit(int x);
bool checkBit(int x);
void toggleBit(int x);
void allBit();
void emptyBit();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	string tempOperator, tempOperand;
	vector <bool> answer;

	cin >> M;
	while (M--) {
		cin >> tempOperator;
		
		if (tempOperator == "empty")
			emptyBit();
		else if (tempOperator == "all")
			allBit();
		else {
			cin >> tempOperand;

			if (tempOperator == "add")
				addBit(stoi(tempOperand));
			else if (tempOperator == "remove")
				removeBit(stoi(tempOperand));
			else if (tempOperator == "toggle")
				toggleBit(stoi(tempOperand));
			else
				answer.push_back(checkBit(stoi(tempOperand)));
		}

	}

	for (int i = 0; i < (int)answer.size(); i++)
		cout << (answer[i] ? 1 : 0) << '\n';

	return 0;
}

void addBit(int x) {
	binNum |= (bitOne << ( x-1));
}
void removeBit(int x) {
	binNum &= ~(bitOne << (x - 1));
}

void toggleBit(int x) {
	binNum ^= (bitOne << (x - 1));
}

void allBit() {
	binNum.set();
}

void emptyBit() {
	binNum.reset();
}

bool checkBit(int x) {
	return (binNum & (bitOne << (x - 1))).to_ulong();
}*/

/*
vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}
*/
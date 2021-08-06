#include <vector>
#include <iostream>

using namespace std;

int main(void) {

	vector<vector<int>> DP;
	vector<int> column;
	string str1, str2;
	int ans = 0;

	cin >> str1 >> str2;

	column.resize(str2.size() + 1, 0);
	DP.resize(str1.length() + 1, column);

	for (int i = 1; i < str1.size()+1; i++) {
		for (int j = 1; j < str2.size()+1; j++) {
			if (str1[i-1] == str2[j-1]) {
				DP[i][j] = DP[i-1][j-1] + 1;
				
				
			}
			else {
				//cout << str1[i] << str2[j] << endl;
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
				//cout << DP[i][j];
				//if (DP[i][j] > 0) cout << "무야호";
			}
		}
	}

	
	/*
	for (int j = 0; j < str2.size(); j++) {
		for (int i = 0; i < str1.size(); i++) {

			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	cout << DP[str1.size()][str2.size()];

	return 0;
}


/*
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int main(void) {

	pair<string, pair<int, int>> substr;
	vector<vector<pair<string, pair<int, int>>>> DP;
	string str1, str2;
	int ans = 0;

	cin >> str1 >> str2;

	DP.resize(str1.length());

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (str1[i] == str2[j]) {
				substr.first = str1[i];
				substr.second.first = i;
				substr.second.second = j;
				DP[0].push_back(substr);
				break;
			}
		}
	}
	if (DP[0].size() > 0) ans++;

	
	for (int i = 1; i < DP.size(); i++) { // DP.size(); i++) {
		for (int j = 0; j < DP[i - 1].size(); j++) {
			//cout << DP[i - 1][j].first << " " << DP[i - 1][j].second << " ";
			for (int k = DP[i - 1][j].second.first + 1; k < str1.size(); k++) {
				for (int l = DP[i - 1][j].second.second + 1; l < str1.size(); l++) {
					//cout << str1[k] << " " << str2[l] << "	";
					if (str1[k] == str2[l]) {
						substr.first = str1[k];// DP[i - 1][j].second.first + str1[k];
						substr.second.first = k;
						substr.second.second = l;
						DP[i].push_back(substr);
						break;
					}

				}
				//cout << endl;
			}
			
		}
		if (DP[i].size() > 0) {
			ans++;
			DP[i - 1].clear();
		//	cout << DP[i].size() << endl;
		}
		else break;

		//cout << endl;
	}	

	for (int i = 0; i < DP.size(); i++) {
		for (int j = 0; j < DP[i].size(); j++) {
			cout << DP[i][j].first << " " << DP[i][j].second.first << " " << DP[i][j].second.second << "	";
		}
		cout << endl;
	}

	cout << ans;

	return 0;
}
*/

/*
ACAYKP
CAPCAK
*/

/*
ACAYKPCAPCAKCAPCAKACAYKP
CAPCAKACAYKPACAYKPCAPCAK
*/

// LIS와 유사하게 처리할 수 있을것인가?
// DP식으로 생각하자면, 대응하는 문자열 길이를 하나씩늘여나가는 방법은 적합한가
// 1에선 첫 문자열의 시작부터 한 개의 문자가 두 번째 문자열에 존재하는지
// 2에선.... 

// 전선 문제와 유사하게 처리가 가능한지?
// 첫 문자가 뒷 문자열의 문자에서 발견되면 처음 발견된 위치를 기억하고
// 두 번째 문자가는 첫 번째 문자가 발견된 그 뒤의 위치부터 찾고...

// 2번째 플랜에서, i - 1번까지의 동일한 부분 수열에서
// 하나를 더 해 i번째 문자와 같은것을 뒷 문자열에서 찾아서 붙이고...

// 만약, i-1번째까지의 LCS가 ABC라면 A를 떼버리고 BC로 시작하는 LCS가 존재할 것인가?
// 만약, ABC에서 A가 3번째 위치고, B가 2,4에 있었는데 A를 떼버린다면 B를 4에서 2로 옮길 수 있다,
// 이것은 무엇을 의미하는가?

// 1개가 겹치는 LCS후보의 위치를 기록해놨다가, 2개짜리 LCS후보를 구할 때 사용가능할 것인가?
// ACAYKP에서
// 첫 A가 두 번째 문자열에서 끝나는 위치를 기억해 AC, AA, AY등을 만들어 낼것인가...
// 각 단계에서 존재할 수 있는 후보을 나열하자면
/*
1단계 : A, C, (A), Y, K, P
2단계 : AC, AA, AY, AK, AP/CA, CY, CK, CP/AY, AK, AP/YK, YP/KP
3단계 : ACA, ACY, ACK, ACP/AAY, AAK, AAP/AYK, AYP/ AKP
		CAY, CAK, CAP/CYK, CYP/ CKP
		AYK, AYP/AKP
		YKP
*/
// 모든 경우의 수를 나열해놓고, 해당 값이 존재 가능한지
// 가능하다면 그 부분문자열의 끝은 2번째 문자열 기준어디에서 끝나는지를 기록해야한다
// 첫단계의 배열의 각 값은 다음 단계의 배열에 어디까지 영향을 끼칠것인가?
// A는 AC부터 AP까지 5개가 가능한데, A에서 P로 갈수록 선택지가 줄어드므로 i단계에서는 N-i ~ 1까지의 선택지가 주어진다
// i단계에서, 배열의 길이는 nCi의 길이이다

// 한 가지 문제가 생겼는데, 문자열이 최대 1000자이고 배열 개수를 1000 C 500까지 만들 수는 없다
// 따라서, 각 단계에서 존재하는지 판단을 하고 없으면 없애버려야한다

/*
알고리즘 단계
1. 벡터의 크기를 단계 수에 맞춘다, 단계는 몇개의 문자열이 일치할 것인지의 개수이다.
2. 해당 단계까지 순환한다
3. i단계에선 문자가 i개인 문자열이 일치하는곳과, 그 문자열이 끝나는 위치를 벡터에 삽입한다
3. 해당 단계에서 단 하나라도 문자열이 삽입된다면 정답에 하나를 추가하고
4. 그렇지 않는 순간이 온다면 종료한다
*/
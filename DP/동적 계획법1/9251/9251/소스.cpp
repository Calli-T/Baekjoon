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
				//if (DP[i][j] > 0) cout << "����ȣ";
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

// LIS�� �����ϰ� ó���� �� �������ΰ�?
// DP������ �������ڸ�, �����ϴ� ���ڿ� ���̸� �ϳ����ÿ������� ����� �����Ѱ�
// 1���� ù ���ڿ��� ���ۺ��� �� ���� ���ڰ� �� ��° ���ڿ��� �����ϴ���
// 2����.... 

// ���� ������ �����ϰ� ó���� ��������?
// ù ���ڰ� �� ���ڿ��� ���ڿ��� �߰ߵǸ� ó�� �߰ߵ� ��ġ�� ����ϰ�
// �� ��° ���ڰ��� ù ��° ���ڰ� �߰ߵ� �� ���� ��ġ���� ã��...

// 2��° �÷�����, i - 1�������� ������ �κ� ��������
// �ϳ��� �� �� i��° ���ڿ� �������� �� ���ڿ����� ã�Ƽ� ���̰�...

// ����, i-1��°������ LCS�� ABC��� A�� �������� BC�� �����ϴ� LCS�� ������ ���ΰ�?
// ����, ABC���� A�� 3��° ��ġ��, B�� 2,4�� �־��µ� A�� �������ٸ� B�� 4���� 2�� �ű� �� �ִ�,
// �̰��� ������ �ǹ��ϴ°�?

// 1���� ��ġ�� LCS�ĺ��� ��ġ�� ����س��ٰ�, 2��¥�� LCS�ĺ��� ���� �� ��밡���� ���ΰ�?
// ACAYKP����
// ù A�� �� ��° ���ڿ����� ������ ��ġ�� ����� AC, AA, AY���� ����� �����ΰ�...
// �� �ܰ迡�� ������ �� �ִ� �ĺ��� �������ڸ�
/*
1�ܰ� : A, C, (A), Y, K, P
2�ܰ� : AC, AA, AY, AK, AP/CA, CY, CK, CP/AY, AK, AP/YK, YP/KP
3�ܰ� : ACA, ACY, ACK, ACP/AAY, AAK, AAP/AYK, AYP/ AKP
		CAY, CAK, CAP/CYK, CYP/ CKP
		AYK, AYP/AKP
		YKP
*/
// ��� ����� ���� �����س���, �ش� ���� ���� ��������
// �����ϴٸ� �� �κй��ڿ��� ���� 2��° ���ڿ� ���ؾ�𿡼� ���������� ����ؾ��Ѵ�
// ù�ܰ��� �迭�� �� ���� ���� �ܰ��� �迭�� ������ ������ ��ĥ���ΰ�?
// A�� AC���� AP���� 5���� �����ѵ�, A���� P�� ������ �������� �پ��Ƿ� i�ܰ迡���� N-i ~ 1������ �������� �־�����
// i�ܰ迡��, �迭�� ���̴� nCi�� �����̴�

// �� ���� ������ ����µ�, ���ڿ��� �ִ� 1000���̰� �迭 ������ 1000 C 500���� ���� ���� ����
// ����, �� �ܰ迡�� �����ϴ��� �Ǵ��� �ϰ� ������ ���ֹ������Ѵ�

/*
�˰��� �ܰ�
1. ������ ũ�⸦ �ܰ� ���� �����, �ܰ�� ��� ���ڿ��� ��ġ�� �������� �����̴�.
2. �ش� �ܰ���� ��ȯ�Ѵ�
3. i�ܰ迡�� ���ڰ� i���� ���ڿ��� ��ġ�ϴ°���, �� ���ڿ��� ������ ��ġ�� ���Ϳ� �����Ѵ�
3. �ش� �ܰ迡�� �� �ϳ��� ���ڿ��� ���Եȴٸ� ���信 �ϳ��� �߰��ϰ�
4. �׷��� �ʴ� ������ �´ٸ� �����Ѵ�
*/
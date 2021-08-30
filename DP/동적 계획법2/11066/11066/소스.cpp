#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int Dynamic() {
	int K, temp;
	vector<int> file;
	vector<int> sum;
	vector<vector<int>> DP;

	file.push_back(0);
	sum.push_back(0);
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		file.push_back(temp);
		sum.push_back(sum[i] + temp);
	}

	DP.resize(K + 1);
	for (int i = 0; i < K + 1; i++)
		DP[i].resize(K + 1, 0);

	/*
	for (int i = 0; i < file.size(); i++) {
		cout << file[i] << " ";
	}
	cout << endl;
	*/
	/*
	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i] << " ";
	}
	cout << endl;
	*/
	
	//행, 길이
	for (int i = 1; i <= K; i++) {
		//열, 어디서부터 어디까지인가, i+j의 합은 항상 K까지, j는 시작점, i와 j의 합은 최소 2, j가 시작점
		for (int j = 1; j <= K - i; j++) {
			//위에서부터 min값을 찾기위해 임시로 max값처리
			DP[j][i + j] = INF;
			//좌우의 합을 가를 k
			for (int k = j; k < i + j; k++) {
				//기존 값과
				//k로 나눈 좌우 DP값의 합과, j부터 i+j까지의 누적합을 더한것을
				//비교해서 min값적용
				DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + sum[i + j] - sum[j - 1]);
			}
		}

	}
	
	return DP[1][K];
}

int main(void) {
	
	vector<int> ans;
	int T;

	cin >> T;
	while (T--)
		ans.push_back(Dynamic());

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}

/*
1
4
40 30 30 50
*/

/*

1
15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
*/

/*
2
4
40 30 30 50
15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
*/
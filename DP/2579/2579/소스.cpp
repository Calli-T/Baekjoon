#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	int temp;
	vector<int> stair(1, 0);
	vector<vector<int>> DP;
	vector<int> status;

	cin >> N;
	status.push_back(0); 
	status.push_back(0); 
	status.push_back(0); 
	DP.resize(N + 1, status);

	for (int i = 0; i < N; i++) {
		cin >> temp;
		stair.push_back(temp);
	}

	DP[1][1] = stair[1];
	if(N >=2){
		DP[2][1] = stair[2];
		DP[2][2] = stair[1] + stair[2];
	}
	
	
	if (N >= 3) {
		for (int i = 3; i <= N; i++) {
			/*// 1칸뛰기의 경우, 0번연속상태에서
			DP[i][1] = (DP[i - 1][0] != 0) ? (DP[i - 1][0] + stair[i]) : 0;*/
			// 1칸뛰기의 경우, 1번연속상태에서
			DP[i][2] = DP[i - 1][1] + stair[i];
			// 2칸뛰기의 경우, 제일 큰 값으로
			temp = max(max(DP[i - 2][0], DP[i - 2][1]), DP[i - 2][2]);
			//cout << "Mu" << temp << "YaHo" << endl;
			DP[i][1] = temp + stair[i];
		}
	}

	int ans = max(DP[N][1], DP[N][2]);
	cout << ans;
	//제일큰걸구한다

	return 0;
}

/*
	for (int i = 0; i <= N; i++) {
		cout << i << "번째 계단(" << stair[i];
		cout << "):	";
		cout << DP[i][0] << "	";
		cout << DP[i][1] << "	";
		cout << DP[i][2] << endl;

	}*/


/*
for (int i = 0; i <= N; i++) {
	cout << i << "번째 계단(" << stair[i];
	cout << "):	";
	cout << DP[i][0] << "	";
	cout << DP[i][1] << "	";
	cout << DP[i][2] << endl;

}*/

/*
for (int i = 0; i < stair.size(); i++)
		cout << stair[i] << endl;
*/

// 아이디어 1: 각 발판별로/연속한 횟수 별로 나눠야 하지 않을까?
// DP[N][M] N은 계단위치, M은 연속한 발판의 수 해당 값은 점수
// 2단계 점프뛰면, 연속계단이 1이든 2든 1로 리셋
// 배열의 크기를 생각할것
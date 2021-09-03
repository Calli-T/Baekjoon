#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	int temp;
	vector<int> value;
	vector<int> DP;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		value.push_back(temp);
	}

	DP.resize(M + 1);
	
	DP[0] = 1; // 0원
	for (int i = 0; i < N; i++) { //각각의 동전에 대해
		for (int j = value[i]; j <= M; j++) { //코인의 가격보다 작은값을 배제
			DP[j] += DP[j - value[i]];  //기존의 개수에 새로운 코인을 추가했을 때 가능한 방법을 부여함
			//코인값만큼 싼것에다가 해당 코인을 더하면 해당 값이 되므로 
		}
	}

	cout << DP[M] << endl;
	
	return 0;
}

//DP[i] = 
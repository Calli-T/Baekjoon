#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	else
		return a[1] < b[1];
}

bool startCompare(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

bool endCompare(vector<int>& a, vector<int>& b) {
	return a[1] < b[1];
}

int main(void) {

	int N;
	vector<vector<int>> meeting;
	vector<int> time(2, 0);
	int temp1, temp2;
	
	int ans = 0;
	int endgame = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		time[0] = temp1;
		time[1] = temp2;
		meeting.push_back(time);
	}

	sort(meeting.begin(), meeting.end(), compare);

	/*for (int i = 0; i < meeting.size(); i++) {
		cout << meeting[i][0] << " " << meeting[i][1] << " " << endl;
	}*/

	for (int i = 0; i < meeting.size(); i++) {
		if (endgame <= meeting[i][0]) {
			endgame = meeting[i][1];
			ans++;
		}
	}

	cout << ans;

	return 0;
}

/*
	cout << endl;
	for (int i = 0; i < meeting.size(); i++) {
		cout << meeting[i][0] << " " << meeting[i][1] << " " << meeting[i][2] << endl;
	}
	cout << endl;
	*/
// 아이디어 1
/*
소요시간기준으로 정렬해서 작은거부터 채워 나가며, 소요시간 안에 있는 것들은 소멸시킨다
*/

//코드
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
	return a[2] < b[2];
}

int main(void) {

	int N;
	vector<vector<int>> meeting;
	vector<int> time(3, 0);
	vector<bool> table;
	int temp1, temp2;
	int ans = 0;

	int endAt = 0;
	bool picked;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		time[0] = temp1;
		time[1] = temp2;
		time[2] = time[1] - time[0];
		meeting.push_back(time);

		endAt = max(endAt, time[1]);
	}

	sort(meeting.begin(), meeting.end(), compare);



	table.resize(endAt, false);

	//cout << endAt<<endl;

	for (int i = 0; i < meeting.size(); i++) {
		if (meeting[i][2] == 0) {
			ans++;
		}
		else {
			picked = false;
			for (int j = meeting[i][0]; j < meeting[i][1]; j++) {
				if (table[j] == true) picked = true;
			}
			if (picked == false) {
				for (int j = meeting[i][0]; j < meeting[i][1]; j++) {
					table[j] = true;
				}
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}
*/

// 아이디어 2
/*
위랑 같이 하되, 하나 채울 때마다 소멸-정렬을 다시한다
*/

// 3시에서 5시까지 2시간 회의를 하는걸 집으면
// 3~4시에 회의를 시작하는 애들을 날려야하고 (5시 시작은 ㄱㅊ)
// 4~5시에 회의를 끝마치는 애들을 날려야한다 (3시 마침은 ㄱㅊ)

/*
// 사실
빨리 끝나는 조건으로 정리하면, 가능하다고 한다
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> DDDP(101, -51);
vector<vector<int>> DDP(101, DDDP);
vector<vector<vector<int>>> DP(101, DDP);

vector<vector<int>> testCase;
vector<int> temp;

int getW(int a, int b, int c) {
	int memo;
	if (DP[a + 50][b + 50][c + 50] == -51) {
		if (a <= 0 || b <= 0 || c <= 0) {
			memo = 1;
			DP[a + 50][b + 50][c + 50] = memo;
			return memo;
		}
		if (a > 20 || b > 20 || c > 20) {
			memo = getW(20, 20, 20);
			DP[a + 50][b + 50][c + 50] = memo;
			return memo;
		}
		if (a < b && b < c) {
			memo = getW(a, b, c - 1) + getW(a, b - 1, c - 1) - getW(a, b - 1, c);
			DP[a + 50][b + 50][c + 50] = memo;
			return memo;
		}
		memo = getW(a - 1, b, c) + getW(a - 1, b - 1, c) + getW(a - 1, b, c - 1) - getW(a - 1, b - 1, c - 1);
		DP[a + 50][b + 50][c + 50] = memo;
		return memo;

	}
	return DP[a + 50][b + 50][c + 50];
}

int main() {

	int a, b, c;
	int ans;

	while (true) {
		cin >> a >> b >> c;
		temp.push_back(a);
		temp.push_back(b);
		temp.push_back(c);
		/*ans = getW(a, b, c);*/
		testCase.push_back(temp);
		temp.clear();

		if (a == -1 && b == -1 && c == -1) break;
	}

	for (int i = 0; i < testCase.size() - 1; i++){
		cout << "w(" << testCase[i][0] << ", ";
		cout << testCase[i][1] << ", ";
		cout << testCase[i][2] << ") = ";
		cout << getW(testCase[i][0], testCase[i][1], testCase[i][2]);
		cout << "\n";
	}

	return 0;
}
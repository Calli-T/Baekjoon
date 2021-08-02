#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> testCase;
	vector<int> cost(3, 0);
	vector<vector<int>> minCost;
	vector<int> RGB;
	int N;
	int color1, color2, color3;

	cin >> N;
	RGB.resize(N + 1, 0);
	minCost.resize(3, RGB);

	for (int i = 0; i < N; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		testCase.push_back(cost);
	}
	
	minCost[0][1] = testCase[0][0];
	minCost[1][1] = testCase[0][1];
	minCost[2][1] = testCase[0][2];
	
	// R = 1, G = 2, B = 3
	color1 = 0;
	color2 = 1;
	color3 = 2;
	
	/*
	cout << minCost[0][1] << " ";
	cout << minCost[1][1] << " ";
	cout << minCost[2][1] << " ";
	*/

	for (int i = 2; i <= N; i++) {
		minCost[0][i] = testCase[i - 1][0] + (minCost[1][i - 1] < minCost[2][i - 1] ? minCost[1][i - 1] : minCost[2][i - 1]);
		minCost[1][i] = testCase[i - 1][1] + (minCost[0][i - 1] < minCost[2][i - 1] ? minCost[0][i - 1] : minCost[2][i - 1]);
		minCost[2][i] = testCase[i - 1][2] + (minCost[0][i - 1] < minCost[1][i - 1] ? minCost[0][i - 1] : minCost[1][i - 1]);
	}

	//cout << minCost[0][N] << " " << minCost[1][N] << " " << minCost[2][N] << endl;
	int ans = minCost[0][N] < minCost[1][N] ? minCost[0][N] : minCost[1][N];
	ans = (ans < minCost[2][N] ? ans : minCost[2][N]);
	cout << ans;
	
	return 0;
}

// �˰��������, N��°�� �� �ּڰ��� N-1��°�� ���� �ּڰ� + �����ٰ��̴�
// �ش� ���� ������, �ش� ���� ���� �ʾҴ� �ٸ� �� ������ �������� �ش� ���� �Ÿ� ���� �����ش�
// �ٸ� �� ���� ���������� �����(�׷��� �ش� ���� �� �� �����Ƿ�)���� ����س���, ���ΰ� ���θ� ������ִ°��� �ٽ�

//�߸��� �˰���

//cout << minCost[0][i - 1] << endl;
		//cout << (color1 + 1) % 3 << " " << (color1 + 2) % 3 << " "<<endl;
/*color1 = (testCase[i - 1][(color1 + 1) % 3] < testCase[i - 1][(color1 + 2) % 3] ? (color1 + 1) % 3 : (color1 + 2) % 3);
color2 = (testCase[i - 1][(color2 + 1) % 3] < testCase[i - 1][(color2 + 2) % 3] ? (color2 + 1) % 3 : (color2 + 2) % 3);
color3 = (testCase[i - 1][(color3 + 1) % 3] < testCase[i - 1][(color3 + 2) % 3] ? (color3 + 1) % 3 : (color3 + 2) % 3);
minCost[0][i] = minCost[0][i - 1] + testCase[i - 1][color1];
minCost[1][i] = minCost[1][i - 1] + testCase[i - 1][color2];
minCost[2][i] = minCost[2][i - 1] + testCase[i - 1][color3];*/

/*if (color1 == 1) {
	minCost[0][i] = minCost[0][i - 1] + (testCase[i - 1][1] < testCase[i - 1][2] ? testCase[i - 1][1] : testCase[i - 1][2]);
	color1 = (testCase[i - 1][1] < testCase[i - 1][2] ? 2 : 3);
}
else if (color2 == 2) {
	minCost[0][i] = minCost[0][i - 1] + (testCase[i - 1][0] < testCase[i - 1][2] ? testCase[i - 1][0] : testCase[i - 1][2]);
	color1 = (testCase[i - 1][0] < testCase[i - 1][2] ? 1 : 3);
}
else {
	minCost[0][i] = minCost[0][i - 1] + (testCase[i - 1][0] < testCase[i - 1][1] ? testCase[i - 1][0] : testCase[i - 1][1]);
	color1 = (testCase[i - 1][0] < testCase[i - 1][1] ? 1 : 2);
}*/
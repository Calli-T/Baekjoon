#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> scene;
int N;
string temp;
string ans = "";
int pixel;

void compress(int len, int r, int c) {
	if (len == 1) {
		ans += scene[r][c] == true ? '1' : '0';
		return;
	}

	pixel = 0;
	for (int i = r; i < r + len; i++)
		for (int j = c; j < c + len; j++)
			if (scene[i][j])
				pixel++;

	if (pixel == 0) {
		ans += '0';
	}
	else if (pixel == len * len) {
		ans += '1';
	}
	else {
		ans = ans + '(';
		compress(len / 2, r, c);
		compress(len / 2, r, c + len / 2);
		compress(len / 2, r + len / 2, c);
		compress(len / 2, r + len / 2, c + len / 2);
		ans = ans + ')';
	}
}

int main(void) {
	cin >> N;
	scene.resize(N);
	for (int i = 0; i < N; i++)
		scene[i].resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < N; j++)
			scene[i][j] = temp[j] == '1' ? true : false;
	}

	compress(N, 0, 0);
	cout << ans;

	return 0;
}

/*
for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++)
		cout << scene[i][j] << " ";
	cout << endl;
}
*/

//ans = '(' + ans;
//ans = ans + ')';
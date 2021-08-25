#include <iostream>

using namespace std;

int loc[16] = { 0, };
int N;
int ans = 0;

void nQueen(int col) {
	if (col == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		int check = true;
		//넣은 값들에 대하여
		for (int j = 0; j < col; j++) {
			loc[col] = i;
			//같은 행이거나, 대각선상에 있거나(같은 열일수는없음)
			if (loc[j] == loc[col] 
				||
				(j - col) == (loc[j] - loc[col])
				|| 
				(j - col) == -(loc[j] - loc[col])
				) {
				check = false;
				break;
			}

		}
		
		if (check) {
			nQueen(col + 1);
		}
	}
}

int main(void) {
	
	cin >> N;

	// 점점 늘어가면서 판단
	for (int i = 0; i < N; i++) {
		loc[0] = i;
		nQueen(1);
	}

	cout << ans;

	return 0;
}

/*
#include <cstdio>

int n, cnt=0;
int temp[16]={0, };

void nqueen(int col);

int main(void){
	scanf("%d", &n);

	for(int i=0;i<n;i++){
		temp[0]=i;
		nqueen(1);
	}

	printf("%d\n", cnt);

	return 0;
}

void nqueen(int col){
	if(col==n){
		cnt+=1;
		return;
	}

	for(int i=0;i<n;i++){
		int check = true;
		for(int j=0;j<col;j++){
			temp[col]=i;
			if(temp[j]==temp[col]||((j-col)==(temp[j]-temp[col]))||((j-col)==(temp[col]-temp[j]))){
				check = false;
				break;
			}
		}

		if(check){
			nqueen(col+1);
		}
	}
}
*/

//기존 dfs 방식을 사용하는것은 좋으나, visit을 2차원으로 만들어야 하나?
//visited의 존재로 인해 구현이 어렵다. visited가 필요없어야한다
//백트레킹은 방문기록을 없애야한다?
/*
for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < N + 2; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
*/

/*
int N;
	vector<vector<int>> board;

	cin >> N;
	board.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		board[i].resize(N + 2, 2);
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			board[i][j] = 0;
		}
	}

	return 0;
*/
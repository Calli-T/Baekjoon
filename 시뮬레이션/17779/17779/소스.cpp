#include <iostream>
#include <vector>

using namespace std;

int N;
int d1;
int d2;
vector<vector<int>> population;

int districtChecker(int x, int y) {
	int difR;
	int difC;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			
		}
		cout << endl;
	}

	return 0;
}

int main(void) {
	cin >> N;
	population.resize(N);
	for (int i = 0; i < N; i++)
		population[i].resize(N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> population[i][j];
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout <<  population[i][j];
		cout << endl;
	}
		
	d1 = 2;
	d2 = 2;
	cout << districtChecker(2, 2);
	


	return 0;
}
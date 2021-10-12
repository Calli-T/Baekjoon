#include <vector>
#include <iostream>

using namespace std;

int main() {
	int N, L;
	vector<vector<int>> ramp;
	vector<vector<bool>> stair;

	bool isPassable;
	bool isPlaceable;
	int destination;
	int origin;
	int ans = 0;

	cin >> N >> L;
	ramp.resize(N);
	for (int i = 0; i < N; i++)
		ramp[i].resize(N);
	stair.resize(N);
	for (int i = 0; i < N; i++)
		stair[i].resize(N, false);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ramp[i][j];

	// ��˻�
	for (int r = 0; r < N; r++) {
		isPassable = true;

		// �� �࿡ ����
		for (int c = 0; c < N - 1; c++) {

			//���̰� ���ٸ�
			if (ramp[r][c] == ramp[r][c + 1]) {
				continue;
			}
			// �������� 1���϶��
			else if (ramp[r][c] + 1 == ramp[r][c + 1] || ramp[r][c] - 1 == ramp[r][c + 1]) {\

				//Ƣ�� ������ �ƿ�
				if (c + L >= N || c - L + 1 < 0) {
					isPassable = false;
					break;
				}
				else {
					//���������� ����������
					if (ramp[r][c] < ramp[r][c + 1]) {
						destination = c - L + 1;
						origin = ramp[r][c];
						
						for (int j = c; j >= destination; j--) {
							if (ramp[r][c] != origin || !stair[r][j]) {
								isPassable = false;
								break;
							}
							else {
								stair[r][j] = true;
							}
						}
					}
					//���������� ����������
					else {
						destination = c + L;
						origin = ramp[r][c + 1];
						c++;
						for (; c <= destination; c++) {
							if (ramp[r][c] != origin) {
								isPassable = false;
								break;
							}
							else {
								stair[r][c] = true;
							}
						}
					}
				}


			}
			//�������� 2�̻��̸�
			else { 
				isPassable = false;
				break;
			}

			if (!isPassable) break;

		}

		if (isPassable) {
			ans++;
			cout << r << "���� ������, ����ȣ!" << endl;
		}
			
	}

	cout << ans << endl;

	// ��˻�
	for (int c = 0; c < N; c++) {
		isPassable = true;

		// �� �࿡ ����
		for (int r = 0; r < N - 1; r++) {

			//���̰� ���ٸ�
			if (ramp[r][c] == ramp[r][c + 1]) {
				continue;
			}
			// �������� 1���϶��
			else if (ramp[r][c] + 1 == ramp[r][c + 1] || ramp[r][c] - 1 == ramp[r][c + 1]) {
				\

					//Ƣ�� ������ �ƿ�
					if (c + L >= N || c - L + 1 < 0) {
						isPassable = false;
						break;
					}
					else {
						//���������� ����������
						if (ramp[r][c] < ramp[r][c + 1]) {
							destination = c - L + 1;
							origin = ramp[r][c];

							for (int j = c; j >= destination; j--) {
								if (ramp[r][c] != origin || stair[r][j]) {
									isPassable = false;
									break;
								}
								else {
									stair[r][j] = true;
								}
							}
						}
						//���������� ����������
						else {
							destination = c + L;
							origin = ramp[r][c + 1];
							c++;
							for (; c <= destination; c++) {
								if (ramp[r][c] != origin) {
									isPassable = false;
									break;
								}
								else {
									stair[r][c] = true;
								}
							}
						}
					}


			}
			//�������� 2�̻��̸�
			else {
				isPassable = false;
				break;
			}

			if (!isPassable) break;

		}

		if (isPassable) {
			ans++;
			cout << c << "���� ������, ����ȣ!" << endl;
		}

	}

	return 0;

}


/*
for (int i = 1; i < L; i++) {

					if (ramp[r][c + i] != ramp[r][c + i])
						isPassable = false;
					else {
						stair[r][c + i] = true;
						stair[r][c + i + 1] = true;
					}

				}
*/


//�ุ ó����
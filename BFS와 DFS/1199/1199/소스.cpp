#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000
using namespace std;

// ������ ��
int n;

//
vector<vector<int>> graph;

// �������
int adj_matrix[MAX][MAX];

// ���� ����
int degree[MAX];

// ���Ϸ� ȸ�� Ž�� �Լ�
void eulerain_circuit(int current_node) {

    // ���� ������ ���� ���
    for (int i = 0; i < n; ++i) {

        // ������ �����Ѵٸ�
        if (adj_matrix[current_node][i] != 0) {

            // ������ ������ ������ ������ -1 �� ������ ��, ����� ������ Ž��
            adj_matrix[current_node][i] -= 1;
            adj_matrix[i][current_node] -= 1;
            eulerain_circuit(i);
        }
    }
    // ���� ���� ���
    cout << to_string(current_node + 1) << " ";
}

int main(void) {

    // ���� ���� �Է�
    cin >> n;

    graph.resize(n);

    // �Է¿� ����, ������� �ʱ�ȭ
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            // ������� ��� �Է�
            cin >> adj_matrix[i][j];
            if (adj_matrix[i][j])
                graph[i].push_back(j);

            // ��������� �� ���� ��� Ž���ϸ�, �� ������ ��� ���� ���� ����
            degree[i] += adj_matrix[i][j];
        }
    }

    // ������� �� ������ ������ Ȧ����� ���Ϸ� ȸ�� �Ұ���
    for (int i = 0; i < n; ++i) {
        if (degree[i] % 2 == 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << endl;
    for (int i = 0; i < n; i++) {
        //???
        for (int j = 0; j <n; j++) {
            cout << graph[i][j] + 1 << " ";
        }
        cout << endl;
    }

    // ��� �Լ� ȣ��
    eulerain_circuit(0);

    return 0;

}
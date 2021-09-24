#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000
using namespace std;

// 정점의 수
int n;

//
vector<vector<int>> graph;

// 인접행렬
int adj_matrix[MAX][MAX];

// 정점 차수
int degree[MAX];

// 오일러 회로 탐색 함수
void eulerain_circuit(int current_node) {

    // 현재 정점의 차수 계산
    for (int i = 0; i < n; ++i) {

        // 간선이 존재한다면
        if (adj_matrix[current_node][i] != 0) {

            // 간선을 가지는 정점의 차수를 -1 씩 감소한 뒤, 연결된 정점을 탐색
            adj_matrix[current_node][i] -= 1;
            adj_matrix[i][current_node] -= 1;
            eulerain_circuit(i);
        }
    }
    // 현재 정점 출력
    cout << to_string(current_node + 1) << " ";
}

int main(void) {

    // 정점 개수 입력
    cin >> n;

    graph.resize(n);

    // 입력에 따른, 인접행렬 초기화
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            // 인접행렬 요소 입력
            cin >> adj_matrix[i][j];
            if (adj_matrix[i][j])
                graph[i].push_back(j);

            // 인접행렬의 한 행을 모두 탐색하며, 한 정점의 모든 간선 개수 덧셈
            degree[i] += adj_matrix[i][j];
        }
    }

    // 인접행렬 한 정점의 차수가 홀수라면 오일러 회로 불가능
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

    // 재귀 함수 호출
    eulerain_circuit(0);

    return 0;

}
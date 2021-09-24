#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int n;
int nxt[1010];
int adj[1010][1010];
vector<int> route;

void getEuler(int here) {
    //변수  앞에 &가 붙으면 해당변수의 별명을 선언하겠다는 뜻
    for (int& there = nxt[here]; there <= n; there++) {
        while (adj[here][there]) {
            adj[here][there]--;
            adj[there][here]--;
            getEuler(there);
        }
        cout << "here: " << here << " " << "nxt[here]: " << nxt[here] << endl;
    }
    if (nxt[here] == 7) cout << "무야호" << endl;
    route.push_back(here);
}

int main() {
    int startPoint = 0;
    int edgeNum[1010] = { 0, };

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            edgeNum[i] += adj[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        // 하나의 엣지라도 붙어있어야 시작점이 될 수 있다.
        if (edgeNum[i] != 0) startPoint = i;
        // 한 노드에 엣지가 홀수개라면 끝
        if (edgeNum[i] % 2 == 1) {
            cout << -1;
            return 0;
        }
    }
    cout << "Start Point: " << startPoint << endl;
    for (int i = 1; i <= n; i++) nxt[i] = 1;
    getEuler(startPoint);

    for (int i = 0; i < route.size(); i++) {
        cout << route[i] << ' ';
    }
}
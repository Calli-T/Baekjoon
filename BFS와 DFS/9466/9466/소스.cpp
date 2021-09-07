#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int termProject(void) {
	int n;
	vector<int> hope;
	vector<bool> isFinished;
	int now, next;
	int ans = 0;
	int chain = 0;

	cin >> n;
	ans = n;
	hope.resize(n + 1);
	isFinished.resize(n + 1, false);

	for (int i = 1; i <= n; i++)
		cin >> hope[i];

	for (int i = 1; i <= n; i++) {


		if (!isFinished[i]) {

			stack<int> ST;
			vector<bool> visited(n + 1, false);

			now = i;
			ST.push(now);
			visited[now] = true;

			while (!ST.empty()) {
				now = ST.top();

				if (isFinished[hope[now]]) {
					isFinished[now] = true;
					break;
				}

				if (!visited[hope[now]]) {
					visited[hope[now]] = true;
					ST.push(hope[now]);
				}
				else {
					chain = 0;
					next = hope[now];
					chain++;
					isFinished[next] = true;
					for (int k = hope[next]; k != next; k = hope[k]) {
						isFinished[k] = true;
						chain++;
					}
					ans -= chain;

					while (!ST.empty()) {
						isFinished[ST.top()] = true;
						ST.pop();
					}
				}
			}

		}
	}
	return ans;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	vector<int> ans;

	cin >> T;
	while (T--) {
		ans.push_back(termProject());
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';

	return 0;
}
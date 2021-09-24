#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, x;
vector<int> sub;
vector<int> input;
int low, high, mid;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		input.push_back(x);
	}
	for (int i = 0; i < N; i++)
	{

		if (sub.empty() || sub.back() < input[i])
		{
			sub.push_back(input[i]);
		}
		else
		{
			auto iterator = lower_bound(sub.begin(), sub.end(), input[i]);
			*iterator = input[i];
		}
	}
	cout << sub.size();
}

/*
8
3 5 7 9 2 1 4 8
*/

//https://cocoon1787.tistory.com/306
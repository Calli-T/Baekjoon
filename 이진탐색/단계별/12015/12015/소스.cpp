#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, x;
vector<int> v;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (v.empty() || v.back() < x)
		{
			v.push_back(x);
		}
		else
		{
			auto iterator = lower_bound(v.begin(), v.end(), x);
			*iterator = x;
		}
	}
	cout << v.size();
}
/*
8
3 5 7 9 2 1 4 8
*/

//https://cocoon1787.tistory.com/306
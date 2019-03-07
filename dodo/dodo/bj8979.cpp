#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX_C 1000
pair<pair<int, int>, pair<int, int>> country[MAX_C];


int N, K;
int cnt = 1;
int samecnt = 0;
int cScore;
bool sortbysec(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
	if (a.first.second > b.first.second)
		return true;
	else if (a.first.second == b.first.second)
	{
		if (a.second.first > b.second.first)
			return true;
		else if (a.second.first == b.second.first)
			if (a.second.second > b.second.second)
				return true;
			else if (a.second.second == b.second.second)

				return a.first.first == K;
	}
	return false;
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> country[i].first.first >> country[i].first.second >> country[i].second.first >> country[i].second.second;
	}

	sort(country,country+N,sortbysec);
	for (int i = 0; i < N; i++) {
		if (country[i].first.first == K)
		{
			cout << i + 1 << endl;
			break;
		}
	}
	
}

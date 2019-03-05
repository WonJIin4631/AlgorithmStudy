#include<iostream>
#include<stack>
#include<utility>
using namespace std;



int main() {

	std::ios::sync_with_stdio(false);	
	int N;
	stack<pair<int,int>> s;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		while (!s.empty()) {
			if (s.top().second >= num) {
				cout << s.top().first << ' ';
				break;
			}
			s.pop();
		}

		if (s.empty())
			cout << '0' << ' ';

		s.push(make_pair(i, num));
	}
}
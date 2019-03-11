#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;
vector<int> s;
int visited[8 + 1] = { 0 };
int N;
int ans;

void DFS() {
	if (s.size() == N) {
		int sum = 0;
		for (int i = 0; i < N - 1; ++i)
			sum += abs(s[i] - s[i + 1]);
		ans = max(ans, sum);
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			s.push_back(v.at(i));
			DFS();
			visited[i] = 0;
			s.pop_back();
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	DFS();
	cout << ans << endl;
}

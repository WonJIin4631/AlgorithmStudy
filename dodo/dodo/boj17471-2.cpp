#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
int citys[11];
bool visit[11];
vector<int> citysConnection[11];
int ans = 987654321;
void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> citys[i];
	}
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int to;
			cin >> to;
			citysConnection[i].push_back(to);
			citysConnection[to].push_back(i);
		}
	}
}
bool checkCity() {
	bool check[11] = { 0 };
	queue<int> q;
	int cityOne;
	int cityTwo;
	int cityOneCnt = 0;
	int cityTwoCnt = 0;;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == true) {
			cityOne = i;
			cityOneCnt++;
		}
		else {
			cityTwo = i;
			cityTwoCnt++;
		}
	}
	int tempCnt = 0;
	q.push(cityOne);
	check[cityOne] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		tempCnt++;
		for (int i = 0; i < citysConnection[cur].size(); i++) {
			int nextCity = citysConnection[cur][i];
			if (visit[nextCity] && check[nextCity] == false) {
				check[nextCity] = true;
				q.push(nextCity);
			}
		}
	}
	if (tempCnt != cityOneCnt)
		return false;
	tempCnt = 0;
	q.push(cityTwo);
	check[cityTwo] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		tempCnt++;
		for (int i = 0; i < citysConnection[cur].size(); i++) {
			int nextCity = citysConnection[cur][i];
			if (visit[nextCity] == false && check[nextCity] == false) {
				check[nextCity] = true;
				q.push(nextCity);
			}
		}
	}
	if (tempCnt != cityTwoCnt)
		return false;
	return true;
}
void chooseCity(int idx, int cnt) {
	if (cnt == N)
		return;
	if (cnt >=1) {

		if (checkCity()) {
			int cityOneSum = 0;
			int cityTwoSum = 0;
			for (int i = 1; i <= N; i++) {
				if (visit[i])
					cityOneSum += citys[i];
				else
					cityTwoSum += citys[i];
			}
			ans = min(ans, abs(cityOneSum - cityTwoSum));
		}
	}
	for (int i = idx; i <=N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			chooseCity(i, cnt + 1);
			visit[i] = false;
		}
	}
}
void solve() {
	init();
	chooseCity(1, 0);
	if (ans == 987654321)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}
int main() {
	solve();
	return 0;
}
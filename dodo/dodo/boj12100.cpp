#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

int N;
int ans = 0;
deque<int> dq;
vector<vector<int>> move_left(vector<vector<int>> m) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (m[i][j] != 0) {
				dq.push_back(m[i][j]);
				m[i][j] = 0;
			}
		int idx = 0;
		while (!dq.empty()) {
			int cur = dq.front();
			dq.pop_front();
			if (dq.size() >= 1) {
				if (dq.front() == cur) {
					m[i][idx++] = cur * 2;
					dq.pop_front();
				}
				else
					m[i][idx++] = cur;
			}
			else
				m[i][idx++] = cur;
		}
	}
	return m;
}
vector<vector<int>> move_right(vector<vector<int>> m) {

	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j >= 0; j--)
			if (m[i][j] != 0) {
				dq.push_back(m[i][j]);
				m[i][j] = 0;
			}
		int idx = N - 1;
		while (!dq.empty()) {
			int cur = dq.front();
			dq.pop_front();
			if (dq.size() >= 1) {
				if (dq.front() == cur) {
					m[i][idx--] = cur * 2;
					dq.pop_front();
				}
				else
					m[i][idx--] = cur;
			}
			else
				m[i][idx--] = cur;
		}
	}
	return m;
}
vector<vector<int>> move_up(vector<vector<int>> m) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (m[j][i] != 0) {
				dq.push_back(m[j][i]);
				m[j][i] = 0;
			}
		int idx = 0;
		while (!dq.empty()) {
			int cur = dq.front();
			dq.pop_front();
			if (dq.size() >= 1) {
				if (dq.front() == cur) {
					m[idx++][i] = cur * 2;
					dq.pop_front();
				}
				else
					m[idx++][i] = cur;
			}
			else
				m[idx++][i] = cur;
		}
	}
	return m;
}
vector<vector<int>> move_down(vector<vector<int>> m) {
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j >= 0; j--)
			if (m[j][i] != 0) {
				dq.push_back(m[j][i]);
				m[j][i] = 0;
			}
		int idx = N - 1;
		while (!dq.empty()) {
			int cur = dq.front();
			dq.pop_front();
			if (dq.size() >= 1) {
				if (dq.front() == cur) {
					m[idx--][i] = cur * 2;
					dq.pop_front();
				}
				else
					m[idx--][i] = cur;
			}
			else
				m[idx--][i] = cur;
		}
	}
	return m;
}

void solve(int cnt, vector<vector<int>> m) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				ans = max(ans, m[i][j]);

		return;
	}
	vector<vector<int>> temp;
	temp = move_left(m);
	solve(cnt + 1, temp);
	temp = move_right(m);
	solve(cnt + 1, temp);
	temp = move_up(m);
	solve(cnt + 1, temp);
	temp = move_down(m);
	solve(cnt + 1, temp);
}
int main() {
	cin >> N;
	vector<vector<int>> map(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve(0, map);
	cout << ans << '\n';
	return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

typedef char basenum[3];
int N;
// 서로다른 숫자 3개
int visit[10];
vector < pair<int, pair<int, int>>> anslist;
vector<int> v;
int ans = 0;
void getcmp(vector<int> vec) {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		int ck[10];
		int st=0, ball=0;
		int num = anslist[i].first;
		ck[num / 100] = 1;
		ck[(num %100)/10] = 1;
		ck[num % 10] = 1;
		if (vec[0] == num / 100) {
			st++;
		}
		else {
			if (ck[vec[0]] == 1) {
				ball++;
				//cout << '1';
			}
		}
		if (vec[1] == (num % 100) / 10) {
			st++;
		}
		else{
			if (ck[vec[1]] == 1) {
				ball++;
				//cout << '2';
			}
		}
		if (vec[2] == num%10) {
			st++;
		}
		else {
			if (ck[vec[2]] == 1) {
				ball++;
				//cout << '3';
			}
		}
		cout << num << '\n';
		cout << st << ' ' << ball << '\n';
		cout << anslist[i].second.first << ' ' << anslist[i].second.second << '\n';
		if (st != anslist[i].second.first || ball != anslist[i].second.second) {
			flag= true;
			return;
		}
	}
	ans++;
}
void solve(int cnt) {
	if (cnt == 3) {
		int ck[10];
		for (int i = 0; i < N; i++) {
			memset(ck, 0, sizeof(ck));
			int st = 0, ball = 0;
			int num = anslist[i].first;
			ck[num / 100] = 1;
			ck[(num % 100) / 10] = 1;
			ck[num % 10] = 1;
			if (v[0] == num / 100) {
				st++;
			}
			else {
				if (ck[v[0]] == 1) {
					ball++;
				}
			}
			if (v[1] == (num % 100) / 10) {
				st++;
			}
			else {
				if (ck[v[1]] == 1) {
					ball++;
				}
			}
			if (v[2] == num % 10) {
				st++;
			}
			else {
				if (ck[v[2]] == 1) {
					ball++;
				}
			}
			if (st != anslist[i].second.first || ball != anslist[i].second.second) {
				return;
			}
		}
		ans++;
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			v.push_back(i);
			solve(cnt + 1);
			visit[i] = 0;
			v.pop_back();
		}
	}

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num,st, ball;
		cin >> num >> st >> ball;
		anslist.push_back(make_pair(num, make_pair(st, ball)));
	}
	solve(0);
	cout << ans << '\n';
}
#include<iostream>
#include<cmath>
#include<set>
using namespace std;

int N, M;
int numList[10] = { 0 };
int primeNum[9002] = { 0 };
bool visit[10] = { 0 };
set<int> Set;
void solve(int cnt,int idx,int sum) {
	if (cnt == M) {
		if (primeNum[sum] != 0) {
			if (Set.find(sum) == Set.end()) {
				Set.insert(sum);
			}
		}
		return;
	}
	for (int i = idx; i < N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			solve(cnt + 1, i, sum + numList[i]);
			visit[i] = false;
		}
	}
}
int main() {
	for (int i = 2; i <= 9000; i++)
		primeNum[i] = i;
	for (int i = 2; i <= sqrt(9000); i++) {
		if (primeNum[i] == 0)
			continue;
		for (int j = i + i; j <= 9000; j += i) {
			primeNum[j] = 0;
		}
	}
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> numList[i];
	}
	solve(0, 0, 0);
	if (Set.size() == 0)
		cout << -1 << '\n';
	else {
		for (auto idx : Set) {
			cout << idx << ' ';
		}
	}
	return 0;
}
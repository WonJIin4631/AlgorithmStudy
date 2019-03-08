#include<iostream>
#include<algorithm>
using namespace std;
int eggS[8 + 1];
int eggW[8 + 1];
int N, ans;

bool isBroken(int idx) {
	if (eggS[idx] <= 0)
		return true;
	else
		return false;
}
void re(int idx1, int idx2) {
	eggS[idx1] += eggW[idx2];
	eggS[idx2] += eggW[idx1];
}
void hit(int idx1, int idx2) {
	eggS[idx1] -= eggW[idx2];
	eggS[idx2] -= eggW[idx1];
}


void DFS(int a) {
	if (a == N) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (isBroken(i))
				count++;
		}
		ans = max(ans, count);
		return;
	}
	if (isBroken(a)) {
		DFS(a + 1);
		return;
	}
	bool check=true;
	
	for (int i = 0; i < N; i++) {
		if (i == a || isBroken(i))
			continue;
		hit(a, i);
		DFS(a + 1);
		check = false;
		re(a, i);
	}
	if (check)
		DFS(a + 1);
	
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> eggS[i] >> eggW[i];
	}
	ans = 0;
	DFS(0);
	cout << ans << endl;

}


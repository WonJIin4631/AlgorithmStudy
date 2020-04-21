#include<iostream>
#include<algorithm>
using namespace std;

char op[20];
int num[20];
int N;
int ans = -987654321;
int cal(int idx) {
	if (op[idx] == '+') 
		return (num[idx] + num[idx + 1]);
	else if(op[idx]=='-')
		return (num[idx] - num[idx + 1]);
	else 
		return (num[idx] * num[idx + 1]);
}
int cal2(int cur, int next, int idx) {
	if (op[idx] == '+')
		return (cur + next);
	else if (op[idx] == '-')
		return (cur - next);
	else
		return (cur * next);
}
void solve(int sum,int idx) {
	if (idx == N / 2) {
		ans = max(sum, ans);
		return;
	}
	solve(cal2(sum,num[idx+1], idx), idx + 1);
	if (idx + 1 < N / 2) {
		solve(cal2(sum, cal(idx + 1),idx), idx + 2);
	}
}
int main() {
	cin >> N;
	int numIdx = 0;
	int opIdx = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 0) {
			cin >> op[opIdx];
			opIdx++;
		}
		else {
			cin >> num[numIdx];
			numIdx++;
		}
	}
	solve(num[0], 0);
	cout << ans << '\n';
	return 0;
}
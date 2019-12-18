#include<iostream>
#include<deque>
using namespace std;
deque<int> dq[4];


int ans = 0;
void move(int idx, int dir) {
	if (dir == 1) {
		int temp = dq[idx].back();
		dq[idx].pop_back();
		dq[idx].push_front(temp);
	}
	else {
		int temp = dq[idx].front();
		dq[idx].pop_front();
		dq[idx].push_back(temp);
	}
}

void side_move(int idx,int dir) {
	
	bool check[4] = { 0 };
	for (int i = 0; i < 3; i++) {
		if (dq[i][2] == dq[i + 1][6])
			check[i] = 0;
		else
			check[i] = 1;
	}
	move(idx, dir);
	int temp = dir;
	//left
	if (idx > 0) {
		for (int i = idx - 1; i >= 0; i--) {
			if (check[i] == 1) {
				temp *= -1;
				move(i, temp);
			}
			else
				break;
		}
	}
	temp = dir;
	//right
	if (idx < 3) {
		for (int i = idx; i <= 2; i++) {
			if (check[i] == 1) {
				temp *= -1;
				move(i + 1, temp);
			}
			else
				break;
		}
	}
}
void get_val() {
	if (dq[0][0] == 1)
		ans += 1;
	if (dq[1][0] == 1)
		ans += 2;
	if (dq[2][0] == 1)
		ans += 4;
	if (dq[3][0] == 1)
		ans += 8;
	cout << ans << '\n';
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int n;
			scanf("%1d", &n);
			dq[i].push_back(n);
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		side_move(a-1, b);
	}
	get_val();
	
}
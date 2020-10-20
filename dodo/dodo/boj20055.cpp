#include<iostream>
#include<queue>
#include<deque>
using namespace std;


deque<int> belt;
queue<int> robot;
int negudo[202];
int N,K;

void init() {
	cin >> N >> K;
	for (int i = 1; i <= 2*N; i++) {
		cin >> negudo[i];
	}
	for (int i = 1; i <= 2 * N; i++)
		belt.push_back(i);
}
void stepOne() {
	int temp = belt.back();
	belt.pop_back();
	belt.push_front(temp);
	int downPos = (belt.front() + (N - 1)) % (2 * N);
	if (downPos == 0)
		downPos = 2 * N;
	int qsz = robot.size();
	for (int i = 0; i < qsz; i++) {
		int cur = robot.front();
		robot.pop();
		if (cur == downPos)
			continue;
		robot.push(cur);
	}
}
void stepTwo() {
	int qsz = robot.size();
	int downPos = (belt.front() + (N - 1)) % (2 * N) ;
	if (downPos == 0)
		downPos = 2 * N;
	int prev = 0;
	for (int i = 0; i < qsz; i++) {
		int cur = robot.front();
		robot.pop();
		int nextPos = (cur + 1) % (2 * N) ;
		if (nextPos == 0)
			nextPos = 2*N;

		if (negudo[nextPos] > 0&&nextPos!=prev) {
			negudo[nextPos]--;
			if (nextPos == downPos)
				continue;
			robot.push(nextPos);
			prev = nextPos;
		}
		else {
			robot.push(cur);
			prev = cur;
		}
	}

}
void stepThree() {
	int cur = belt.front();
	if (negudo[cur] > 0) {
		negudo[cur]--;
		robot.push(cur);
	}
}
bool stepFour() {
	int cnt = 0;
	for(int i = 1; i <= 2 * N; i++) {
		if (negudo[i] == 0)
			cnt++;
	}
	if (cnt >= K)
		return true;
	return false;
}
void solve() {
	init();
	int time = 0;
	while (true){
		time++;
		stepOne();
		stepTwo();
		stepThree();
		if (stepFour())
			break;
	}
	cout << time << '\n';
}
int main() {
	solve();
	return 0;
}
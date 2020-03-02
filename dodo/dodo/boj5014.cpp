#include<iostream>
#include<queue>
using namespace std;
/*
F층으로 이루어진 건물, 가야되는 층수는 G, 현재 층수 S
버튼은 2개 위로 U만큼 가는 버튼, D만큼 내려가는 버튼
버튼 누르고 해당하는 층이 없으면 움직이지 않음
BFS로 모든경우를 탐색
1~최고층까지 INF값을 가진 배열을 만들고
해당 층수로 이동할때 버튼 눌린횟수가 적으면 이동
*/
int F, S, G, U, D;
int stair[1000002];
typedef pair<int, int> pii;
void BFS(int S, int G) {
	queue<pii> q;
	q.push(pii(S, 0));
	stair[S] = 0;
	while (!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur + U<= F) {
			if (stair[cur + U] >= cnt+1) {
				stair[cur + U] = cnt + 1;
				q.push(pii(cur + U, cnt + 1));
			}
		}
		if (cur - D >= 1) {
			if (stair[cur - D] >= cnt + 1) {
				stair[cur - D] = cnt + 1;
				q.push(pii(cur - D, cnt + 1));
			}
		}
	}
}
int main() {
	cin >> F >> S >> G >> U >> D;
	for (int i = 1; i <= F; i++) {
		stair[i] = 987654321;
	}
	BFS(S, G);
	if (stair[G] == 987654321)
		cout << "use the stairs" << '\n';
	else
		cout << stair[G] << '\n';

	return 0;
}
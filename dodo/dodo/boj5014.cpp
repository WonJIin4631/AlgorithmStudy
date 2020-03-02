#include<iostream>
#include<queue>
using namespace std;
/*
F������ �̷���� �ǹ�, ���ߵǴ� ������ G, ���� ���� S
��ư�� 2�� ���� U��ŭ ���� ��ư, D��ŭ �������� ��ư
��ư ������ �ش��ϴ� ���� ������ �������� ����
BFS�� ����츦 Ž��
1~�ְ������� INF���� ���� �迭�� �����
�ش� ������ �̵��Ҷ� ��ư ����Ƚ���� ������ �̵�
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
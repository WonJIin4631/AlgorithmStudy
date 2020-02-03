#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

/*
������ ���佺Ƽ���� �̵��Ѵ�
���� �� �ڽ��� ��� ��� ,�� �ڽ����� ���ְ� 20��, 50���Ϳ� �Ѻ��� ����

�������� ����� ���ָ� �ִ� 20������ �ٽ� ����

������ �佺Ƽ������ ���ְ� �������� �ʰ� ���� happy ���
�����ϸ� sad���

�������� �� �ִ� 100��
queue ������ġ���� ������ ��ü�� Ȯ��, ���� ���� ���� �湮 ���� , visit �迭�� ���� ���ݱ��� �Ӵ� �湮 ������ ���� �������� �湮
��ǥ�� ������ ���ԵǾ� ������ �Ÿ� ���ݿ� ����!

*/
typedef pair<int, int> pii;
int visit[101] = { 0 };
int N;
vector<pii> v;
pii st_pos;
pii end_pos;

bool getDIst(pii a, pii b) {
	int dist_x;
	int dist_y;
	if (a.first > 0 && b.first < 0) {
		dist_x = a.first + abs(b.first);
	}
	else if (a.first < 0 && b.first>0) {

		dist_x = b.first + abs(a.first);
	}
	else {
		if (a.first <= b.first)
			dist_x = b.first - a.first;
		else
			dist_x = a.first - b.first;
	}
	if (a.second > 0 && b.second < 0) {
		dist_y = a.second + abs(b.second);
	}
	else if (a.second < 0 && b.second>0) {

		dist_y = b.second + abs(a.second);
	}
	else {
		if (a.second <= b.second)
			dist_y = b.second - a.second;
		else
			dist_y = a.second - b.second;
	}
	if (dist_x + dist_y <= 1000)
		return true;
	return false;
}
void move() {
	memset(visit, 987654321, sizeof(visit));
	for (int i = 0; i < N+1; i++) {
		visit[i] = 987654321;
	}
	queue < pair<int, pii>> q;
	q.push(make_pair(0, st_pos));
	while (!q.empty()) {
		pii cur = q.front().second;
		int cnt = q.front().first;
		q.pop();
		if (cur == end_pos) {
			cout << "happy" << '\n';
			return;
		}
		for (int i = 0; i <N+1; i++) {
			if(cur!=v[i]){
				if (getDIst(cur, v[i])) {
					if (visit[i] >= cnt) {
						visit[i] = cnt;
						q.push(make_pair(cnt + 1, v[i]));
					}
				}
			}
		}
	}
	cout << "sad" << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		cin >> st_pos.first >> st_pos.second;
		for (int i = 0; i < N; i++) {
			pii info;
			cin >> info.first >> info.second;
			v.push_back(info);
		}
		cin >> end_pos.first >> end_pos.second;
		v.push_back(end_pos);
		move();
		v.clear();
	}
	return 0;
}
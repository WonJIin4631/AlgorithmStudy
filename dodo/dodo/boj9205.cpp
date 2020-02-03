#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

/*
집에서 락페스티벌로 이동한다
맥주 한 박스를 들고 출발 ,한 박스에는 맥주가 20개, 50미터에 한병씩 마심

편의점에 들려서 맥주를 최대 20병으로 다시 구매

집에서 페스티벌까지 맥주가 부족하지 않게 가면 happy 출력
부족하면 sad출력

편의점수 가 최대 100개
queue 현재위치에서 편의점 전체를 확인, 남은 맥주 수로 방문 가능 , visit 배열을 통해 지금까지 왓던 방문 수보다 작은 편의점에 방문
좌표가 음수도 포함되어 있으니 거리 간격에 유의!

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
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
1~N 구역이 존재 선거구는 2개로 나누어짐
조건
선거구는 적어도 한개 이상의 구역이 있어야함
같은 선거구는 모두 연결되어 있다

두개 선거구 차이 최소값 출력
조합으로 분배 구역을 2개의 선거구로 분배


*/
int N;
int citizen[12] = { 0 };
int connect[12][12] = { 0 };
int visit[12] = { 0 };
int ans = 987654321;
vector<int> gu1;
vector<int> gu2;

bool check_connect(vector<int> v1, vector<int> v2) {
	int city[12] = { 0 };
	queue<int> q;
	//구역이 2개이상일때 확인
	if (v1.size() > 1) {
		q.push(v1[0]);
		//1구역 맨처음 도시로부터 순차 탐색 
		while (!q.empty()){
			int cur = q.front();
			q.pop();
			//방문한 도시는 1구역으로 지정
			city[cur] = 1;
			for (int i = 1; i <= N; i++) {
				//조건 현재 도시에서 연결되어있고 1구역으로 지정, 방문 하지 않은 도시 큐에 다시넣음 
				if (visit[i]==1 && connect[cur][i] == 1&& city[i]==0)
					q.push(i);
			}
		}
		// 1구역에 있는 도시들 값이 1이 아니면 연결이 안되어있음
		for (int i = 0; i < v1.size(); i++) {
			if (city[v1[i]] != 1)
				return false;
		}
	}
	if (v2.size() > 1) {
		q.push(v2[0]);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			city[cur] = 2;
			for (int i = 1; i <= N; i++) {
				if (visit[i] == 0 && connect[cur][i] == 1 && city[i] == 0)
					q.push(i);
			}
		}
		for (int i = 0; i < v2.size(); i++) {
			if (city[v2[i]] != 2)
				return false;
		}
	}
	return true;
}
void div_city(int cnt, int idx) {

	if (1 <= cnt) {
		vector<int> v1;
		vector<int> v2;
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 1)
				v1.push_back(i);
			else
				v2.push_back(i);
		}

		//구역이 한개도 없을경우
		if (v1.size() != 0 && v2.size() != 0) {

			//연결되어 있는지 확인
			if (check_connect(v1, v2)) {
				int c1_sum = 0;
				int c2_sum = 0;
				// 구역 합더하기
				for (int i = 0; i < v1.size(); i++) {
					c1_sum += citizen[v1[i]];
				}
				for (int i = 0; i < v2.size(); i++) {
					c2_sum += citizen[v2[i]];
				}
				//최소값 정하기
				ans = min(ans, abs(c1_sum - c2_sum));
			}
		}
	}
	for (int i = idx; i <= N; i++) {
		if (visit[i]==1)
			continue;
			visit[i] = 1;
			div_city(cnt + 1, i);
			visit[i] = 0;
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> citizen[i];
	}
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int to;
			cin >> to;
			connect[i][to] = 1;
			connect[to][i] = 1;
		}
	}
	div_city(0, 1);
	if (ans == 987654321)
		ans = -1;
	cout << ans << '\n';
	return 0;
}
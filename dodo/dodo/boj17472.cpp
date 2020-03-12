#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

/*
N x M ũ���� ����
�ٸ��� �ٴٿ��� �Ǽ��Ҽ� �ְ� ���̴� 2�̻��̴�. �ٸ��� �����̴�. �ٸ��� �����Ҽ� �ִ�.
�ٸ��� ��ġ�Ͽ� ��� ���� ����ǵ����Ѵ�. �ּ��� �ٸ� ���̸� ����Ѵ�.
���� ������ �ִ� 6��
1. ���� ��������
2. �������� �Ÿ��� Ȯ��
3. MST�� �ּ� �Ÿ��� ã��

�ϴ� �� ���� ã�� 1
���ǰ��� �ִ� 6��
*/
#define INF 987654321
typedef pair<int, int > pii;

int N, M;
int map[11][11];
int visit[11][11];
int island_Cnt = 0;
vector<pair<int, int>> island[7];//���ܰ���ǥ
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int d_Island[7][7];
int check[7] = { 0 };
int ans = -1;
queue<pair<int, int>> q;

void MST() {
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	for (int i = 1; i <= island_Cnt; i++) {
		if (d_Island[1][i] != INF) {
			pq.push(pii(d_Island[1][i], i));
		}
	}
	check[1] = 1;
	int temp = 0;
	while (!pq.empty()){
		int cur = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		if (check[cur])
			continue;
		temp += dist;
		check[cur] = 1;
		for (int i = 1; i <= island_Cnt; i++) {
			if (d_Island[cur][i] != INF) {
				pq.push(pii(d_Island[cur][i], i));
			}
		}
	}
	bool flag = true;
	for (int i = 1; i <= island_Cnt; i++) {
		if (check[i] == 0) {
			flag = false;
			break;
		}
	}
	if (flag)
		ans = temp;
}

void connect_land() {
	for (int i = 1; i <= island_Cnt; i++) {
		for (int j = 1; j <= island_Cnt; j++) {
			d_Island[i][j] = INF;
		}
	}
	for (int i = 1; i <= island_Cnt; i++) {
		for (int j = 0; j < island[i].size(); j++) {
			int x = island[i][j].second;
			int y = island[i][j].first;
			//4���� ����
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];;
				int cnt = 0;
				while (true) {
					if (nx < 0 || ny < 0 || ny >= N || nx >= M)
						break;
					if (map[ny][nx] == i)
						break;
					if (map[ny][nx] != 0) {
						if (cnt > 1) {
							if (d_Island[i][map[ny][nx]] > cnt) {
								d_Island[i][map[ny][nx]] = cnt;
								d_Island[map[ny][nx]][i] = cnt;
							}
						}
						break;
					}
					nx += dx[k];
					ny += dy[k];
					cnt++;
				}
			}
		}
	}
}
void spread(int x, int y, int num) {
	queue<pii> q;
	visit[y][x] = 1;
	q.push(pii(y, x));
	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();
		map[cy][cx] = num;
		//�ֺ��� ���� ������ �ܰ�����
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (map[ny][nx] == 0) {
					island[num].push_back(pii(cy, cx));
					break;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (map[ny][nx] == 1) {
					if (visit[ny][nx] == 0) {
						visit[ny][nx] = 1;
						q.push(pii(ny, nx));
					}
				}
			}
		}
	}
}
void div_island() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				if (visit[i][j] == 0) {
					spread(j, i, ++island_Cnt);
				}
			}
		}
	}
}
void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}
int main() {
	init();
	div_island();
	connect_land();
	MST();
	cout << ans << '\n';
	return 0;
}
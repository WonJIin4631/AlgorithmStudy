#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
/*
NxM ������ �ü� 3�� ��ġ, ��ĭ���� �ִ� 1���� �ü��� ����, �ü��� �� �Ͽ� ���ϳ� ���ݰ���, �ü��� ���ÿ� ����,
���ݰŸ��� D���� ����� �� , ������ ������ ���� ����, �������� ���� �ü����� ���� ���Ҽ� �ִ�.
���� ���� ���� ����, ������ ������ ���� ��ĭ �Ʒ��� �̵�, ��� ���� �����ǿ��� ���ܵǸ� ���ӳ�

M���� ĭ�� 3���� �ü��� ���Ѽ� �ִ� ��츦 ���Ѵ�-> prev�۹·� ��� ��츦 Ž��
�־��� ���ǿ� �°� �ù�
���� �����̴� �ͺ��� �ü��� ��ġ�� ��ĭ�� ���� �̵��Ѵ�.
���� �Ÿ��϶� ���ʿ��� ���� Ž��(�»��) �̼������ Ž��?

���� ���� ���� ���ؼ� ���� ����

*/

struct info {
	int y;
	int x;
	info(int y, int x) :y(y), x(x) {};
};
int N, M, D;
int ans = 0;
int gupos[16] = { 0 };
vector<info> archor;
vector<vector<int>> map;

void solve() {
	vector<vector<int>> tmp_map = map;
	vector<info> tmp_archor = archor;
	vector<vector<int>> visit(N + 1, vector<int>(M, 0));

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		queue<pair<int, int>> q;
		for (int j = 0; j < 3; j++) {
			bool check = false;
			for (int distance = 1; distance <= D; distance++) {
				int dy = -1;
				int dx = (distance - 1)*(-1);
				for (int k = 1; k < 2 * distance; k++) {
					int ny = tmp_archor[j].y + dy;
					int nx = tmp_archor[j].x + dx;
					dy = (k >= distance) ? dy + 1 : dy - 1;
					dx += 1;
					if (ny < 0 || nx < 0 || nx >= M)
						continue;
					if (tmp_map[ny][nx] == 1) {
						if (visit[ny][nx] == 0) {
							cnt++;
							visit[ny][nx] = 1;
							q.push(make_pair(ny, nx));
						}
						check = true;
						break;
					}
				}
				if (check)
					break;
			}
			tmp_archor[j].y--;
		}
		while (!q.empty()) {
			int ny = q.front().first;
			int nx = q.front().second;
			q.pop();
			tmp_map[ny][nx] = 0;
		}
	}
	ans = max(ans, cnt);
}

void per() {
	do{
		for (int i = 0; i < M; i++) {
			if (gupos[i] == 1) {
				archor.push_back(info(N, i));
			}
		}
		solve();
		archor.clear();
	} while (prev_permutation(gupos,gupos+M));
}
int main() {
	cin >> N >> M >> D;
	map = vector<vector<int>>(N + 1, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		gupos[i] = 1;
	}
	per();
	cout << ans << '\n';
	return 0;
}
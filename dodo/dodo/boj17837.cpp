#include<iostream>
#include<vector>
using namespace std;
/*
ü���� ũ�� N*N, ����ϴ� ���� ���� K��
�̵����� �����¿�
�� 1���� 1~K������ ������� �̵�
�Ѹ��� �̵��Ҷ� �÷��� �ִ� ���� ���� �̵�
���� 4�� �̻����� �׿����� �������� ���� 1000�� �̳� ����Ǹ� ���� ���� ��� 1000�ʰ��̸� -1 ���

�̵��ҷ��� ĭ�� ��,����,�Ķ� 3������ ����
��� - �̵��ҷ��� ĭ�� ���� �ִ� ��� ���� ����
������ - �׿� �ִ� ������ �ٲ� ���� ���� �ִ� ��� ������ �ٲ� ���·� ����
�Ķ��� �̵����� �ݴ�� �ϰ� ��ĭ �̵� ,���� �̵��� ĭ�� �Ķ����̸� ���⸸ �ٲ�
ü������ ����� �Ķ����� ����.

ó�� ����Ǯ��� ���� �������� ���� ->ó���Ұ� ���Ƽ� ������

�־��� �̵� ���ǿ� �°� �̵��Ѵ�.
���� ��ġ�� �˼� �ְ� 2���� �迭 ����
2���� �迭���������� ���ڸ��� �ִ� ���� � ������� �ִ��� �ľ��ϱ� ����
������ ���� ���° ���̿� �ִ��� �߿�
�����϶� ���� ~ size()-1���� ���� ĭ���� �̵� �ϰ� ���ش�
*/
struct info {
	int x;
	int y;
	int dir;
};

int dx[] = { 0, 1,-1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int N, K;
int ans = 1000;
int map[13][13] = { 0 };

vector<int> malMap[13][13];

info mal[11];
//�Է�
void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		int x, y, dir;
		cin >> y >> x >> dir;
		mal[i] = { x,y,dir };
		malMap[y][x].push_back(i);
	}

}

int find_h(int y, int x, int idx) {
	for (int i = 0; i < malMap[y][x].size(); i++) {
		if (malMap[y][x][i] == idx) {
			return i;
		}
	}
}

int change_dir(int dir) {
	if (dir == 1) {
		return 2;
	}
	else if (dir == 2) {
		return 1;
	}
	else if (dir == 3) {
		return 4;
	}
	else if (dir == 4) {
		return 3;
	}
}

// ���� ��ĭ �̵�
void moveMal(int idx) {
	int cx = mal[idx].x;
	int cy = mal[idx].y;
	int cd = mal[idx].dir;
	int nx = dx[cd] + cx;
	int ny = dy[cd] + cy;
	int h = find_h(cy, cx, idx);
	// ���� ü���� ����� ����
	if (nx >= 1 && nx <= N&&ny >= 1 && ny <= N) {
		//����ĭ�� ���
		if (map[ny][nx] == 0) {
			int cnt = 0;
			for (int i = h; i < malMap[cy][cx].size(); i++) {
				int temp = malMap[cy][cx][i];
				mal[temp].x = nx;
				mal[temp].y = ny;
				malMap[ny][nx].push_back(temp);
				cnt++;
			}
			for (int i = 0; i < cnt; i++) {
				malMap[cy][cx].pop_back();
			}
		}

		//����ĭ�� ����
		else if (map[ny][nx] == 1) {
			int cnt = 0;
			for (int i = malMap[cy][cx].size() - 1; i >= h; i--) {
				int temp = malMap[cy][cx][i];
				mal[temp].x = nx;
				mal[temp].y = ny;
				malMap[ny][nx].push_back(temp);
				cnt++;
			}
			for (int i = 0; i < cnt; i++) {
				malMap[cy][cx].pop_back();
			}

		}
		//����ĭ �Ķ�
		else if (map[ny][nx] == 2) {
			int ncd = change_dir(cd);
			int nnx = cx + dx[ncd];
			int nny = cy + dy[ncd];
			mal[idx].dir = ncd;
			if (nnx >= 1 && nnx <= N&&nny >= 1 && nny <= N) {
				if (map[nny][nnx] != 2) {
					moveMal(idx);
				}
			}
		}
	}
	else {
		int ncd = change_dir(cd);
		int nnx = cx + dx[ncd];
		int nny = cy + dy[ncd];
		mal[idx].dir = ncd;
		if (nnx >= 1 && nnx <= N&&nny >= 1 && nny <= N) {
			if (map[nny][nnx] != 2) {
				moveMal(idx);
			}
		}
	}
}
bool check_fin() {
	for (int i = 1; i <= K; i++) {
		int x = mal[i].x;
		int y = mal[i].y;
		if (malMap[y][x].size() >= 4)
			return true;
	}
	return false;
}

void solve() {
	int turn = 0;
	bool flag = false;
	while (true) {
		if (turn > 1000)
			break;
		for (int i = 1; i <= K; i++) {
			moveMal(i);
			if (check_fin()) {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
		turn++;
	}
	if (!flag)
		ans = -1;
	else {
		ans = turn + 1;
	}
}

int main() {
	input();
	solve();
	cout << ans << '\n';
	return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<string>
using namespace std;

/*
���̷��� M�� �ְ� ���ÿ� ����, ũ��� NxN
��ĭ�� 0  ���� 1 ���̷��� ���� ��ġ 2
��ĭ�� ���� + ���̷����� ���������� ���õ��� ���� ĭ�� ���� ��ŭ ���� �Ǹ� ���ĭ�� �����Ȱ��̴�. -> ���ĭ�� ��� Ȯ���ϴ� ���� ���̱� ���ؼ�

����+ �ù�?

*/

typedef pair<int, int> pii;
int map[51][51];
int visit[51][51];
int leftCan = 0;
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 987654321;
bool checkVirus[11] = { false };
vector<pii> virus;

void move_virus() {
	queue<pii> q;
	// ���õ� ���̷���
	for (int i = 0; i < virus.size(); i++) {
		if (checkVirus[i]) {
			q.push(pii(virus[i].first, virus[i].second));
			visit[virus[i].first][virus[i].second] = 1;
		}
	}
	int day = 0;
	//������� ���� ĭ�� ������ Ȯ�� ����
	int cnt = 0;
	while (true) {

		//���� ť�� ũ�Ⱑ �Ϸ絿�� ���� �ִ� ���̷���
		int qSZ = q.size();
		if (qSZ == 0)
			break;
		//���� �ȵ��� ��� Ȯ��
		bool flag = false;
		for (int i = 0; i < qSZ; i++) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
					//���� �ƴϰų� �湮���� ���� ĭ���� ����
					if (visit[ny][nx] == 0) {
						if (map[ny][nx] != 1) {
							visit[ny][nx] = 1;
							q.push(pii(ny, nx));
							//������ ĭ�� ���� ����
							cnt++;
							flag = true;
						}
					}
				}
			}
		}
		if (flag)
			day++;
		//���ݱ��� ������ ĭ�� ������ ������ ĭ�� ���� ��
		if (cnt == (leftCan + virus.size() - M)) {
			ans = min(ans, day);
			break;
		}
	}
	memset(visit, 0, sizeof(visit));
}
// ���̷��� ������ ĭ�� ��ġ�� M���� ����
void choose_virus(int cnt, int idx) {
	if (cnt == M) {
		move_virus();
		return;
	}
	for (int i = idx; i < virus.size(); i++) {
		if (!checkVirus[i]) {
			checkVirus[i] = true;
			choose_virus(cnt + 1, i + 1);
			checkVirus[i] = false;
		}
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				leftCan++;
			}
			if (map[i][j] == 2) {
				virus.push_back(pii(i, j));
			}
		}
	}
	choose_virus(0, 0);
	if (ans == 987654321)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
/*
NxN ũ�� ����� M������ �Ʊ��� ���� 1�ʿ� �����¿� 1ĭ�� �����ϼ� �ִ�. �ڽ��� ũ�⺸�� ū ����Ⱑ �ִ� ĭ�� �������� ����.
������ ĭ�� �������� �ִ�. �Ʊ���� �ڽ��� ũ�⺸�� �����ָ� ������ �ִ�. ���� ũ�� ������ �������� �ִ�
������ �ִ� ����Ⱑ 1������ �ش� ������������
1���� �̻��̸� �Ÿ��� ����� ����⸦ �Դ´�. �Ÿ��� ����� ����Ⱑ 2���� �̻��̸� ������-> ���� ���� ����⸦ �Դµ�.
���� �ڱ�� ���� ũ���� ������  ����ŭ ����⸦ �԰ԵǸ� 1����.

���� ũ��� ���� ����Ⱑ �ִ��� �ľ��� ���ٸ� ����
�ִٸ� ���ǿ� �°� ����⸦ �Դ´�. ���±濡 �ڽ��� ũ�⺸�� ���� ����Ⱑ ������ �԰� �̵���

������� ũ�⸦ �������� �迭�� ���� -> �����Ҷ� ������� ��ǥ�� ����
���� ���� ������� ���� �Ծ��� ����� ���� ����
�־��� ���ǿ� �°� �ù�
*/

typedef pair<int, int> pii;
int map[22][22] = { 0 };
int visit[22][22] = { 0 };
int leftFish[7] = { 0 };
vector<pii> fish[7];
int N;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int sx, sy;
int s_sz = 2;
int s_cnt = 0;
int time = 0;

int c_fx;
int c_fy;
int findF(int x,int y) {
	memset(visit, 0, sizeof(visit));
	queue<pii> q;
	q.push(pii(y, x));
	visit[y][x] = 1;
	vector<pii> f;
	int can =0;
	bool flag = false;
	while (!q.empty()){
		//�̵��ð� �������� Ž��
		int qsz = q.size();
		//cout << qsz << '\n';
		if (flag) {
			while (!q.empty()){
				q.pop();
			}
			break;
		}
		for (int i = 0; i < qsz; i++) {
			int cx = q.front().second;
			int cy = q.front().first;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
					if (visit[ny][nx] == 0 ){
						//����Ⱑ ����ĭ
						if (map[ny][nx] <= s_sz) {
							visit[ny][nx] = 1;
							q.push(pii(ny, nx));
						}
						//������ �ִ� �����ĭ
						if (map[ny][nx] > 0 && map[ny][nx] < s_sz) {
							f.push_back(pii(ny, nx));
						}
					}
				}
			}
		}
		if (f.size() > 0) {
			//�����Ͽ� ù��° ����� ����
			sort(f.begin(), f.end());
			c_fx = f[0].second;
			c_fy = f[0].first;
			flag = true;
		}
		can++;
	}
	f.clear();
	if (flag)
		return can;
	else
		return -1;
}
int solve() {
	int time = 0;
	while (true) {
		bool flag = true;
		//���� ����Ⱑ ���� �ִ��� Ȯ��
		for (int i = 1; i <= s_sz; i++) {
			if (leftFish[i] > 0) {
				flag = false;
				break;
			}
		}
		if (flag)
			break;
		//���� ����� ã��
		int dist;
		dist = findF(sx, sy);
		//������ ���������� ������ ���°��
		if (dist == -1)
			break;
		//�ڽ��� ũ�⺸�� ������ ������ ����
		if (map[c_fy][c_fx] <= s_sz) {
			s_cnt++ ;
			if (s_cnt == s_sz) {
				s_cnt = 0;
				s_sz++;
			}
		}
		//�̵��� ĭ��ŭ �ð�����
		time += dist;
		//���� ����� ������
		leftFish[map[c_fy][c_fx]]--;
		map[c_fy][c_fx] = 0;
		//�����ġ �ʱ�ȭ
		sx = c_fx;
		sy = c_fy;
	}
	return time;
}
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			if (n == 0)
				continue;
			if (n == 9) {
				sx = j, sy = i;
				continue;
			}
			map[i][j] = n;
			leftFish[n]++;
			fish[n].push_back(pii(i, j));
		}
	}
}
int main() {
	init();
	cout << solve() << '\n';
	return 0;
}
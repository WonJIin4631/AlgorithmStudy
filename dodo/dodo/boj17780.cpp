#include<iostream>
#include<queue>
#include<deque>
using namespace std;
/*
ü���� ũ�� 4<=N<=12, ���� ���� 4<=K<=10
0 ���: �̵��������� �̵�, �̹��ִ°�� ���� ���� �ξ���
1 ������: �̵��������� �̵�, ���°�� ���� ���� ����, �ִ°�� �������ιٲ�� ������ �÷���
2 �Ķ���: �̵����� �ݴ� �̵�, ���� ����ĭ�� �Ķ����̸� ���⸸ �ݴ��
ü���� ��� ��� �Ķ����� ����
*/
int N, K;
int map[14][14];
int malMap[14][14];
int dx[] = { 0,1,-1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int ans = 0;

struct Node {
	int state;
	int dir;
	int y;
	int x;
};
deque<int> mal[12];
Node malInfo[12];
queue<Node> q;
int change_dir(int dir) {
	if (dir == 1)
		return 2;
	else if (dir == 2)
		return 1;
	else if (dir == 3)
		return 4;
	else
		return 3;
}
void solve() {
	while (true) {
		if (ans > 1000)
			break;
		int cnt = 0;
		for (int i = 1; i <= K; i++) {
			int state = malInfo[i].state;
			if (state == 1) {
				cnt++;
				int dir = malInfo[i].dir;
				int y = malInfo[i].y;
				int x = malInfo[i].x;
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				//�� �ȿ� ������
				if (ny >= 1 && ny <= N&&nx >= 1 && nx <= N) {
					//�Ķ���
					if(map[ny][nx]==2){
						cout << "blue: ";
						dir = change_dir(dir);
						nx = x + dx[dir];
						ny = y + dy[dir];
						if (map[ny][nx] == 2) {
							malInfo[i] = { state,dir,y,x, };
						}
						else {
							malInfo[i] = { state,dir,ny,nx, };
							malMap[ny][nx] = i;
							malMap[y][x] = 0;
						}
					}
					//����ĭ�� ���
					if (map[ny][nx] == 0) {
						cout << "white: ";
						//����ĭ�� ���� ������
						if (malMap[ny][nx] == 0) {
							cout << " NO\n";
							malInfo[i] = { state,dir,ny,nx };
							malMap[y][x] = 0;
							malMap[ny][nx] = i;
						}
						//���� ������
						else {
							cout << " yes\n";
							malInfo[i].state = 0;
							malMap[y][x] = 0;
							int nMal = malMap[ny][nx];
							int sz = mal[i].size();
							for (int k = 0; k < sz; k++) {
								int temp = mal[i].front();
								mal[i].pop_front();
								mal[nMal].push_back(temp);
							}
						}
					}
					//����ĭ�� ������
					else if (map[ny][nx] == 1) {
						cout << "red: ";
						if (malMap[ny][nx] == 0) {
							cout << " NO\n";
							int sz = mal[i].size();
							int chgMal_Num = mal[i].back();
							for (int k = 0; k < sz; k++) {
								int temp = mal[i].back();
								mal[i].pop_back();
								mal[chgMal_Num].push_front(temp);
							}
							malInfo[i].state = 0;
							malInfo[chgMal_Num].state = 1;
							malInfo[chgMal_Num].y = ny;
							malInfo[chgMal_Num].x = nx;
							malMap[y][x] = 0;
							malMap[ny][nx] = chgMal_Num;
						}
						else {
							cout << " Yes\n";
							int sz = mal[i].size();
							malInfo[i].state = 0;
							int nMal = malMap[ny][nx];
							malMap[y][x] = 0;
							for (int k = 0; k < sz; k++) {
								int temp = mal[i].back();
								mal[i].pop_back();
								mal[nMal].push_back(temp);
							}
						}
					}

				}
				else {
					cout << "out: ";
					dir = change_dir(dir);
					nx = x + dx[dir];
					ny = y + dy[dir];
					if (map[ny][nx] == 2) {
						malInfo[i] = { state,dir,y,x, };
					}
					else {
						malInfo[i] = { state,dir,ny,nx, };
						malMap[ny][nx] = i;
						malMap[y][x] = 0;
					}
				}
			}
			if (state == 1) {
				cout << "MAl: " << i << '\n';
				for (int k = 1; k <= N; k++) {
					for (int j = 1; j <= N; j++) {
						cout << malMap[k][j] << ' ';
					}
					cout << '\n';
				}
				cout << "-------------------\n";
			}
		}
		if (cnt == 1) {
			break;
		}
		ans++;
	}
}
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		cin >> malInfo[i].y >> malInfo[i].x >> malInfo[i].dir;
		malInfo[i].state = 1;
		malMap[malInfo[i].y][malInfo[i].x] = i;
	}
	for (int i = 1; i <= K; i++) {
		mal[i].push_back(i);
	}
	solve();
	cout << ans << '\n';
	return 0;
}
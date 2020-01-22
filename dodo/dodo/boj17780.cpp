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
1~K���� �ݺ������� ���� -> ���� ������ ���� �����̸� �ǾƷ��� ���� �������� ���� ������
*/
int N, K;
int map[14][14];
int malMap[14][14];
int dx[] = { 0,1,-1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int ans = 0;

struct Node {
	int dir;
	int y;
	int x;
};
deque<int> mal[12];
Node malInfo[12];
int parent[12];
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
void white_Block(int num,int ny,int nx,int y,int x) {
	if (malMap[ny][nx] == 0) {
		malInfo[num].y = ny;
		malInfo[num].x = nx;
		malMap[y][x] = 0;
		malMap[ny][nx] = num;
	}
	else {
		malMap[y][x] = 0;
		int nextNum = malMap[ny][nx];
		int sz = mal[num].size();
		for (int i = 0; i < sz; i++) {
			int temp = mal[num].front();
			mal[num].pop_front();
			mal[nextNum].push_back(temp);
			parent[temp] = nextNum;
		}
	}
}
void red_Block(int num, int ny, int nx, int y, int x) {
	if (malMap[ny][nx] == 0) {
		malMap[y][x] = 0;
		int chgNum = mal[num].back();
		malMap[ny][nx] = chgNum;
		malInfo[chgNum].x = nx;
		malInfo[chgNum].y = ny;
		int sz = mal[num].size();
		for (int i = 0; i < sz; i++) {
			int temp = mal[num].back();
			mal[num].pop_front();
			mal[chgNum].push_back(temp);
			parent[temp] = chgNum;
		}
	}
	else {
		malMap[y][x] = 0;
		int nextNum = malMap[ny][nx];
		int sz = mal[num].size();
		for (int i = 0; i < sz; i++) {
			int temp = mal[num].back();
			mal[num].back();
			mal[nextNum].push_back(temp);
			parent[temp] = nextNum;
		}
	}
}
void blue_Block(int num,int dir, int y, int x) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (map[ny][nx] == 2) {
		malInfo[num].dir = dir;
	}
	else if (map[ny][nx] == 1) {
		malInfo[num].dir = dir;
		cout << "RED" << '\n';
		//red_Block(num, ny, nx, y, x);
	}
	else {
		if (nx >= 1 && nx <= N&&ny >= 1 && ny <= N) {
			malMap[y][x] = 0;
			malMap[ny][nx] = num;
			malInfo[num].dir = dir;
			malInfo[num].y = ny;
			malInfo[num].x = nx;
		}
		else {
			malInfo[num].dir = dir;
		}
	}
}
void over_Block(int num, int dir, int y, int x) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	cout << ny << ' ' << nx << '\n';
	if (map[ny][nx] == 2) {
		malInfo[num].dir = dir;
	}
	else if (map[ny][nx] == 1) {
		malInfo[num].dir = dir;
		//red_Block(num, ny, nx, y, x);
	}
	else {
		if (nx >= 1 && nx <= N&&ny >= 1 && ny <= N) {
			malMap[y][x] = 0;
			malMap[ny][nx] = num;
			malInfo[num].dir = dir;
			malInfo[num].y = ny;
			malInfo[num].x = nx;
		}
		else {
			malInfo[num].dir = dir;
		}
	}
}
void solve() {
	while (true){
		ans++;
		for (int i = 1; i <= K; i++) {
			int curMal = parent[i];
			int dir = malInfo[curMal].dir;
			int x = malInfo[curMal].x;
			int y = malInfo[curMal].y;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 1 && nx <= N&&ny >= 1 && ny <= N) {
				if (map[ny][nx] == 0) {
					white_Block(curMal, ny, nx,y,x);
				}
				else if (map[ny][nx] == 1) {
					red_Block(curMal, ny, nx, y, x);
				}
				else if (map[ny][nx] == 2) {
					blue_Block(curMal, change_dir(dir), y, x);
				}
			}
			else {
				over_Block(curMal, change_dir(dir), y, x);
			}
			cout << ans << '\n';
			for (int k = 1; k <= N; k++) {
				for (int j = 1; j <= N; j++) {
					cout << malMap[k][j] << ' ';
				}
				cout << '\n';
			}
			cout << "-------------------\n";
		}
		bool flag = true;
		for (int k = 2; k <= K; k++) {
			if (parent[1] != parent[k]) {
				flag = false;
				break;
			}
		}
		if (flag)
			break;
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
		malMap[malInfo[i].y][malInfo[i].x] = i;
	}
	for (int i = 1; i <= K; i++) {
		mal[i].push_back(i);
		parent[i] = i;
	}
	for (int k = 1; k <= N; k++) {
		for (int j = 1; j <= N; j++) {
			cout << malMap[k][j] << ' ';
		}
		cout << '\n';
	}
	cout << "-------------------\n";

	solve();
	cout << ans << '\n';
	return 0;
}
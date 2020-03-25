#include<iostream>
#include<vector>
#include<deque>
using namespace std;
/*
 ����� ������ �� ���̰� �þ�� 
 ���� ���̳� �ڱ� �ڽ��� ���� �ε����� ������ ������
 ���� ó���� ���������� ���Ѵ�.
 �� �ʸ��� �̵��ϴµ� ��Ģ�� �ִ�
 �Ӹ����� �̵� ����� �ִٸ� ������ �������� �ʴ´�
 ���� �̵��� ĭ�� ����� ���ٸ� ������ ����

2���� �迭 map�� ���� ���� ��ġ�� ����
��ť�� �̿��� ���� �̵���θ� ����
*/
typedef pair<int, char> pic;
typedef pair<int, int> pii;
int N, K, L;
int map[102][102] = { 0 };
int apple[102][102] = { 0 };
vector<pic> v;
//��,��,��,��
int dx[] = { 0,1,0,-1};
int dy[] = {1,0,-1,0};

int chDir(int d, char c) {
	if (c == 'L') {
		if (d == 3)
			return 0;
		return d + 1;
	}
	else {
		if (d == 0)
			return 3;
		return d - 1;
	}
}

int main() {
	cin >> N>>K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		apple[y-1][x-1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t;
		char d;
		cin >> t >> d;
		v.push_back(pic(t, d));
	}
	int time = 0;
	map[0][0]= 1;
	deque<pii> dq;
	dq.push_back(pii(0, 0));
	int dir = 1;
	int cidx = 0;
	while (true){
		time++;
		int nx = dq.front().second + dx[dir];
		int ny = dq.front().first + dy[dir];
		if (nx < 0|| nx >= N||ny < 0 || ny >= N)
			break;
		if (map[ny][nx] == 1)
			break;
		map[ny][nx] = 1;
		dq.push_front(pii(ny, nx));
		if (apple[ny][nx] == 0) {
			map[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		else {
			apple[ny][nx] = 0;
		}
		if (cidx < v.size()) {
			if (v[cidx].first == time) {
				dir = chDir(dir, v[cidx].second);
				cidx++;
			}
		}
	}
	cout << time << '\n';
	return 0;
}
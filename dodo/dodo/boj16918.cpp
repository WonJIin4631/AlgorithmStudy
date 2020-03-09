#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
��ź�� ��ġ�Ѵ�.
���� 1�� ����  �������� �ƹ��͵� �����ʴ´�.
���� 1�� ���� ��ź�� ��ġ�Ǿ� ���� ���� ��� ĭ�� ��ź ��ġ
���� 1����  3���� ��ġ�� ��ź ���������� ��ź�� ���� ����

�ݺ�-> �ù�
*/
char map[202][202];
char temp[202][202];
int visit[202][202];
int R, C, N;
int dx[] = {0, 0,0,-1,1 };
int dy[] = {0, -1,1,0,0 };

typedef pair<int, int> pii;
vector<pii> boom;

int main() {
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	if (N == 0 || N == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}
	}
	else {
		int time = 1;
		while (true){
			boom.clear();
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (map[i][j] == 'O')
						boom.push_back(pii(i, j));
				}
			}
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					map[i][j] = 'O';
				}
			}
			time++;
			if (time ==N)
				break;
			for (int i = 0; i < boom.size(); i++) {
				int cx = boom[i].second;
				int cy = boom[i].first;
				for (int j = 0; j < 5; j++) {
					int nx = cx + dx[j];
					int ny = cy + dy[j];
					if (nx >= 0 && nx < C&&ny >= 0 && ny < R)
						map[ny][nx] = '.';
				}
			}
			time++;
			if (time ==N)
				break;
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}
	}
}
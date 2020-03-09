#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
ÆøÅºÀ» ¼³Ä¡ÇÑ´Ù.
´ÙÀ½ 1ÃÊ µ¿¾È  º½¹ö¸ÇÀº ¾Æ¹«°Íµµ ÇÏÁö¾Ê´Â´Ù.
´ÙÀ½ 1ÃÊ µ¿¾È ÆøÅºÀÌ ¼³Ä¡µÇ¾î ÀÖÁö ¾ÊÀº ¸ðµç Ä­¿¡ ÆøÅº ¼³Ä¡
´ÙÀ½ 1ÃÊÈÄ  3ÃÊÀü ¼³Ä¡ÇÑ ÆøÅº Æø¹ßÀÎÀüÇÑ ÆøÅºÀº °°ÀÌ ÅÍÁü

¹Ýº¹-> ½Ã¹Ä
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
#include<iostream>
#include<queue>
#include<deque>
using namespace std;
/*
체스판 크기 4<=N<=12, 말의 개수 4<=K<=10
0 흰색: 이동방향으로 이동, 이미있는경우 맨위 말이 두어짐
1 빨간색: 이동방향으로 이동, 없는경우 말의 순서 역순, 있는경우 역순으로바뀐뒤 맨위에 올려짐
2 파란색: 이동방향 반대 이동, 만약 다음칸도 파란색이면 방향만 반대로
체스판 벗어날 경우 파란색과 같음
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
				//판 안에 있을때
				if (ny >= 1 && ny <= N&&nx >= 1 && nx <= N) {
					//파랑색
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
					//다음칸이 흰색
					if (map[ny][nx] == 0) {
						cout << "white: ";
						//다음칸에 말이 없을때
						if (malMap[ny][nx] == 0) {
							cout << " NO\n";
							malInfo[i] = { state,dir,ny,nx };
							malMap[y][x] = 0;
							malMap[ny][nx] = i;
						}
						//말이 있을때
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
					//다음칸이 빨간색
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
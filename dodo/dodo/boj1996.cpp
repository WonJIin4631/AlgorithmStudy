#include<iostream>

using namespace std;
int N;
char map[1001][1001];
int map2[1001][1001];

int dx[] = {-1,-1,-1,0,0,1,1,1  };
int dy[] = {-1,0,1,-1,1,-1,0,1  };

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != '.') {
				for (int k = 0; k < 8; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
						map2[ny][nx]+=map[i][j]-'0';
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != '.')
				cout << '*';
			else {
				if (map2[i][j] < 10)
					cout << map2[i][j];
				else
					cout << 'M';
			}
		}
		cout << '\n';
	}
}
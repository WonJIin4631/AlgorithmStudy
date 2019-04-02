#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAX_SIZE 50
#define INF 99999999
int N, M,ans;
int map[MAX_SIZE+1][MAX_SIZE+1] = { 0, };
bool visited[14];
vector<pair<int, int>> home;
vector<pair<int, int>> chick;

void DFS(int cur_num,int cur_cnt){
	if (cur_num > chick.size())
		return;
	if (cur_cnt == M) {
		int cmp = 0;
		for (int i = 0; i < home.size(); i++) {
			int dist = INF;
			for (int j = 0; j < chick.size(); j++) {
				if (visited[j]) {
					int x = abs(home[i].first - chick[j].first);
					int y = abs(home[i].second - chick[j].second);
					int d = x + y;
					dist = min(dist, d);
				}
			}
			cmp += dist;
		}
		ans = min(ans, cmp);
		return;
	}
	visited[cur_num] = 1;
	DFS(cur_num + 1, cur_cnt + 1);
	visited[cur_num] = 0;
	DFS(cur_num + 1, cur_cnt);
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2) {
				chick.push_back(make_pair(i, j));
			}
		}
	}
	ans = INF;
	DFS(0, 0);
	cout << ans << endl;
}
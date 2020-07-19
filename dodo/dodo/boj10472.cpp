#include<iostream>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int P;
int black_Cnt[51] = { 0 };
int ans[51];
string map;
set<string> Set;
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };
bool isIn(int x, int y) {
	return x >= 0 && x < 3 && y >= 0 && y < 3;
}
int solve(string s) {
	queue<string> q;
	q.push("000000000");
	Set.insert("000000000");
	int moveCnt = 0;
	while (!q.empty()){
		int qsz = q.size();
		for (int ss= 0; ss < qsz;ss++) {
			string cur = q.front();
			q.pop();
			for (int i = 0; i < 9; i++) {
				string temp = cur;
				int x = i % 3;
				int y = i / 3;
				for (int d = 0; d < 5; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					int nIdx = nx + (ny * 3);
					if(nx>=0&&nx<3&&ny>=0&&ny<3){
						if (temp[nIdx] == '0')
							temp[nIdx] = '1';
						else
							temp[nIdx] = '0';
					}
				}
				if (Set.find(temp) != Set.end())
					continue;
				if (temp == s) {
					return moveCnt + 1;
				}
				q.push(temp);
				Set.insert(temp);
			}
		}
		moveCnt++;
	}
}
int main() {
	cin >> P;
	for (int i = 0; i < P; i++) {
		for (int j = 0; j < 9; j++) {
			char c;
			cin >> c;
			if (c == '.')
				map += '0';
			else
				map += '1';
		}
		if (map == "000000000")
			cout << 0 << '\n';
		else
			cout<<solve(map)<<'\n';
		Set.clear();
		map.clear();
	}
	return 0;
}
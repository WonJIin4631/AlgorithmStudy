#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
�ź��̴� L��R ����� ���� �ź��̰� �̵��� ������ ����Ѵ� 
������ ���� �κ��� ���簢���̴�.

�¿� ��ܰ��� �¿��ϴܰ��� ��� �� �����ذ��鼭 ���Ѵ�.
*/

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int T;

int chDir(int d, char c) {
	if (c == 'L') {
		if (d == 0)
			return 3;
		return d - 1;
	}
	else {
		if (d == 3)
			return 0;
		return d + 1;
	}
}
int main() {
	cin >> T;
	while (T--){
		string s;
		int minx = 500, miny = 500, maxx = 500, maxy = 500;
		int cx = 500, cy = 500;
		int dir = 1;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'F') {
				cx += dx[dir];
				cy += dy[dir];
			}
			else if(s[i]=='B'){
				cx -= dx[dir];
				cy -= dy[dir];
			}
			else {
				dir = chDir(dir, s[i]);
			}
			minx = min(minx, cx);
			miny = min(miny, cy);
			maxx = max(maxx, cx);
			maxy = max(maxy, cy);
		}
		cout << (maxx - minx)*(maxy-miny) << '\n';
	}
	return 0;
}
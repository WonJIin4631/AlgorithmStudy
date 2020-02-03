#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

/*
N*N ũ�� �迭, �������� �ٸ� ������ ĭ�� ����, ���� ��ȯ�Ѵ�, ��� ���� ������ �̷���� �ִ� ���� ��κ� ��� �Ա�
��� ��,�� Ȯ���ϸ� �ð��� �����ɸ��� �ٲ� �κи� �� �� �˻�
*/
char map[52][52];
int ans = 0;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int N;
void check() {

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 1; j < N; j++) {
			if (map[i][j - 1] == map[i][j])
				cnt++;
			else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[j + 1][i] == map[j][i])
				cnt++;
			else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}
	ans = max(1, ans);
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
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N - 1; x++) {

			swap(map[y][x], map[y][x + 1]);
			check();
			swap(map[y][x], map[y][x + 1]);
				
			swap(map[y][x], map[y + 1][x]);
			check();
			swap(map[y][x], map[y + 1][x]);
		}
	}
	cout << ans << '\n';
	return 0;
}
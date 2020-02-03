#include<iostream>
using namespace std;

/*
길이 지나갈 수 있으려면 모든 칸의 높이가 같아야됨 단, 경사로를 놓아 지나갈수 있는 길을 만들수 있다. 경사로 높이는 무조건 1 길이는 L
지도에서 갈수 있다 -> 한쪽 끝에서 반대쪽 끝까지 갈수 있다.
경사로 조건
경사로는 낮은 칸에 위치, L개의 연속된 칸 바닥에 모두 접촉
낮은칸 높은 칸 높이 차이 무조건 1

경사로 중복 설치 X

경사로 방향은 2가지-> 오르막, 내리막
행, 열 등산로 개수 파악
1. 높이가 같은 등산로 파악
2. 등산로가 만들어진 곳 이외 경사로를 두어 확인
양쪽 끝에서 시작했을때 생겨진 경사로에 맞게 이동가능 한쪽에서만 이동가능 하면 안됨

*/

int map[101][101];
int hang[101] = { 0 };
int yeol[101] = { 0 };
int ans = 0;
int N, L;

void solve() {
	// 행
	for (int i = 0; i < N; i++) {
		int prev_height = map[i][0];
		int same_cnt = 1;
		bool flag = true;
		int temp[101] = { 0 };
		//1은 오르막 -1은 내리막
		for (int j = 1; j < N; j++) {
			if (!flag)
				break;
			if (prev_height == map[i][j]) {
				same_cnt++;
				continue;
			}
			//높이차이 1보다 클경우
			if (prev_height + 1 < map[i][j])
				flag = false;
			else if (prev_height - 1 > map[i][j])
				flag = false;
			//이전보다 높을경우
			else if (prev_height + 1 == map[i][j]) {
				//경사로 칸 부족
				if (j - L < 0 || same_cnt < L)
					flag = false;
				else {
					for (int k = j - L; k < j; k++) {
						if (temp[k] == 0)
							temp[k] = 1;
						else {
							flag = false;
							break;
						}
					}
				}
				prev_height = map[i][j];
				same_cnt = 1;
			}
			//이전보다 낮을경우
			else if (prev_height - 1 == map[i][j]) {
				//경사로 칸 부족
				if (j + L - 1 >= N)
					flag = false;
				else {
					for (int k = j; k < j + L; k++) {
						if (temp[k] == 0 && map[i][j] == map[i][k]) {
							temp[k] = -1;
						}
						else {
							flag = false;
							break;
						}
					}
				}
				prev_height = map[i][j];
				j += L-1;
				same_cnt = L;
			}
		}
		if (!flag)
			continue;
		//반대쪽에서 진행 경사로 확인하며
		for (int j = N - 1; j >= 1; j--) {
			if (!flag)
				break;
			if (map[i][j] == map[i][j - 1])
				continue;
			if (map[i][j] == map[i][j - 1] + 1) {
				if (temp[j - 1] != 1)
					flag = false;
			}
			if (map[i][j] == map[i][j - 1] - 1) {
				if (temp[j] != -1)
					flag = false;
			}
		}
		if (flag)
			hang[i] = 1;
	}
	//열
	for (int i = 0; i < N; i++) {
		int prev_height = map[0][i];
		int same_cnt = 1;
		bool flag = true;
		int temp[101] = { 0 };
		//1은 오르막 -1은 내리막
		for (int j = 1; j < N; j++) {
			if (!flag)
				break;
			if (prev_height == map[j][i]) {
				same_cnt++;
				continue;
			}
			//높이차이 1보다 클경우
			if (prev_height + 1 < map[j][i])
				flag = false;
			if (prev_height - 1 > map[j][i])
				flag = false;
			//이전보다 높을경우
			else if (prev_height + 1 == map[j][i]) {
				//경사로 칸 부족
				if (j - L < 0 || same_cnt < L)
					flag = false;
				else {
					for (int k = j - L; k < j; k++) {
						if (temp[k] == 0)
							temp[k] = 1;
						else {
							flag = false;
							break;
						}
					}
				}
				prev_height = map[j][i];
				same_cnt = 1;
			}
			//이전보다 낮을경우
			else if (prev_height - 1 == map[j][i]) {
				//경사로 칸 부족
				if (j + L - 1 >= N)
					flag = false;
				else {
					for (int k = j; k < j + L; k++) {
						if (temp[k] == 0 && map[j][i] == map[k][i]) {
							temp[k] = -1;
						}
						else {
							flag = false;
							break;
						}
					}
				}
				prev_height = map[j][i];
				j += L - 1;
				same_cnt = L;
			}
		}
		if (!flag)
			continue;


		for (int j = N - 1; j >= 1; j--) {
			if (!flag)
				break;
			if (map[j][i] == map[j - 1][i])
				continue;
			if (map[j][i] == map[j - 1][i] + 1) {
				if (temp[j - 1] != 1)
					flag = false;
			}
			if (map[j][i] == map[j - 1][i] - 1) {
				if (temp[j] != -1)
					flag = false;
			}
		}
		if (flag)
			yeol[i] = 1;
	}
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	for (int i = 0; i < N; i++) {
		if (hang[i] == 1)
			ans++;
		if (yeol[i] == 1)
			ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
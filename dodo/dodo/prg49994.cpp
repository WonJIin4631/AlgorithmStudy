#include <string>
#include<iostream>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int solution(string dirs) {
	int answer = 0;
	int x = 5;
	int y = 5;
	bool map[12][12][12][12] = { false };
	for (int i = 0; i < dirs.size(); i++) {
		int nx;
		int ny;
		if (dirs[i] == 'U') {
			nx = x + dx[1];
			ny = y + dy[1];
			if (ny > 10)
				continue;
		}
		else if (dirs[i] == 'D') {
			nx = x + dx[0];
			ny = y + dy[0];
			if (ny < 0)
				continue;
		}
		else if (dirs[i] == 'R') {
			nx = x + dx[3];
			ny = y + dy[3];
			if (nx > 10)
				continue;
		}
		else {
			nx = x + dx[2];
			ny = y + dy[2];
			if (nx < 0)
				continue;

		}
		if (!map[y][x][ny][nx]) {
			answer++;
			map[ny][nx][y][x] = true;
			map[y][x][ny][nx] = true;
		}
		x = nx;
		y = ny;
	}
	return answer;
}
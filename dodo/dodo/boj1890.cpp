#include <iostream>
#include <cstring> 
using namespace std;

int N;
int map[101][101];
long long dp[101][101]; 
long long path(int y, int x){
	if (y == N - 1 && x == N - 1)
		return 1;
	long long &result = dp[y][x];
	if (result != -1)
		return result;
	result = 0;
	if (y != N - 1 && y + map[y][x] < N)
		result += path(y + map[y][x], x);

	if (x != N - 1 && x + map[y][x] < N)
		result += path(y, x + map[y][x]);
	return result;
}

int main(){
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << path(0, 0) <<'\n';
}
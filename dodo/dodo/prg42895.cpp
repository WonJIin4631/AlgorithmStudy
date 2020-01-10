#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int ans = 9;
int MAX = 9;

void DFS(int cnt, int num, int N, int number) {
	if (cnt >= 9)
		return;

	if (num == number)
		ans = min(ans, cnt);
	int n = 0;
	for (int i = 0; i < 8; i++) {
		n = (n * 10) + N;
		DFS(cnt + i + 1, num + n, N, number);
		DFS(cnt + i + 1, num - n, N, number);
		if (num != 0) {
			DFS(cnt + i + 1, num * n, N, number);
			DFS(cnt + i + 1, num / n, N, number);
		}
	}
}
int solution(int N, int number) {
	int answer = 0;
	DFS(0, 0, N, number);
	if (ans == 9)
		answer = -1;
	else
		answer = ans;
	return answer;
}
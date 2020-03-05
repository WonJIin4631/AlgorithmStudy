#include<iostream>
#include<algorithm>	
using namespace std;
/*
계란 2개를 서로 친다 각 계란의 내구도는 상대 계란의 무게만큼 줄음, 내구도가 0이하가 되면 깨짐
1번 규칙 가장 왼쪽 계란을 든다
2번 손에 들고있는 계란으로 깨지지 않은 계란 중 하나를 친다 손에 있는계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다 이후에 계란 원위치 후 3번과정 수행
3번 가장 최근에 든 계란 한칸 오른쪽 계란 손에듬 2번과정 수행 가장 최근에 친 계란이 가장 오른쪽이면 종료

깰수 있는 계란의 최대 개수를 출력
DFS를 통해서 조건에 맞는 경우에 대해서 완전탐색 하여 문제를 해결

*/
int eggS[8 + 1];
int eggW[8 + 1];
int N, ans;

bool isBroken(int idx) {
	if (eggS[idx] <= 0)
		return true;
	else
		return false;
}

void DFS(int idx) {
	if (idx == N) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (isBroken(i))
				count++;
		}
		ans = max(ans, count);
		return;
	}
	if (isBroken(idx)) {
		DFS(idx+ 1);
		return;
	}
	bool check = true;

	for (int i = 0; i < N; i++) {
		if (i == idx || isBroken(i))
			continue;
		eggS[idx] -= eggW[i];
		eggS[i] -= eggW[idx];
		DFS(idx + 1);
		check = false;
		eggS[idx] += eggW[i];
		eggS[i] += eggW[idx];

	}
	if (check)
		DFS(idx + 1);

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> eggS[i] >> eggW[i];
	}
	ans = 0;
	DFS(0);
	cout << ans << '\n';
	return 0;
}
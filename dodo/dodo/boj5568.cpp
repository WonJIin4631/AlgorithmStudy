#include<iostream>
#include<string>
#include<set>
using namespace std;

int N;
int K;
string numList[11];
bool visit[11] = { 0 };
string curNum;
set<string> Set;
int ans = 0;
void DFS(int cnt) {
	if (cnt == K) {
		if (Set.find(curNum) == Set.end()) {
			Set.insert(curNum);
			ans++;
		}
		return;
	}
	int curLen = curNum.length();
	for (int i = 0; i < N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			curNum += numList[i];
			DFS(cnt + 1);
			curNum.erase(curLen, numList[i].length());
			visit[i] = false;
		}
	}
}
int main() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++) {
		cin >> numList[i];
	}
	DFS(0);
	cout << ans << '\n';
	return 0;
}
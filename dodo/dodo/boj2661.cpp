#include<iostream>
#include<string>
using namespace std;
/*
숫자 1,2,3 으로만 이루어진 수열이 있다. 길이가 N인 수열에서 인접한 수열에 같은 수의 수열이 있으면 나쁜 수열이다.
좋은 수열 중 가작 작은 값을 가진 수열을 출력한다.


DFS로 푼다 
수열의 길이 반까지 나오는 중복된 수열을 찾는다.
처음 나오게 되는 수열이 제일 작은 값이다 -> 1,2,3 이순서로 추가했기 때문

*/
bool flag = false;
char numList[3] = {'1','2','3' };
int N;
string ans = "";
void DFS(int idx,char c) {
	if (idx-1 == N) {
		cout << ans << '\n';
		exit(0);
	}
	ans += c;
	for (int i = 1; i <= idx / 2; i++) {
		string temp1 = ans.substr(idx - i, i);
		string temp2 = ans.substr(idx - i * 2, i);
		if (temp1 == temp2) {
			ans.erase(idx - 1);
			return;
		}
	}
	for (int i = 0; i < 3; i++) {
		DFS(idx + 1, numList[i]);
	}
	ans.erase(idx-1);
}
int main() {
	cin >> N;
	for (int i = 0; i < 3; i++) {
		DFS(1,numList[i]);
	}
	return 0;
}
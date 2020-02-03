#include<iostream>
#include<vector>
using namespace std;

/*
자연수 K 3이상 1000이하
크기 1001 배열 생성
0에서부터 1씩 증가

DFS로 모든경우 탐색
조건 
3개의 삼각형을 더해서 찾을려는 수가 나와야됨 미만, 초과 안됨
3개 미만에서 찾을려는 수보다 크게 되면 탐색 할 필요없음
나올수 있는경우에는 더이상 찾지 않아도 됨
*/
int T;
vector<int> v;
int num;
bool flag;
void DFS(int cnt,int sum) {
	if (cnt == 3) {
		if (sum == num)
			flag = true;
		return;
	}
	if (flag)
		return;
	if (sum > num)
		return;
	for (int i = 0; i < v.size(); i++) {
		DFS(cnt + 1, sum + v[i]);
	}
}
int main() {
	int curIdx = 1;
	while (true){
		int checkPos=curIdx*(curIdx+1)/2;
		if (checkPos > 1000)
			break;
		v.push_back(checkPos);
		curIdx++;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		flag = false;
		cin >> num;
		DFS(0, 0);
		if (flag)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}
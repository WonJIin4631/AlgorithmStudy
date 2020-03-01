#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
DFS로 모든 경우를 탐색함 N값까지 나오게되면 vector에 현재까지 연산한 값넣기
입력된 K번이 나오는 경우의 수보다 초과할경우는 -1 출력
아니면 정렬을 통해 K-1번째 값을 출력

*/

int arr[3] = { 1,2,3 };
long long cnt = 0;
long long N, K;
vector<string> ans;
void DFS(int n, int m,string s) {
	if (n < m) {
		for (int i = 0; i < 3; i++) {
			n += arr[i];
			string temp = s;
			if (s.length() != 0) {
				temp += "+" + to_string(arr[i]);
			}
			else {
				temp += to_string(arr[i]);
			}
			DFS(n, m,temp);
			n -= arr[i];
		}
	}
	else if (n == m) {
		cnt++;
		ans.push_back(s);
	}
}

int main() {
	cin >> N >> K;
	DFS(0, N, "");
	if (cnt < K)
		cout << "-1\n";
	else {
		sort(ans.begin(), ans.end());
		cout << ans[K - 1] << '\n';
	}

}
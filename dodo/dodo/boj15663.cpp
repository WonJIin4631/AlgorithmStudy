#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
/*
N개의 자연수에서 M개를 고른 수열을 출력한다.
중복되는 수열은 한번만 출력한다.
수열 출력은 사전순으로 한다.

N개의 자연수를 오름차순으로 정렬한다.
N개의 자연수에서 조합으로 M개의 수열을 찾는다.
SET으로 중복된 수열인지 확인한다.
*/
int N, M;
int list[9];
int visit[9] = { 0 };
vector<string> ans;
set<string> Set;
void combi(int cnt,string s) {
	if (cnt == M) {
		s.pop_back();
		if (Set.find(s) == Set.end()) {
			Set.insert(s);
			ans.push_back(s);
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			string temp = s;
			temp += to_string(list[i])+" ";
			combi(cnt + 1,temp);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> list[i];
	sort(list, list + N);
	combi(0,"");
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
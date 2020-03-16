#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
/*
N���� �ڿ������� M���� �� ������ ����Ѵ�.
�ߺ��Ǵ� ������ �ѹ��� ����Ѵ�.
���� ����� ���������� �Ѵ�.

N���� �ڿ����� ������������ �����Ѵ�.
N���� �ڿ������� �������� M���� ������ ã�´�.
SET���� �ߺ��� �������� Ȯ���Ѵ�.
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
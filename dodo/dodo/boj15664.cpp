#include<iostream>
#include<algorithm>
#include<set>
#include<string>
using namespace std;

int N, M;
int num[9] = { 0 };
bool visit[9] = { 0 };
set<string> Set;
void DFS(int cnt) {
	if (cnt == M) {
		string s = "";
		for (int i = 0; i < N; i++) {
			if (visit[i] == true) {
				s += to_string(num[i]);
				s += " ";
			}
		}
		if (Set.find(s) == Set.end()) {
			Set.insert(s);
			cout << s << '\n';
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			DFS(cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	DFS(0);
	return 0;
}
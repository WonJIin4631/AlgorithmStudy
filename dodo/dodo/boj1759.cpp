#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int L, C;
vector<char> v;
bool visit[26] = { 0 };

void DFS(int ja,int mo, vector<char> list,int idx) {
	if (list.size() == L) {
		if (mo >= 1 && ja >= 2) {
			for (int i = 0; i < list.size(); i++) {
				cout << list[i];
			}
			cout << '\n';
		}
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		char c = v[i];
		if (visit[c - 'a'] == false) {
			list.push_back(v[i]);
			visit[c - 'a'] = true;
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				DFS(ja, mo + 1, list, i + 1);
			}
			else {
				DFS(ja+1, mo, list, i + 1);
			}
			visit[c - 'a'] = false;
			list.pop_back();
		}
	}
}
int main() {
	cin >> L >> C;
	v.resize(C);
	for (int i = 0; i < C; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<char> list;
	DFS(0, 0, list, 0);
	return 0;
}
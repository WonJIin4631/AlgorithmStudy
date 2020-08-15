#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <cstring>
#include <vector>
#include<cstdio>
using namespace std;
int dx[] = { 0,0,-1,-1,-1,1,1,1 };
int dy[] = { -1,1,-1,0,1,-1,0,1 };
int score[] = { 0,0,0,1,1,2,3,5,11 };
set<string> res;
bool visited[4][4];
string boggle[4];
int w, b;
struct Trie {
	Trie* next[26];

	bool finish;
	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0')
			finish = true;
		else {
			int cur = *key - 'A';
			if (next[cur] == NULL)
				next[cur] = new Trie();
			next[cur]->insert(key + 1);
		}
	}

	void query(int i, int j, string cur) {
		if (i < 0 || j < 0 || i >= 4 || j >= 4)return;
		if (visited[i][j])return;
		if (cur.size() >= 8)return;

		visited[i][j] = true;
		cur = cur + boggle[i][j];
		if (next[boggle[i][j] - 'A'] == NULL) {
			visited[i][j] = false;
			return;
		}
		if (next[boggle[i][j] - 'A']->finish)
			res.insert(cur);
		for (int c = 0; c < 8; c++) {
			next[boggle[i][j] - 'A']->query(i + dx[c], j + dy[c], cur);
		}
		visited[i][j] = false;
	}
};
int main() {
	scanf("%d", &w);
	Trie *root = new Trie;
	getchar();
	for (int i = 0; i < w; i++) {
		char t[10];
		scanf("%s", &t);
		root->insert(t);
	}
	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < 4; j++)
			cin >> boggle[j];
		res.clear();
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				root->query(j, k, "");
			}
		}
		string ans = *(res.begin());
		int tscore = 0;
		for (auto word : res) {
			if (ans.size() < word.size())
				ans = word;
			tscore += score[word.size()];
		}
		cout << tscore << " " << ans << " " << res.size() << "\n";
	}
	return 0;
}

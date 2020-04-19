#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

int N, K;
string word[51];
bool check[26] = { 0 };
int ans = 0;
void DFS(int cnt,int idx) {
	if (cnt == K) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			bool flag = true;
			for (int j = 0; j < word[i].length(); j++) {
				if (!check[word[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag)
				temp++;
		}
		ans = max(ans, temp);
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (!check[i]) {
			check[i] = !check[i];
			DFS(cnt + 1,i);
			check[i] = !check[i];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	if (K < 5)
		cout << 0 << '\n';
	else if(K==26) {
		cout << N << '\n';
	}
	else {
		for (int i = 0; i < N; i++) {
			cin >> word[i];
			word[i] = word[i].substr(4, word[i].length());
			for (int j = 0; j < 4; j++)
				word[i].pop_back();
		}
		string s = "antatica";
		for (int i = 0; i < s.length(); i++)
			check[s[i] - 'a'] = true;
		DFS(5, 0);
		cout << ans << '\n';
	}
	return 0;
}
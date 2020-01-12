#include <string>
#include <vector>
#include<algorithm>
#include<map>
using namespace std;
char alpha[26];
string cmp;
map<string,int> Map;
int visit[51];
int answer = 987654321;
void DFS(string s, int cnt) {
	if (s==cmp) {
		answer = min(cnt, answer);
		return;
	}
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 26; j++) {
			char temp = s[i];
			s[i] = alpha[j];
			if (Map.find(s) != Map.end()) {
				if (visit[Map.find(s)->second] == 0) {
					visit[Map.find(s)->second] = 1;
					DFS(s, cnt + 1);
					visit[Map.find(s)->second] = 0;
				}
			}
			s[i] = temp;
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	for (int i = 0; i < words.size(); i++) {
		Map.insert(make_pair(words[i],i));
	}
	for (int i = 0; i < 26; i++) {
		alpha[i] = i + 'a';
	}
	DFS(begin, 0);
	if (answer == 987654321)
		answer = 0;
	return answer;
}
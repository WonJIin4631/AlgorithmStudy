#include<iostream>
#include<queue>
using namespace std;


int emoticon[1002];
int S;
void solve() {
	queue<pair<int,pair<int, int>>> q;
	//화면 이모티콘수,명령,2번일때 복사된이모티콘수
	q.push(make_pair(1, make_pair(2, 1)));
	int min_time = 1;
	while (!q.empty()){
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int cpysize = q.front().second.second;
			int cmd = q.front().second.first;
			int emo = q.front().first;
			q.pop();
			if (emo == S) {
				cout << min_time << '\n';
				return;
			}
			if (emo + cpysize <= 1000) {
				if (emoticon[emo + cpysize] > min_time + 1) {
					emoticon[emo + cpysize] = min_time + 1;
					q.push(make_pair(emo + cpysize, make_pair(1, cpysize)));
				}
			}
			if (emo <= 1000) {
				if (cmd != 2 && emo != cpysize) {
					q.push(make_pair(emo, make_pair(2, emo)));
				}
			}
			if (emo<=1000 && emo - 1 > 0) {
				if (emoticon[emo -1] > min_time + 1) {
					emoticon[emo -1] = min_time + 1;
					q.push(make_pair(emo - 1, make_pair(2, cpysize)));
				}
			}
		}
		min_time++;
	}
}
int main() {
	cin >> S;
	for (int i = 2; i <= 1000; i++) {
		emoticon[i] = 987654321;
	}
	emoticon[1] = 0;
	solve();
	return 0;
}
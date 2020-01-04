#include<iostream>
#include<queue>

using namespace std;

int S;
int visit[2000][2000];

void BFS(){
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(1, 0), 0));
	visit[1][0] = 1;
	while (!q.empty())
	{
		int emo = q.front().first.first;
		int clip = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (emo == S) {
			cout << time << '\n';
			return;
		}
		if (emo > 0 && emo < 2000){
			if (visit[emo][emo] == 0){
				visit[emo][emo] = 1;
				q.push(make_pair(make_pair(emo, emo), time + 1));
			}
			if (visit[emo - 1][clip] == 0){
				visit[emo - 1][clip] = 1;
				q.push(make_pair(make_pair(emo - 1, clip), time + 1));
			}
		}
		if (clip > 0 && emo + clip < 2000){
			if (visit[emo + clip][clip] == 0){
				visit[emo + clip][clip] = 1;
				q.push(make_pair(make_pair(emo + clip, clip), time + 1));
			}
		}
	}
}


int main(void)
{
	cin >> S;

	BFS();
	return 0;
}
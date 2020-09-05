#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int numList[8];
bool visit[8];
vector<int> v;


void DFS(int idx, int cnt){
	if (cnt == M){
		for (int i = 0; i < M; i++){
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; i++)
	{
		if (visit[i] == true) continue;
		visit[i] = true;
		v.push_back(numList[i]);
		DFS(i, cnt + 1);
		visit[i] = false;
		v.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++){
		cin >> numList[i];
	}

	sort(numList, numList + N);
	DFS(0, 0);

	return 0;
}
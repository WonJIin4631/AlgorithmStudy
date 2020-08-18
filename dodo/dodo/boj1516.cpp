#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
vector<int> v[502];
queue<int> q;
int check[502] = { 0 }; //내가 지을 수 있는 건물
int time[502];
int ans[502] = { 0 };
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> time[i];
		int n;
		while (true){
			cin >> n;
			if (n == -1)
				break;
			v[n].push_back(i);
			check[i]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == 0) {
			q.push(i);
			ans[i] = time[i];
		}
	}
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (auto val : v[cur]) {
			check[val]--;
			ans[val] = max(ans[val], ans[cur] + time[val]);
			if (check[val] == 0) {
				q.push(val);
			}
		}
	}
	for (int i = 1; i <= N; i++)
		cout << ans[i]<< '\n';
	return 0;
}
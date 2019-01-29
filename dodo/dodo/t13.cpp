#include<iostream>
#include<queue>
using namespace std;
int N;
int arr[101][101];
int vi[101][101] = { 0 };
void show() {
	for (int i = 0; i < N; i++) {
		queue<int> que;
		que.push(i);
		while (!que.empty()) {
			int out = que.front();
			que.pop();
			for (int j = 0; j < N; j++) {
				if (arr[out][j] == 1&&vi[i][j]==0) {
						que.push(j);
						vi[i][j] = 1;
				}
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}
	show();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<<	vi[i][j];
		}
		cout << endl;
	}
}
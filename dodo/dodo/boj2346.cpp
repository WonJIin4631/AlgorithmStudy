#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
deque<pii> list;

int N;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		list.push_back(pii(i, num));
	}
	while (!list.empty()){
		cout << list.front().first << ' ';
		int t = list.front().second;
		list.pop_front();
		if (list.size() < 1) {
			continue;
		}
		if (t < 0) {
			for (int i = 0; i < (t*-1); i++) {
				pii temp = list.back();
				list.push_front(temp);
				list.pop_back();
			}
		}
		else {
			for (int i = 0; i < t-1; i++) {
				pii temp = list.front();
				list.push_back(temp);
				list.pop_front();
			}
		}
	}
	return 0;
}
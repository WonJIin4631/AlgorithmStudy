#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


struct info {
	int stD;
	int endD;
	int cost;
};
struct cmp {
	bool operator()(info a, info b) {
		if (a.stD == b.stD) {
			if (a.endD == b.endD)
				return a.cost > b.cost;
			return a.endD > b.endD;
		}
		return a.stD > b.stD;
	};
};
bool comp(info a, info b) {
	if (a.stD == b.stD) {
		return a.stD > b.stD;
	}
	return a.stD < b.stD;
}
int main() {
	int T;
	vector<info> v;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		int deadLine = 0;
		priority_queue < info, vector<info>, cmp>  pq;
		for (int i = 0; i < N; i++) {
			info data;
			cin >> data.stD >> data.endD >> data.cost;
			pq.push(data);
			deadLine = max(data.endD, deadLine);
		}
		int curDay = 1;
		int leftTime = 8;
		while (!pq.empty()) {
			info data = pq.top();
			pq.pop();
			cout << curDay << ' '<<leftTime<<' ' << data.stD << ' ' << data.endD << ' ' << data.cost << '\n';
			if (curDay <= data.endD&&curDay >= data.stD) {
				if (data.cost >= leftTime) {
					curDay++;
					data.cost -= leftTime;
					data.stD = curDay;
					leftTime = 8;
					if (data.cost>0)
						pq.push(data);
				}
				else {
					leftTime -= data.cost;
					data.cost -= leftTime;
					if (data.cost>0)
						pq.push(data);
				}
			}
		}
		cout << curDay << '\n';
	}
	return 0;
}
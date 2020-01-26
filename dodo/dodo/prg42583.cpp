#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int time = 0;
	int idx = 0;
	int cur_weight=0;
	queue<pair<int,int>> q;
	while (true){
		cout << idx << ' '<<q.size()<<' '<<time<<'\n';
		if (idx == truck_weights.size()) {
			if (q.size()==0)
				break;
		}
		if (q.empty()) {
			q.push(make_pair(idx,time + bridge_length));
			cur_weight += truck_weights[idx++];
		}
		else {
			if (q.front().second == time) {
				cur_weight -= truck_weights[q.front().first];
				q.pop();
			}
			if (cur_weight + truck_weights[idx] <= weight && idx<truck_weights.size()) {
				q.push(make_pair(idx, time + bridge_length));
				cur_weight += truck_weights[idx++];
			}	
		}
		time++;
	}
	answer = time;
	return answer;
}
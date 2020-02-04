#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;
/*
현재 가지고 있는 옷의 수
*/


void solve(int cnt,int idx) {

}
int solution(vector<vector<string>> clothes) {
	int answer = 0;
	vector<int> list(30, 0);
	map<string, int> Map;
	int idx = 0;
	for (int i = 0; i < clothes.size(); i++) {
		if (Map.find(clothes[i][1]) == Map.end()) {
			list[idx]++;
			Map.insert(make_pair(clothes[i][1], idx++));
		}
		else {
			int pos = Map.find(clothes[i][1])->second;
			list[pos]++;
		}
	}
	list.resize(idx);
	cout << list.size();
	return answer;
}
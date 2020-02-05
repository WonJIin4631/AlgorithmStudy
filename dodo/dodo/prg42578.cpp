#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
/*
Map을 이용하여 의상의 종류에 맞는 Idx 번호를 부여
종류별 (의상의 개수+1) 곱한뒤 마지막에 1을 빼면 조합의 수가 나옴
*/
int solution(vector<vector<string>> clothes) {
	int answer = 1;
	vector<vector<string>> list;
	list.resize(30);
	map<string, int> Map;
	int idx = 0;
	for (int i = 0; i < clothes.size(); i++) {
		if (Map.find(clothes[i][1]) == Map.end()) {
			list[idx].push_back(clothes[i][0]);
			Map.insert(make_pair(clothes[i][1], idx++));
		}
		else {
			int pos = Map.find(clothes[i][1])->second;
			list[pos].push_back(clothes[i][0]);
		}
	}
	for (int i = 0; i < idx; i++) {
		answer *= (list[i].size() + 1);
	}
	answer -= 1;
	return answer;
}
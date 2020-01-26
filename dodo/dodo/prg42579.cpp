#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<functional>
using namespace std;

map<string, int> Map;
vector<pair<int, int>> v[101];
vector<int, int> totalSum;
/*
속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
*/
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
bool cmpSong(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	int idx = 0;
	for (int i = 0; i < genres.size(); i++) {
		if (Map.find(genres[i]) == Map.end()) {
			Map.insert(make_pair(genres[i], idx));
			totalSum.push_back(make_pair(idx, 1));
			v[idx++].push_back(make_pair(i, plays[i]));
		}
		else {
			int temp = Map.find(genres[i])->second;
			v[temp].push_back(make_pair(i, plays[i]));
			totalSum[temp].second += 1;
		}
	}
	sort(totalSum.begin(), totalSum.end() ,greater<pair<int,int>>());
	for (int i = 0; i < idx; i++) {
		sort(v[i].begin(), v[i].end(), cmpSong);
		answer.push_back(v[i][0].first);
		if (v[i].size() > 1)
			answer.push_back(v[i][1].first);
	}
	return answer;
}
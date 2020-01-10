#include <string>
#include <vector>
#include<stack>
#include<iostream>
using namespace std;


vector<int> solution(vector<int> heights) {
	vector<int> answer;
	answer.resize(heights.size());
	vector<pair<int, int>> list;
	stack<pair<int,int>> st;
	for (int i = 0; i < heights.size(); i++) {
		list.push_back(make_pair(heights[i],i+1));
	}
	st.push(list[list.size() - 1]);
	for (int i = list.size(); i >= 0; i++) {
		int h = list[i].first;
		int idx = list[i].second;
		while (!st.empty()){
			if (st.top().first >= h )
				break;
			answer[st.top().second] = idx;
			st.pop();
		}
		st.push(list[i]);
	}
	return answer;
}
#include <string>
#include <vector>
#include<stack>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer(heights.size(), 0);
	stack<pair<int, int>> st;
	st.push(make_pair(heights.back(), heights.size()));
	for (int i = heights.size() - 2; i >= 0; i--) {
		while (true) {
			if (st.empty())
				break;
			if (st.top().first >= heights[i])
				break;
			int pos = st.top().second;
			answer[pos - 1] = i + 1;
			st.pop();
			cout << pos << ' ' << i << '\n';
		}
		st.push(make_pair(heights[i], i+1));
	}
	return answer;
}
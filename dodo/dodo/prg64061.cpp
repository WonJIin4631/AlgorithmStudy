#include <string>
#include <vector>
#include<iostream>	
#include<stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	stack<int> st[31];
	stack<int> bucket;
	int N;

	N = board.size();

	for (int i = 0; i <N; i++) {
		for (int j = N - 1; j >= 0; j--) {
			if (board[j][i] != 0) {
				st[i + 1].push(board[j][i]);
			}
		}
	}
	for (int i = 0; i < moves.size(); i++) {
		int pos = moves[i];
		if (st[pos].size() == 0) {
			continue;
		}
		else {
			int cur = st[pos].top();
			st[pos].pop();
			if (bucket.size() == 0) {
				bucket.push(cur);
			}
			else {
				if (bucket.top() == cur) {
					answer++;
					while (bucket.top() == cur) {
						bucket.pop();
						answer++;
						if (bucket.size() == 0)
							break;
					}
				}
				else {
					bucket.push(cur);
				}
			}
		}
	}
	return answer;
}